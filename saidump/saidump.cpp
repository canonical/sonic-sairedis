#include <inttypes.h>
#include <string>
#include <set>
#include <sstream>
#include <iostream>
#include <fstream>
#include <regex>
#include <climits>

extern "C" {
#include <sai.h>
}

#include "swss/table.h"
#include "meta/sai_serialize.h"
#include "sairediscommon.h"
#include "swss/json.hpp"

#include <getopt.h>

// TODO split to multiple cpp

using namespace swss;
using json = nlohmann::json;

// Default value: 100 MB
constexpr int64_t RDB_JSON_MAX_SIZE = 1024 * 1024 * 100;

struct CmdOptions
{
    bool skipAttributes;
    bool dumpTempView;
    bool dumpGraph;
    std::string rdbJsonFile;
    uint64_t rdbJSonSizeLimit;
};


static CmdOptions g_cmdOptions;
static std::map<sai_object_id_t, const TableMap*> g_oid_map;

void printUsage()
{
    SWSS_LOG_ENTER();

    std::cout << "Usage: saidump [-t] [-g] [-r] [-m] [-h]" << std::endl;
    std::cout << "    -t --tempView:" << std::endl;
    std::cout << "        Dump temp view" << std::endl;
    std::cout << "    -g --dumpGraph:" << std::endl;
    std::cout << "        Dump current graph" << std::endl;
    std::cout << "    -r --rdb:" << std::endl;
    std::cout << "        Dump by parsing the RDB JSON file, which is created by rdbtools based on Redis dump.rdb that is generated by Redis SAVE command" << std::endl;
    std::cout << "    -m --max:" << std::endl;
    std::cout << "        Config the the RDB JSON file's max size in MB, which is optional with default value 100MB" << std::endl;
    std::cout << "    -h --help:" << std::endl;
    std::cout << "        Print out this message" << std::endl;
}

CmdOptions handleCmdLine(int argc, char **argv)
{
    SWSS_LOG_ENTER();

    CmdOptions options;

    options.dumpTempView = false;
    options.dumpGraph = false;
    options.rdbJSonSizeLimit = RDB_JSON_MAX_SIZE;

    const char* const optstring = "gtr:m:h";
    uint64_t result = 0;

    while (true)
    {
        static struct option long_options[] =
        {
            { "dumpGraph",      no_argument,       0, 'g' },
            { "tempView",       no_argument,       0, 't' },
            { "rdb",            required_argument, 0, 'r' },
            { "max",            required_argument, 0, 'm' },
            { "help",           no_argument,       0, 'h' },
            { 0,                0,                 0,  0  }
        };

        int option_index = 0;

        int c = getopt_long(argc, argv, optstring, long_options, &option_index);

        if (c == -1)
        {
            break;
        }

        switch (c)
        {
            case 'g':
                SWSS_LOG_NOTICE("Dumping graph");
                options.dumpGraph = true;
                break;

            case 't':
                SWSS_LOG_NOTICE("Dumping temp view");
                options.dumpTempView = true;
                break;

            case 'r':
                SWSS_LOG_NOTICE("Dumping from %s", optarg);
                options.rdbJsonFile = std::string(optarg);
                break;

            case 'm':
                if(!regex_match(optarg, std::regex(R"([+]?\d+)")))              //only positive numeric chars are valid, such as 3984, +3232, etc.
                {
                    SWSS_LOG_WARN("invalid option -m %s", optarg);
                    printUsage();
                    exit(EXIT_SUCCESS);
                }

                result = strtoull(optarg, NULL, 0);

                if((errno == ERANGE && result == ULLONG_MAX) || result == 0 || result >= INT_MAX)
                {
                    SWSS_LOG_WARN("invalid option -m %s", optarg);
                    printUsage();
                    exit(EXIT_SUCCESS);
                }

                options.rdbJSonSizeLimit = result * 1024 * 1024;
                SWSS_LOG_NOTICE("Configure the RDB JSON MAX size to %llu MB", options.rdbJSonSizeLimit / 1024 / 1024);

                break;

            case 'h':
                printUsage();
                exit(EXIT_SUCCESS);

            case '?':
                SWSS_LOG_WARN("unknown option %c", optopt);
                printUsage();
                exit(EXIT_FAILURE);

            default:
                SWSS_LOG_ERROR("getopt_long failure");
                exit(EXIT_FAILURE);
        }
    }

    return options;
}

size_t get_max_attr_len(const TableMap& map)
{
    SWSS_LOG_ENTER();

    size_t max = 0;

    for (const auto&field: map)
    {
        max = std::max(max, field.first.length());
    }

    return max;
}

std::string pad_string(std::string s, size_t pad)
{
    SWSS_LOG_ENTER();

    size_t len = s.length();

    if (len < pad)
    {
        s.insert(len, pad - len, ' ');
    }

    return s;
}

const TableMap* get_table_map(sai_object_id_t object_id)
{
    SWSS_LOG_ENTER();

    auto it = g_oid_map.find(object_id);

    if (it == g_oid_map.end())
    {
        SWSS_LOG_THROW("unable to find oid %s in oid map",
                sai_serialize_object_id(object_id).c_str());
    }

    return it->second;
}

void print_attributes(size_t indent, const TableMap& map)
{
    SWSS_LOG_ENTER();

    size_t max_len = get_max_attr_len(map);

    std::string str_indent = pad_string("", indent);

    for (const auto&field: map)
    {
        const sai_attr_metadata_t *meta;
        sai_deserialize_attr_id(field.first, &meta);

        std::stringstream ss;

        ss << str_indent << pad_string(field.first, max_len) << " : ";

        ss << field.second;

        std::cout << ss.str() << std::endl;
    }
}

// colors are in HSV
#define GV_ARROW_COLOR  "0.650 0.700 0.700"
#define GV_ROOT_COLOR   "0.650 0.200 1.000"
#define GV_NODE_COLOR   "0.650 0.500 1.000"

void dumpGraph(const TableDump& td)
{
    SWSS_LOG_ENTER();

    std::map<sai_object_id_t, const sai_object_type_info_t*> oidtypemap;
    std::map<sai_object_type_t,const sai_object_type_info_t*> typemap;

    std::cout << "digraph \"SAI Object Dependency Graph\" {" << std::endl;
    std::cout << "size = \"30,12\"; ratio = fill;" << std::endl;
    std::cout << "node [ style = filled ];" << std::endl;

    // build object type map first

    std::set<sai_object_type_t> definedtypes;

    std::map<sai_object_type_t, int> usagemap;

    for (const auto& key: td)
    {
        sai_object_meta_key_t meta_key;
        sai_deserialize_object_meta_key(key.first, meta_key);

        auto info = sai_metadata_get_object_type_info(meta_key.objecttype);

        typemap[info->objecttype] = info;

        if (!info->isnonobjectid)
            oidtypemap[meta_key.objectkey.key.object_id] = info;

        if (definedtypes.find(meta_key.objecttype) != definedtypes.end())
            continue;

        definedtypes.insert(meta_key.objecttype);
    }

    std::set<std::string> definedlinks;

    std::set<sai_object_type_t> ref;
    std::set<sai_object_type_t> attrref;

#define SAI_OBJECT_TYPE_PREFIX_LEN (sizeof("SAI_OBJECT_TYPE_") - 1)

    for (const auto& key: td)
    {
        sai_object_meta_key_t meta_key;
        sai_deserialize_object_meta_key(key.first, meta_key);

        auto info = sai_metadata_get_object_type_info(meta_key.objecttype);

        // process non object id objects if any
        for (size_t j = 0; j < info->structmemberscount; ++j)
        {
            const sai_struct_member_info_t *m = info->structmembers[j];

            if (m->membervaluetype == SAI_ATTR_VALUE_TYPE_OBJECT_ID)
            {
                sai_object_id_t member_oid = m->getoid(&meta_key);

                auto member_info = oidtypemap.at(member_oid);

                if (member_info->objecttype == SAI_OBJECT_TYPE_SWITCH)
                {
                    // skip link of SWITCH to non object id object types, since
                    // all of them contain switch_id
                    continue;
                }

                std::stringstream ss;

                ss << std::string(member_info->objecttypename + SAI_OBJECT_TYPE_PREFIX_LEN) << " -> "
                << std::string(info->objecttypename + SAI_OBJECT_TYPE_PREFIX_LEN)
                << "[ color=\"" << GV_ARROW_COLOR << "\", style = dashed, penwidth = 2 ]";

                std::string link = ss.str();

                if (definedlinks.find(link) != definedlinks.end())
                    continue;

                definedlinks.insert(link);

                std::cout << link << std::endl;
            }
        }

        // process attributes for this object

        for (const auto&field: key.second)
        {
            const sai_attr_metadata_t *meta;
            sai_deserialize_attr_id(field.first, &meta);

            if (!meta->isoidattribute || meta->isreadonly)
            {
                // skip non oid attributes and read only attributes
                continue;
            }

            sai_attribute_t attr;

            sai_deserialize_attr_value(field.second, *meta, attr, false);

            sai_object_list_t list = { 0, NULL };

            switch (meta->attrvaluetype)
            {
                case SAI_ATTR_VALUE_TYPE_OBJECT_ID:
                    list.count = 1;
                    list.list = &attr.value.oid;
                    break;

                case SAI_ATTR_VALUE_TYPE_ACL_FIELD_DATA_OBJECT_ID:
                    if (attr.value.aclfield.enable)
                    {
                        list.count = 1;
                        list.list = &attr.value.aclfield.data.oid;
                    }
                    break;

                case SAI_ATTR_VALUE_TYPE_ACL_ACTION_DATA_OBJECT_ID:
                    if (attr.value.aclaction.enable)
                    {
                        list.count = 1;
                        list.list = &attr.value.aclaction.parameter.oid;
                    }
                    break;

                case SAI_ATTR_VALUE_TYPE_OBJECT_LIST:
                    list = attr.value.objlist;
                    break;

                case SAI_ATTR_VALUE_TYPE_ACL_FIELD_DATA_OBJECT_LIST:
                    if (attr.value.aclfield.enable)
                        list = attr.value.aclfield.data.objlist;
                    break;

                case SAI_ATTR_VALUE_TYPE_ACL_ACTION_DATA_OBJECT_LIST:
                    if (attr.value.aclaction.enable)
                        list = attr.value.aclaction.parameter.objlist;
                    break;

                default:
                    SWSS_LOG_THROW("attr value type: %d is not supported, FIXME", meta->attrvaluetype);
            }

            for (uint32_t i = 0; i < list.count; ++i)
            {
                sai_object_id_t oid = list.list[i];

                if (oid == SAI_NULL_OBJECT_ID)
                    continue;

                // this object type is not root, can be in the middle or leaf
                ref.insert(info->objecttype);

                auto attr_oid_info = oidtypemap.at(oid);

                std::stringstream ss;

                attrref.insert(attr_oid_info->objecttype);

                ss << std::string(attr_oid_info->objecttypename + SAI_OBJECT_TYPE_PREFIX_LEN) << " -> "
                << std::string(info->objecttypename + SAI_OBJECT_TYPE_PREFIX_LEN)
                << "[ color = \"" << GV_ARROW_COLOR << "\" ]";

                std::string link = ss.str();

                if (definedlinks.find(link) != definedlinks.end())
                    continue;

                definedlinks.insert(link);

                std::cout << link << std::endl;
            }

            sai_deserialize_free_attribute_value(meta->attrvaluetype, attr);
        }
    }

    for (auto t: typemap)
    {
        auto ot = t.first;
        auto info = t.second;

        auto name = std::string(info->objecttypename + SAI_OBJECT_TYPE_PREFIX_LEN);

        if (info->isnonobjectid)
        {
            /* non object id leafs */

            std::cout << name << " [ color = plum, shape = rect ];\n";
            continue;
        }

        if (ref.find(ot) != ref.end() && attrref.find(ot) != attrref.end())
        {
            /* middle nodes */

            std::cout << name << " [ color =\"" << GV_NODE_COLOR << "\" ];\n";
            continue;
        }

        if (ref.find(ot) != ref.end() && attrref.find(ot) == attrref.end())
        {
            /* leafs */

            std::cout << name << " [ color = palegreen, shape = rect ];\n";
            continue;
        }

        if (ref.find(ot) == ref.end() && attrref.find(ot) != attrref.end())
        {
            /* roots */

            std::cout << name << " [ color = \"" << GV_ROOT_COLOR << "\" ];\n";
            continue;
        }

        /* objects which are there but not referenced nowhere for example STP */

        std::cout << name << " [ color = \"" << GV_ROOT_COLOR << "\", shape = rect ];\n";
    }

    std::cout << "SWITCH -> PORT [ dir = none, color = red, peripheries = 2, penwidth = 2, style = dashed ];" << std::endl;
    std::cout << "SWITCH [ color = orange, fillcolor = orange, shape = parallelogram, peripheries = 2 ];" << std::endl;
    std::cout << "PORT [ color = gold, shape = diamond, peripheries = 2 ];" << std::endl;
    std::cout << "}" << std::endl;
}

#define SWSS_LOG_ERROR_AND_STDERR(format, ...) { fprintf(stderr, format"\n", ##__VA_ARGS__); SWSS_LOG_ERROR(format, ##__VA_ARGS__); }

/**
 * @brief Process the input JSON file to make sure it's a valid JSON file for the JSON library.
 */
static sai_status_t preProcessFile(const std::string file_name)
{
    SWSS_LOG_ENTER();

    std::ifstream input_file(file_name);

    if (!input_file.is_open())
    {
        SWSS_LOG_ERROR_AND_STDERR("Failed to open the input file %s.", file_name.c_str());
        return SAI_STATUS_FAILURE;
    }

    input_file.seekg(0, std::ios::end);     // Move to the end of the file
    uint64_t file_size = input_file.tellg(); // Get the current position
    SWSS_LOG_NOTICE("Get %s's size %" PRIu64 " Bytes, limit: %" PRIu64 " MB.", file_name.c_str(), file_size, g_cmdOptions.rdbJSonSizeLimit / 1024 / 1024);

    if (file_size >= g_cmdOptions.rdbJSonSizeLimit)
    {
        SWSS_LOG_ERROR_AND_STDERR("Get %s's size failure or its size %" PRIu64 " >= %" PRIu64 " MB.", file_name.c_str(), file_size, g_cmdOptions.rdbJSonSizeLimit / 1024 / 1024);
        return SAI_STATUS_FAILURE;
    }

    input_file.seekg(0);     // Move to the begin of the file

    // Read the content of the input file into a string
    std::string content((std::istreambuf_iterator<char>(input_file)),
                   std::istreambuf_iterator<char>());

    content = regex_replace(content, std::regex("\\},\\{\\r"), ",");

    std::ofstream outputFile(file_name);

    if (!outputFile.is_open())
    {
        SWSS_LOG_ERROR_AND_STDERR("Failed to open the output file %s.", file_name.c_str());
        return SAI_STATUS_FAILURE;
    }

    //Remove the 1st and last char to make sure its format is same as previous output
    if (content.size() >= 2 && content[0] == '[' && content[content.length()-1] == ']')
    {
        outputFile << content.substr(1, content.size()-2);
    }
    else
    {
        outputFile << content;
    }

    return SAI_STATUS_SUCCESS;
}

static sai_status_t dumpFromRedisRdbJson(const std::string file_name)
{
    SWSS_LOG_ENTER();

    std::ifstream input_file(file_name);

    if (!input_file.is_open())
    {
        SWSS_LOG_ERROR_AND_STDERR("The file %s does not exist for dumping from Redis RDB JSON file.", file_name.c_str());
        return SAI_STATUS_FAILURE;
    }

    try
    {
        // Parse the JSON data from the file (validation)
        nlohmann::json jsonData;
        input_file >> jsonData;

        SWSS_LOG_DEBUG("JSON file is valid.");

        for (json::iterator it = jsonData.begin(); it != jsonData.end(); ++it)
        {
            json jj_key = it.key();

            std::string keystr = jj_key;
            std::string item_name = keystr;
            size_t pos = keystr.find_first_of(":");

            if (pos != std::string::npos)
            {
                if(ASIC_STATE_TABLE != keystr.substr(0, pos))  // filter out non ASIC_STATE
                {
                    continue;
                }

                item_name = keystr.substr(pos + 1);

                if (item_name.find(":") != std::string::npos)
                {
                    item_name.replace(item_name.find_first_of(":"), 1, " ");
                }
            }
            else
            {
                continue;
            }

            std::cout << item_name << " " << std::endl;

            json jj = it.value();

            if (!it->is_object())
            {
                continue;
            }

            TableMap map;

            for (json::iterator itt = jj.begin(); itt != jj.end(); ++itt)
            {
                if (itt.key() != "NULL")
                {
                    map[itt.key()] = itt.value();
                }
            }

            constexpr size_t LINE_IDENT = 4;
            size_t max_len = get_max_attr_len(map);
            std::string str_indent = pad_string("", LINE_IDENT);

            for (const auto&field: map)
            {
                std::cout << str_indent << pad_string(field.first, max_len) << " : ";
                std::cout << field.second << std::endl;
            }

            std::cout << std::endl;
        }

        return SAI_STATUS_SUCCESS;
    }
    catch (std::exception &ex)
    {
        SWSS_LOG_ERROR_AND_STDERR("JSON file %s is invalid.", file_name.c_str());
        SWSS_LOG_ERROR_AND_STDERR("JSON parsing error: %s.", ex.what());
    }

    return SAI_STATUS_FAILURE;
}

int main(int argc, char **argv)
{
    swss::Logger::getInstance().setMinPrio(swss::Logger::SWSS_DEBUG);

    SWSS_LOG_ENTER();

    swss::Logger::getInstance().setMinPrio(swss::Logger::SWSS_NOTICE);

    swss::Logger::getInstance().setMinPrio(swss::Logger::SWSS_INFO);

    g_cmdOptions = handleCmdLine(argc, argv);


    if (g_cmdOptions.rdbJsonFile.size() > 0)
    {
        if (SAI_STATUS_FAILURE == preProcessFile(g_cmdOptions.rdbJsonFile))
        {
            return EXIT_FAILURE;
        }

        return dumpFromRedisRdbJson(g_cmdOptions.rdbJsonFile);
    }

    swss::DBConnector db("ASIC_DB", 0);

    std::string table = ASIC_STATE_TABLE;

    if (g_cmdOptions.dumpTempView)
    {
        table = TEMP_PREFIX + table;
    }

    swss::Table t(&db, table);

    TableDump dump;

    t.dump(dump);

    for (const auto&key: dump)
    {
        auto start = key.first.find_first_of(":");
        auto str_object_type = key.first.substr(0, start);
        auto str_object_id  = key.first.substr(start + 1);

        sai_object_type_t object_type;
        sai_deserialize_object_type(str_object_type, object_type);

        auto info = sai_metadata_get_object_type_info(object_type);

        if (!info->isnonobjectid)
        {
            sai_object_id_t object_id;
            sai_deserialize_object_id(str_object_id, object_id);

            g_oid_map[object_id] = &key.second;
        }
    }

    if (g_cmdOptions.dumpGraph)
    {
        dumpGraph(dump);

        return EXIT_SUCCESS;
    }

    for (const auto&key: dump)
    {
        auto start = key.first.find_first_of(":");
        auto str_object_type = key.first.substr(0, start);
        auto str_object_id  = key.first.substr(start + 1);

        std::cout << str_object_type << " " << str_object_id << " " << std::endl;

        size_t indent = 4;

        print_attributes(indent, key.second);

        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
