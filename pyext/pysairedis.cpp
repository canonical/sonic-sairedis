#include "pysairedis.h"

#include <cstddef>

#include "swss/logger.h"

#include "meta/sai_serialize.h"

static std::map<std::string, std::string> g_profileMap;
static std::map<std::string, std::string>::iterator g_profileMapIterator = g_profileMap.begin();

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

    if (value == NULL)
    {
        // Restarts enumeration
        g_profileMapIterator = g_profileMap.begin();
    }
    else if (g_profileMapIterator == g_profileMap.end())
    {
        return -1;
    }
    else
    {
        *variable = g_profileMapIterator->first.c_str();
        *value = g_profileMapIterator->second.c_str();
        g_profileMapIterator++;
    }

    if (g_profileMapIterator != g_profileMap.end())
        return 0;

    return -1;
}

static const sai_service_method_table_t g_smt = {
    profile_get_value,
    profile_get_next_value
};

sai_status_t sai_api_initialize(
        _In_ uint64_t flags,
        _In_ const std::map<std::string, std::string>& profileMap)
{
    g_profileMap = profileMap;
    g_profileMapIterator = g_profileMap.begin();

    return sai_api_initialize(flags, &g_smt);
}

sai_status_t sai_get_switch_api(sai_switch_api_t* out)
{
    sai_switch_api_t* api;

    sai_status_t status = sai_api_query(SAI_API_SWITCH, (void**)&api);

    if (status == SAI_STATUS_SUCCESS)
    {
        *out = *api;
    }

    return status;
}

sai_status_t sai_get_lag_api(sai_lag_api_t* out)
{
    sai_lag_api_t* api;

    sai_status_t status = sai_api_query(SAI_API_LAG, (void**)&api);

    if (status == SAI_STATUS_SUCCESS)
    {
        *out = *api;
    }

    return status;
}

sai_status_t sai_get_router_interface_api(sai_router_interface_api_t* out)
{
    sai_router_interface_api_t* api;

    sai_status_t status = sai_api_query(SAI_API_ROUTER_INTERFACE, (void**)&api);

    if (status == SAI_STATUS_SUCCESS)
    {
        *out = *api;
    }

    return status;
}

sai_status_t sai_get_next_hop_api(sai_next_hop_api_t* out)
{
    sai_next_hop_api_t* api;

    sai_status_t status = sai_api_query(SAI_API_NEXT_HOP, (void**)&api);

    if (status == SAI_STATUS_SUCCESS)
    {
        *out = *api;
    }

    return status;
}

sai_status_t sai_get_route_api(sai_route_api_t* out)
{
    sai_route_api_t* api;

    sai_status_t status = sai_api_query(SAI_API_ROUTE, (void**)&api);

    if (status == SAI_STATUS_SUCCESS)
    {
        *out = *api;
    }

    return status;
}

sai_status_t sai_get_vlan_api(sai_vlan_api_t* out)
{
    sai_vlan_api_t* api;

    sai_status_t status = sai_api_query(SAI_API_VLAN, (void**)&api);

    if (status == SAI_STATUS_SUCCESS)
    {
        *out = *api;
    }

    return status;
}

sai_status_t sai_get_fdb_api(sai_fdb_api_t* out)
{
    sai_fdb_api_t* api;

    sai_status_t status = sai_api_query(SAI_API_FDB, (void**)&api);

    if (status == SAI_STATUS_SUCCESS)
    {
        *out = *api;
    }

    return status;
}

sai_mac_t* sai_mac_t_from_string(const std::string& s)
{
    sai_mac_t *mac = (sai_mac_t*)calloc(1, sizeof(sai_mac_t));

    sai_deserialize_mac(s, *mac);

    return mac;
}

sai_ip_address_t* sai_ip_address_t_from_string(const std::string& s)
{
    sai_ip_address_t* ip = (sai_ip_address_t*)calloc(1, sizeof(sai_ip_address_t));

    sai_deserialize_ip_address(s, *ip);
    return ip;
}

sai_ip_prefix_t* sai_ip_prefix_t_from_string(const std::string& s)
{
    sai_ip_prefix_t* ip = (sai_ip_prefix_t*)calloc(1, sizeof(sai_ip_prefix_t));

    sai_deserialize_ip_prefix(s, *ip);

    return ip;
}
