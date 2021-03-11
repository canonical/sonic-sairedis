#include "Python.h"

extern "C" {
#include "sai.h"
#include "saimetadata.h"
}

#include "../lib/inc/Sai.h"
#include "../meta/sai_serialize.h"

#include "swss/logger.h"
#include "swss/tokenize.h"

#include <map>
#include <string>
#include <memory>
#include <vector>

#define MAX_LIST_SIZE (0x1000)
#define LIST_ITEM_MAX_SIZE (sizeof(sai_attribute_t))

static std::map<std::string, std::string> g_profileMap;

static const char *profile_get_value (
        _In_ sai_switch_profile_id_t profile_id,
        _In_ const char *variable)
{
    SWSS_LOG_ENTER();

    auto it = g_profileMap.find(variable);

    if (it == g_profileMap.end())
        return NULL;
    return it->second.c_str();
}

static int profile_get_next_value (
        _In_ sai_switch_profile_id_t profile_id,
        _Out_ const char **variable,
        _Out_ const char **value)
{
    SWSS_LOG_ENTER();

    static auto it = g_profileMap.begin();

    if (value == NULL)
    {
        // Restarts enumeration
        it = g_profileMap.begin();
    }
    else if (it == g_profileMap.end())
    {
        return -1;
    }
    else
    {
        *variable = it->first.c_str();
        *value = it->second.c_str();
        it++;
    }

    if (it != g_profileMap.end())
        return 0;

    return -1;
}

static const sai_service_method_table_t service_method_table = {
    profile_get_value,
    profile_get_next_value
};

static std::shared_ptr<sairedis::Sai> g_sai;

static PyObject* SaiRedisError;

static PyObject * generic_create(
        _In_ sai_object_type_t objectType,
        _In_ PyObject *self,
        _In_ PyObject *args)
{
    SWSS_LOG_ENTER();

    sai_object_id_t switchId = SAI_NULL_OBJECT_ID;

    auto* info = sai_metadata_get_object_type_info(objectType);

    if (!info)
    {
        PyErr_Format(SaiRedisError, "Invalid object type specified");
        return nullptr;
    }

    if (info->isnonobjectid)
    {
        PyErr_Format(SaiRedisError, "Non object id specified to oid function");
        return nullptr;
    }

    if (!PyTuple_Check(args))
    {
        PyErr_Format(SaiRedisError, "Python error, expected args type is tuple");
        return nullptr;
    }

    int size = (int)PyTuple_Size(args);

    PyObject* dict = nullptr;

    if (objectType == SAI_OBJECT_TYPE_SWITCH)
    {
        if (size != 1)
        {
            PyErr_Format(SaiRedisError, "Expected number of arguments is 1, but %d given", size);
            return nullptr;
        }

        dict = PyTuple_GetItem(args, 0);
    }
    else
    {
        if (size != 2)
        {
            PyErr_Format(SaiRedisError, "Expected number of arguments is 2, but %d given", size);
            return nullptr;
        }

        auto*swid = PyTuple_GetItem(args, 0);

        if (!PyString_Check(swid))
        {
            PyErr_Format(SaiRedisError, "Switch id must be string type");
            return nullptr;
        }

        try
        {
            sai_deserialize_object_id(PyString_AsString(swid), &switchId);
        }
        catch (const std::exception&e)
        {
            PyErr_Format(SaiRedisError, "Failed to deserialize switchId: %s", e.what());
            return nullptr;
        }

        dict = PyTuple_GetItem(args, 1);
    }

    if (!PyDict_CheckExact(dict))
    {
        PyErr_Format(SaiRedisError, "Passed argument must be of type dict");
        return nullptr;
    }

    std::map<std::string, std::string> map;

    PyObject *key, *value;
    Py_ssize_t pos = 0;

    while (PyDict_Next(dict, &pos, &key, &value))
    {
        if (!PyString_Check(key) || !PyString_Check(value))
        {
            PyErr_Format(SaiRedisError, "Keys and values in dict must be strings");
            return nullptr;
        }

        // save pair to map
        map[PyString_AsString(key)] = PyString_AsString(value);
    }

    std::vector<sai_attribute_t> attrs;
    std::vector<const sai_attr_metadata_t*> meta;

    for (auto& kvp: map)
    {
        auto*md = sai_metadata_get_attr_metadata_by_attr_id_name(kvp.first.c_str());

        if (!md)
        {
            PyErr_Format(SaiRedisError, "Invalid attribute: %s", kvp.first.c_str());
            return nullptr;
        }

        if (md->objecttype != objectType)
        {
            PyErr_Format(SaiRedisError, "Attribute: %s is not %s", kvp.first.c_str(), info->objecttypename);
            return nullptr;
        }

        sai_attribute_t attr;

        try
        {
            attr.id = md->attrid;

            sai_deserialize_attr_value(kvp.second, *md, attr, false);
        }
        catch (const std::exception&e)
        {
            PyErr_Format(SaiRedisError, "Failed to deserialize %s '%s': %s", kvp.first.c_str(), kvp.second.c_str(), e.what());
            return nullptr;
        }

        attrs.push_back(attr);
        meta.push_back(md);

    }

    sai_object_id_t objectId;
    sai_status_t status = g_sai->create(
            objectType,
            &objectId,
            switchId,
            (uint32_t)attrs.size(),
            attrs.data());

    for (size_t i = 0; i < attrs.size(); i++)
    {
        // free potentially allocated memory
        sai_deserialize_free_attribute_value(meta[i]->attrvaluetype, attrs[i]);
    }

    PyObject *pdict = PyDict_New();
    PyDict_SetItemString(pdict, "status", PyString_FromFormat("%s", sai_serialize_status(status).c_str()));

    if (status == SAI_STATUS_SUCCESS)
    {
        PyDict_SetItemString(pdict, "oid", PyString_FromFormat("%s", sai_serialize_object_id(objectId).c_str()));
    }

    return pdict;
}

static PyObject * generic_remove(
        _In_ sai_object_type_t objectType,
        _In_ PyObject *self,
        _In_ PyObject *args)
{
    SWSS_LOG_ENTER();

    auto* info = sai_metadata_get_object_type_info(objectType);

    if (!info)
    {
        PyErr_Format(SaiRedisError, "Invalid object type specified");
        return nullptr;
    }

    if (info->isnonobjectid)
    {
        PyErr_Format(SaiRedisError, "Non object id specified to oid function");
        return nullptr;
    }

    if (!PyTuple_Check(args))
    {
        PyErr_Format(SaiRedisError, "Python error, expected args type is tuple");
        return nullptr;
    }

    int size = (int)PyTuple_Size(args);

    if (size != 1)
    {
        PyErr_Format(SaiRedisError, "Expected number of arguments is 1, but %d given", size);
        return nullptr;
    }

    auto*oid = PyTuple_GetItem(args, 0);

    if (!PyString_Check(oid))
    {
        PyErr_Format(SaiRedisError, "Passed argument must be of type string");
        return nullptr;
    }

    sai_object_id_t objectId;

    try
    {
        sai_deserialize_object_id(PyString_AsString(oid), &objectId);
    }
    catch (const std::exception&e)
    {
        PyErr_Format(SaiRedisError, "Failed to deserialize switchId: %s", e.what());
        return nullptr;
    }

    sai_status_t status = g_sai->remove(
            objectType,
            objectId);

    PyObject *pdict = PyDict_New();
    PyDict_SetItemString(pdict, "status", PyString_FromFormat("%s", sai_serialize_status(status).c_str()));

    return pdict;
}

static PyObject * generic_set(
        _In_ sai_object_type_t objectType,
        _In_ PyObject *self,
        _In_ PyObject *args)
{
    SWSS_LOG_ENTER();

    auto* info = sai_metadata_get_object_type_info(objectType);

    if (!info)
    {
        PyErr_Format(SaiRedisError, "Invalid object type specified");
        return nullptr;
    }

    if (info->isnonobjectid)
    {
        PyErr_Format(SaiRedisError, "Non object id specified to oid function");
        return nullptr;
    }

    if (!PyTuple_Check(args))
    {
        PyErr_Format(SaiRedisError, "Python error, expected args type is tuple");
        return nullptr;
    }

    int size = (int)PyTuple_Size(args);

    if (size != 3)
    {
        PyErr_Format(SaiRedisError, "Expected number of arguments is 3, but %d given", size);
        return nullptr;
    }

    auto* pyoid = PyTuple_GetItem(args, 0);
    auto* pyattr = PyTuple_GetItem(args, 1);
    auto* pyval = PyTuple_GetItem(args, 2);

    if (!PyString_Check(pyoid) || !PyString_Check(pyattr) || !PyString_Check(pyval))
    {
        PyErr_Format(SaiRedisError, "All parameters must be of type string");
        return nullptr;
    }

    sai_object_id_t objectId;

    try
    {
        sai_deserialize_object_id(PyString_AsString(pyoid), &objectId);
    }
    catch (const std::exception&e)
    {
        PyErr_Format(SaiRedisError, "Failed to deserialize switchId: %s", e.what());
        return nullptr;
    }

    std::string strAttr = PyString_AsString(pyattr);
    std::string strVal = PyString_AsString(pyval);

    if (objectType == SAI_OBJECT_TYPE_SWITCH)
    {
        if (strAttr == "SAI_REDIS_SWITCH_ATTR_SYNC_OPERATION_RESPONSE_TIMEOUT")
        {
            sai_attribute_t attr;

            attr.id = SAI_REDIS_SWITCH_ATTR_SYNC_OPERATION_RESPONSE_TIMEOUT;

            uint32_t value;

            try
            {
                sai_deserialize_number(strVal, value);
            }
            catch (const std::exception&e)
            {
                PyErr_Format(SaiRedisError, "Failed to deserialize %s '%s': %s", strAttr.c_str(), strVal.c_str(), e.what());
                return nullptr;
            }

            attr.value.u64 = value;

            sai_status_t status = g_sai->set(objectType, objectId, &attr);

            PyObject *pdict = PyDict_New();
            PyDict_SetItemString(pdict, "status", PyString_FromFormat("%s", sai_serialize_status(status).c_str()));

            return pdict;
        }
        else if (strAttr == "SAI_REDIS_SWITCH_ATTR_NOTIFY_SYNCD")
        {
            sai_attribute_t attr;

            attr.id = SAI_REDIS_SWITCH_ATTR_NOTIFY_SYNCD;

            sai_redis_notify_syncd_t value;

            try
            {
                sai_deserialize(strVal, value);
            }
            catch (const std::exception&e)
            {
                PyErr_Format(SaiRedisError, "Failed to deserialize %s '%s': %s", strAttr.c_str(), strVal.c_str(), e.what());
                return nullptr;
            }

            attr.value.s32 = value;

            sai_status_t status = g_sai->set(objectType, objectId, &attr);

            PyObject *pdict = PyDict_New();
            PyDict_SetItemString(pdict, "status", PyString_FromFormat("%s", sai_serialize_status(status).c_str()));

            return pdict;
        }
        else if (strAttr == "SAI_REDIS_SWITCH_ATTR_REDIS_COMMUNICATION_MODE")
        {
            sai_attribute_t attr;

            attr.id = SAI_REDIS_SWITCH_ATTR_REDIS_COMMUNICATION_MODE;

            sai_redis_communication_mode_t value;

            try
            {
                sai_deserialize_redis_communication_mode(strVal, value);
            }
            catch (const std::exception&e)
            {
                PyErr_Format(SaiRedisError, "Failed to deserialize %s '%s': %s", strAttr.c_str(), strVal.c_str(), e.what());
                return nullptr;
            }

            attr.value.s32 = value;

            sai_status_t status = g_sai->set(objectType, objectId, &attr);

            PyObject *pdict = PyDict_New();
            PyDict_SetItemString(pdict, "status", PyString_FromFormat("%s", sai_serialize_status(status).c_str()));

            return pdict;
        }
    }

    auto*md = sai_metadata_get_attr_metadata_by_attr_id_name(strAttr.c_str());

    if (!md)
    {
        PyErr_Format(SaiRedisError, "Invalid attribute: %s", strAttr.c_str());
        return nullptr;
    }

    if (md->objecttype != objectType)
    {
        PyErr_Format(SaiRedisError, "Attribute: %s is not %s", strAttr.c_str(), info->objecttypename);
        return nullptr;
    }

    sai_attribute_t attr;

    try
    {
        attr.id = md->attrid;

        sai_deserialize_attr_value(strVal, *md, attr, false);
    }
    catch (const std::exception&e)
    {
        PyErr_Format(SaiRedisError, "Failed to deserialize %s '%s': %s", strAttr.c_str(), strVal.c_str(), e.what());
        return nullptr;
    }

    sai_status_t status = g_sai->set(objectType, objectId, &attr);

    // free potentially allocated memory
    sai_deserialize_free_attribute_value(md->attrvaluetype, attr);

    PyObject *pdict = PyDict_New();
    PyDict_SetItemString(pdict, "status", PyString_FromFormat("%s", sai_serialize_status(status).c_str()));

    return pdict;
}

static PyObject * generic_get(
        _In_ sai_object_type_t objectType,
        _In_ PyObject *self,
        _In_ PyObject *args)
{
    SWSS_LOG_ENTER();

    auto* info = sai_metadata_get_object_type_info(objectType);

    if (!info)
    {
        PyErr_Format(SaiRedisError, "Invalid object type specified");
        return nullptr;
    }

    if (info->isnonobjectid)
    {
        PyErr_Format(SaiRedisError, "Non object id specified to oid function");
        return nullptr;
    }

    if (!PyTuple_Check(args))
    {
        PyErr_Format(SaiRedisError, "Python error, expected args type is tuple");
        return nullptr;
    }

    int size = (int)PyTuple_Size(args);

    if (size != 2)
    {
        PyErr_Format(SaiRedisError, "Expected number of arguments is 2, but %d given", size);
        return nullptr;
    }

    auto*pyoid = PyTuple_GetItem(args, 0);
    auto*pyattr = PyTuple_GetItem(args, 1);

    if (!PyString_Check(pyoid) || !PyString_Check(pyattr))
    {
        PyErr_Format(SaiRedisError, "All atttributes must be of type string");
        return nullptr;
    }

    sai_object_id_t objectId;
    try
    {
        sai_deserialize_object_id(PyString_AsString(pyoid), &objectId);
    }
    catch (const std::exception&e)
    {
        PyErr_Format(SaiRedisError, "Failed to deserialize objectId: %s", e.what());
        return nullptr;
    }

    std::string strAttr = PyString_AsString(pyattr);

    auto*md = sai_metadata_get_attr_metadata_by_attr_id_name(strAttr.c_str());

    if (!md)
    {
        PyErr_Format(SaiRedisError, "Invalid attribute: %s", strAttr.c_str());
        return nullptr;
    }

    if (md->objecttype != objectType)
    {
        PyErr_Format(SaiRedisError, "Attribute: %s is not %s", strAttr.c_str(), info->objecttypename);
        return nullptr;
    }

    // we need to populate list pointers with predefined max value
    // so user will not have to manually populate that from python
    // all data types with pointers need special handling

    sai_attribute_t attr = {};

    std::vector<int> data(MAX_LIST_SIZE * LIST_ITEM_MAX_SIZE);

    switch (md->attrvaluetype)
    {
        case SAI_ATTR_VALUE_TYPE_BOOL:
        case SAI_ATTR_VALUE_TYPE_CHARDATA:
        case SAI_ATTR_VALUE_TYPE_UINT8:
        case SAI_ATTR_VALUE_TYPE_INT8:
        case SAI_ATTR_VALUE_TYPE_UINT16:
        case SAI_ATTR_VALUE_TYPE_INT16:
        case SAI_ATTR_VALUE_TYPE_UINT32:
        case SAI_ATTR_VALUE_TYPE_INT32:
        case SAI_ATTR_VALUE_TYPE_UINT64:
        case SAI_ATTR_VALUE_TYPE_INT64:
        case SAI_ATTR_VALUE_TYPE_MAC:
        case SAI_ATTR_VALUE_TYPE_IPV4:
        case SAI_ATTR_VALUE_TYPE_IPV6:
        case SAI_ATTR_VALUE_TYPE_POINTER:
        case SAI_ATTR_VALUE_TYPE_IP_ADDRESS:
        case SAI_ATTR_VALUE_TYPE_IP_PREFIX:
        case SAI_ATTR_VALUE_TYPE_OBJECT_ID:
            break;

        case SAI_ATTR_VALUE_TYPE_UINT32_RANGE:
        case SAI_ATTR_VALUE_TYPE_INT32_RANGE:
            break;

        case SAI_ATTR_VALUE_TYPE_OBJECT_LIST:
        case SAI_ATTR_VALUE_TYPE_UINT8_LIST:
        case SAI_ATTR_VALUE_TYPE_INT8_LIST:
        case SAI_ATTR_VALUE_TYPE_UINT16_LIST:
        case SAI_ATTR_VALUE_TYPE_INT16_LIST:
        case SAI_ATTR_VALUE_TYPE_UINT32_LIST:
        case SAI_ATTR_VALUE_TYPE_INT32_LIST:
        case SAI_ATTR_VALUE_TYPE_VLAN_LIST:
        case SAI_ATTR_VALUE_TYPE_QOS_MAP_LIST:
        case SAI_ATTR_VALUE_TYPE_MAP_LIST:
        case SAI_ATTR_VALUE_TYPE_ACL_RESOURCE_LIST:
        case SAI_ATTR_VALUE_TYPE_TLV_LIST:
        case SAI_ATTR_VALUE_TYPE_SEGMENT_LIST:
        case SAI_ATTR_VALUE_TYPE_IP_ADDRESS_LIST:
        case SAI_ATTR_VALUE_TYPE_PORT_EYE_VALUES_LIST:
            // we can get away with this since each list is count + pointer
            attr.value.s32list.count = MAX_LIST_SIZE;
            attr.value.s32list.list = data.data();
            break;

            // ACL FIELD DATA

        case SAI_ATTR_VALUE_TYPE_ACL_FIELD_DATA_BOOL:
        case SAI_ATTR_VALUE_TYPE_ACL_FIELD_DATA_UINT8:
        case SAI_ATTR_VALUE_TYPE_ACL_FIELD_DATA_INT8:
        case SAI_ATTR_VALUE_TYPE_ACL_FIELD_DATA_UINT16:
        case SAI_ATTR_VALUE_TYPE_ACL_FIELD_DATA_INT16:
        case SAI_ATTR_VALUE_TYPE_ACL_FIELD_DATA_UINT32:
        case SAI_ATTR_VALUE_TYPE_ACL_FIELD_DATA_INT32:
        case SAI_ATTR_VALUE_TYPE_ACL_FIELD_DATA_MAC:
        case SAI_ATTR_VALUE_TYPE_ACL_FIELD_DATA_IPV4:
        case SAI_ATTR_VALUE_TYPE_ACL_FIELD_DATA_IPV6:
        case SAI_ATTR_VALUE_TYPE_ACL_FIELD_DATA_OBJECT_ID:
            break;

            //case SAI_ATTR_VALUE_TYPE_ACL_FIELD_DATA_OBJECT_LIST:
            //case SAI_ATTR_VALUE_TYPE_ACL_FIELD_DATA_UINT8_LIST:

            // ACL ACTION DATA

        case SAI_ATTR_VALUE_TYPE_ACL_ACTION_DATA_BOOL:
        case SAI_ATTR_VALUE_TYPE_ACL_ACTION_DATA_UINT8:
        case SAI_ATTR_VALUE_TYPE_ACL_ACTION_DATA_INT8:
        case SAI_ATTR_VALUE_TYPE_ACL_ACTION_DATA_UINT16:
        case SAI_ATTR_VALUE_TYPE_ACL_ACTION_DATA_INT16:
        case SAI_ATTR_VALUE_TYPE_ACL_ACTION_DATA_UINT32:
        case SAI_ATTR_VALUE_TYPE_ACL_ACTION_DATA_INT32:
        case SAI_ATTR_VALUE_TYPE_ACL_ACTION_DATA_MAC:
        case SAI_ATTR_VALUE_TYPE_ACL_ACTION_DATA_IPV4:
        case SAI_ATTR_VALUE_TYPE_ACL_ACTION_DATA_IPV6:
        case SAI_ATTR_VALUE_TYPE_ACL_ACTION_DATA_OBJECT_ID:
            break;

            //case SAI_ATTR_VALUE_TYPE_ACL_ACTION_DATA_OBJECT_LIST:
            //case SAI_ATTR_VALUE_TYPE_ACL_CAPABILITY:

        default:
            PyErr_Format(SaiRedisError, "Attribute: %s value type is not supported yet, FIXME", strAttr.c_str());
            return nullptr;
    }

    attr.id = md->attrid;

    sai_status_t status = g_sai->get(
            objectType,
            objectId,
            1,
            &attr);

    PyObject *pdict = PyDict_New();
    PyDict_SetItemString(pdict, "status", PyString_FromFormat("%s", sai_serialize_status(status).c_str()));

    if (status == SAI_STATUS_SUCCESS)
    {
        switch (md->attrvaluetype)
        {
            // for list's we want to split list and return actual list
            case SAI_ATTR_VALUE_TYPE_OBJECT_LIST:
            case SAI_ATTR_VALUE_TYPE_UINT8_LIST:
            case SAI_ATTR_VALUE_TYPE_INT8_LIST:
            case SAI_ATTR_VALUE_TYPE_UINT16_LIST:
            case SAI_ATTR_VALUE_TYPE_INT16_LIST:
            case SAI_ATTR_VALUE_TYPE_UINT32_LIST:
            case SAI_ATTR_VALUE_TYPE_INT32_LIST:
            case SAI_ATTR_VALUE_TYPE_VLAN_LIST:

                // for simple lists, where they are separated by ',' we can use this split
                {
                    auto val = sai_serialize_attr_value(*md, attr, false);

                    val = val.substr(val.find_first_of(":") + 1);

                    auto tokens = swss::tokenize(val, ',');

                    auto *list = PyList_New(0);

                    for (auto&tok: tokens)
                    {
                        PyList_Append(list, PyString_FromString(tok.c_str()));
                    }

                    PyDict_SetItemString(pdict, strAttr.c_str(), list);
                }

                break;

            default:

                PyDict_SetItemString(pdict, strAttr.c_str(), PyString_FromFormat("%s", sai_serialize_attr_value(*md, attr, false).c_str()));
                break;
        }
    }

    return pdict;
}

// GLOBAL SAI APIS

static PyObject* api_initialize(PyObject *self, PyObject *args)
{
    SWSS_LOG_ENTER();

    if (!PyTuple_Check(args))
    {
        PyErr_Format(SaiRedisError, "Python error, expected args type is tuple");
        return nullptr;
    }

    int size = (int)PyTuple_Size(args);

    PyObject* dict = nullptr;

    if (size != 1)
    {
        PyErr_Format(SaiRedisError, "Expected number of arguments is 1, but %d given", size);
        return nullptr;
    }

    dict = PyTuple_GetItem(args, 0);

    if (!PyDict_CheckExact(dict))
    {
        PyErr_Format(SaiRedisError, "Passed argument must be of type dict");
        return nullptr;
    }

    g_profileMap.clear();

    PyObject *key, *value;
    Py_ssize_t pos = 0;

    while (PyDict_Next(dict, &pos, &key, &value))
    {
        if (!PyString_Check(key) || !PyString_Check(value))
        {
            PyErr_Format(SaiRedisError, "Keys and values in dict must be strings");
            return nullptr;
        }

        g_profileMap[PyString_AsString(key)] = PyString_AsString(value);
    }

    auto status = g_sai->initialize(0, &service_method_table);

    PyObject *pdict = PyDict_New();

    PyDict_SetItemString(pdict, "status", PyString_FromFormat("%s", sai_serialize_status(status).c_str()));

    return pdict;
}

static PyObject* api_uninitialize(PyObject *self, PyObject *args)
{
    SWSS_LOG_ENTER();

    auto status = g_sai->uninitialize();

    PyObject *pdict = PyDict_New();

    PyDict_SetItemString(pdict, "status", PyString_FromFormat("%s", sai_serialize_status(status).c_str()));

    return pdict;
}

// QUAD API

#define PYTHON_CREATE(OT,ot) \
static PyObject* create_ ## ot(PyObject *self, PyObject *args) \
{ return generic_create(SAI_OBJECT_TYPE_ ## OT , self, args); }

#define PYTHON_REMOVE(OT, ot) \
static PyObject* remove_ ## ot(PyObject *self, PyObject *args) \
{ return generic_remove(SAI_OBJECT_TYPE_ ## OT, self, args); }

#define PYTHON_SET(OT,ot) \
static PyObject* set_ ## ot ## _attribute(PyObject *self, PyObject *args) \
{ return generic_set(SAI_OBJECT_TYPE_ ## OT, self, args); }

#define PYTHON_GET(OT,ot) \
static PyObject* get_ ## ot ## _attribute(PyObject *self, PyObject *args) \
{ return generic_get(SAI_OBJECT_TYPE_ ## OT, self, args); }

#define PYTHON_GENERIC_QUAD(OT,ot) \
    PYTHON_CREATE(OT,ot) \
    PYTHON_REMOVE(OT,ot) \
    PYTHON_SET(OT,ot) \
    PYTHON_GET(OT,ot)

PYTHON_GENERIC_QUAD(SWITCH,switch);
PYTHON_GENERIC_QUAD(VLAN,vlan);

#define PYTHON_METHODS_GENERIC_QUAD(ot) \
{"create_" # ot,   create_ ## ot,  METH_VARARGS, "Create " # ot }, \
{"remove_" # ot,   remove_ ## ot,  METH_VARARGS, "Remove " # ot }, \
{"set_" # ot "_attribute",      set_ ## ot ## _attribute,     METH_VARARGS, "Set " # ot " atribute."}, \
{"get_" # ot "_attribute",      get_ ## ot ## _attribute,     METH_VARARGS, "Get " # ot " atribute."},

static PyMethodDef SaiRedisMethods[] = {

    {"api_initialize",      api_initialize,     METH_VARARGS, "SAI initialize"},
    {"api_uninitialize",    api_uninitialize,   METH_VARARGS, "SAI uninitialize"},

    PYTHON_METHODS_GENERIC_QUAD(switch)
    PYTHON_METHODS_GENERIC_QUAD(vlan)


    {NULL, NULL, 0, NULL}        // sentinel
};

extern "C" PyMODINIT_FUNC initsairedis(void);

PyMODINIT_FUNC initsairedis(void)
{
    SWSS_LOG_ENTER();

    PyObject *m;

    m = Py_InitModule("sairedis", SaiRedisMethods);

    if (m == NULL)
        return;

    g_sai = std::make_shared<sairedis::Sai>();

    SaiRedisError = PyErr_NewException(const_cast<char*>("sairedis.error"), NULL, NULL);
    Py_INCREF(SaiRedisError);
    PyModule_AddObject(m, "error", SaiRedisError);
}
