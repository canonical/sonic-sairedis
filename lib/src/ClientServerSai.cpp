#include "ClientServerSai.h"
#include "ClientSai.h"
#include "ServerSai.h"
#include "SaiInternal.h"
#include "Sai.h"

#include "swss/logger.h"

#include "meta/sai_serialize.h"

using namespace sairedis;
using namespace std::placeholders;

#define REDIS_CHECK_API_INITIALIZED()                                       \
    if (!m_apiInitialized) {                                                \
        SWSS_LOG_ERROR("%s: api not initialized", __PRETTY_FUNCTION__);     \
        return SAI_STATUS_FAILURE; }

ClientServerSai::ClientServerSai()
{
    SWSS_LOG_ENTER();

    m_apiInitialized = false;
}

ClientServerSai::~ClientServerSai()
{
    SWSS_LOG_ENTER();

    if (m_apiInitialized)
    {
        uninitialize();
    }
}

// INITIALIZE UNINITIALIZE

sai_status_t ClientServerSai::initialize(
        _In_ uint64_t flags,
        _In_ const sai_service_method_table_t *service_method_table)
{
    MUTEX();
    SWSS_LOG_ENTER();

    if (m_apiInitialized)
    {
        SWSS_LOG_ERROR("%s: api already initialized", __PRETTY_FUNCTION__);

        return SAI_STATUS_FAILURE;
    }

    if (flags != 0)
    {
        SWSS_LOG_ERROR("invalid flags passed to SAI API initialize");

        return SAI_STATUS_INVALID_PARAMETER;
    }

    if ((service_method_table == NULL) ||
            (service_method_table->profile_get_next_value == NULL) ||
            (service_method_table->profile_get_value == NULL))
    {
        SWSS_LOG_ERROR("invalid service_method_table handle passed to SAI API initialize");

        return SAI_STATUS_INVALID_PARAMETER;
    }

    memcpy(&m_service_method_table, service_method_table, sizeof(m_service_method_table));

    const char* enableClient = service_method_table->profile_get_value(0, SAI_REDIS_KEY_ENABLE_CLIENT);

    if (enableClient && strcmp(enableClient, "true") == 0)
    {
        SWSS_LOG_NOTICE("acting as a sairedis CLIENT");

        m_sai = std::make_shared<ClientSai>();
    }
    else
    {
        SWSS_LOG_NOTICE("acting as a sairedis SERVER");

        m_sai = std::make_shared<ServerSai>();
    }

    auto status = m_sai->initialize(flags, service_method_table);

    SWSS_LOG_NOTICE("init client/server sai: %s", sai_serialize_status(status).c_str());

    if (status == SAI_STATUS_SUCCESS)
    {
        m_apiInitialized = true;
    }

    return status;
}

sai_status_t ClientServerSai::uninitialize(void)
{
    SWSS_LOG_ENTER();
    REDIS_CHECK_API_INITIALIZED();

    SWSS_LOG_NOTICE("begin");

    m_apiInitialized = false;

    m_sai = nullptr;

    SWSS_LOG_NOTICE("end");

    return SAI_STATUS_SUCCESS;
}

// QUAD OID

sai_status_t ClientServerSai::create(
        _In_ sai_object_type_t objectType,
        _Out_ sai_object_id_t* objectId,
        _In_ sai_object_id_t switchId,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list)
{
    MUTEX();
    SWSS_LOG_ENTER();
    REDIS_CHECK_API_INITIALIZED();

    return m_sai->create(
            objectType, 
            objectId,
            switchId, 
            attr_count, 
            attr_list);
}

sai_status_t ClientServerSai::remove(
        _In_ sai_object_type_t objectType,
        _In_ sai_object_id_t objectId)
{
    MUTEX();
    SWSS_LOG_ENTER();
    REDIS_CHECK_API_INITIALIZED();

    return m_sai->remove(objectType, objectId);
}

sai_status_t ClientServerSai::set(
        _In_ sai_object_type_t objectType,
        _In_ sai_object_id_t objectId,
        _In_ const sai_attribute_t *attr)
{
    MUTEX();
    SWSS_LOG_ENTER();
    REDIS_CHECK_API_INITIALIZED();

    return m_sai->set(objectType, objectId, attr);
}

sai_status_t ClientServerSai::get(
        _In_ sai_object_type_t objectType,
        _In_ sai_object_id_t objectId,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list)
{
    MUTEX();
    SWSS_LOG_ENTER();
    REDIS_CHECK_API_INITIALIZED();

    return m_sai->get(
            objectType,
            objectId,
            attr_count,
            attr_list);
}

// QUAD ENTRY

#define DECLARE_CREATE_ENTRY(OT,ot)                                 \
sai_status_t ClientServerSai::create(                               \
        _In_ const sai_ ## ot ## _t* entry,                         \
        _In_ uint32_t attr_count,                                   \
        _In_ const sai_attribute_t *attr_list)                      \
{                                                                   \
    MUTEX();                                                        \
    SWSS_LOG_ENTER();                                               \
    REDIS_CHECK_API_INITIALIZED();                                  \
    return m_sai->create(entry, attr_count, attr_list);             \
}

DECLARE_CREATE_ENTRY(FDB_ENTRY,fdb_entry);
DECLARE_CREATE_ENTRY(INSEG_ENTRY,inseg_entry);
DECLARE_CREATE_ENTRY(IPMC_ENTRY,ipmc_entry);
DECLARE_CREATE_ENTRY(L2MC_ENTRY,l2mc_entry);
DECLARE_CREATE_ENTRY(MCAST_FDB_ENTRY,mcast_fdb_entry);
DECLARE_CREATE_ENTRY(NEIGHBOR_ENTRY,neighbor_entry);
DECLARE_CREATE_ENTRY(ROUTE_ENTRY,route_entry);
DECLARE_CREATE_ENTRY(NAT_ENTRY,nat_entry);


#define DECLARE_REMOVE_ENTRY(OT,ot)                         \
sai_status_t ClientServerSai::remove(                       \
        _In_ const sai_ ## ot ## _t* entry)                 \
{                                                           \
    MUTEX();                                                \
    SWSS_LOG_ENTER();                                       \
    REDIS_CHECK_API_INITIALIZED();                          \
    return m_sai->remove(entry);                            \
}

DECLARE_REMOVE_ENTRY(FDB_ENTRY,fdb_entry);
DECLARE_REMOVE_ENTRY(INSEG_ENTRY,inseg_entry);
DECLARE_REMOVE_ENTRY(IPMC_ENTRY,ipmc_entry);
DECLARE_REMOVE_ENTRY(L2MC_ENTRY,l2mc_entry);
DECLARE_REMOVE_ENTRY(MCAST_FDB_ENTRY,mcast_fdb_entry);
DECLARE_REMOVE_ENTRY(NEIGHBOR_ENTRY,neighbor_entry);
DECLARE_REMOVE_ENTRY(ROUTE_ENTRY,route_entry);
DECLARE_REMOVE_ENTRY(NAT_ENTRY,nat_entry);

#define DECLARE_SET_ENTRY(OT,ot)                            \
sai_status_t ClientServerSai::set(                          \
        _In_ const sai_ ## ot ## _t* entry,                 \
        _In_ const sai_attribute_t *attr)                   \
{                                                           \
    MUTEX();                                                \
    SWSS_LOG_ENTER();                                       \
    REDIS_CHECK_API_INITIALIZED();                          \
    return m_sai->set(entry, attr);                         \
}

DECLARE_SET_ENTRY(FDB_ENTRY,fdb_entry);
DECLARE_SET_ENTRY(INSEG_ENTRY,inseg_entry);
DECLARE_SET_ENTRY(IPMC_ENTRY,ipmc_entry);
DECLARE_SET_ENTRY(L2MC_ENTRY,l2mc_entry);
DECLARE_SET_ENTRY(MCAST_FDB_ENTRY,mcast_fdb_entry);
DECLARE_SET_ENTRY(NEIGHBOR_ENTRY,neighbor_entry);
DECLARE_SET_ENTRY(ROUTE_ENTRY,route_entry);
DECLARE_SET_ENTRY(NAT_ENTRY,nat_entry);

#define DECLARE_GET_ENTRY(OT,ot)                                \
sai_status_t ClientServerSai::get(                              \
        _In_ const sai_ ## ot ## _t* entry,                     \
        _In_ uint32_t attr_count,                               \
        _Inout_ sai_attribute_t *attr_list)                     \
{                                                               \
    MUTEX();                                                    \
    SWSS_LOG_ENTER();                                           \
    REDIS_CHECK_API_INITIALIZED();                              \
    return m_sai->get(entry, attr_count, attr_list);            \
}

DECLARE_GET_ENTRY(FDB_ENTRY,fdb_entry);
DECLARE_GET_ENTRY(INSEG_ENTRY,inseg_entry);
DECLARE_GET_ENTRY(IPMC_ENTRY,ipmc_entry);
DECLARE_GET_ENTRY(L2MC_ENTRY,l2mc_entry);
DECLARE_GET_ENTRY(MCAST_FDB_ENTRY,mcast_fdb_entry);
DECLARE_GET_ENTRY(NEIGHBOR_ENTRY,neighbor_entry);
DECLARE_GET_ENTRY(ROUTE_ENTRY,route_entry);
DECLARE_GET_ENTRY(NAT_ENTRY,nat_entry);

// STATS

sai_status_t ClientServerSai::getStats(
        _In_ sai_object_type_t object_type,
        _In_ sai_object_id_t object_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _Out_ uint64_t *counters)
{
    MUTEX();
    SWSS_LOG_ENTER();
    REDIS_CHECK_API_INITIALIZED();

    return m_sai->getStats(
            object_type,
            object_id,
            number_of_counters,
            counter_ids,
            counters);
}

sai_status_t ClientServerSai::getStatsExt(
        _In_ sai_object_type_t object_type,
        _In_ sai_object_id_t object_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _In_ sai_stats_mode_t mode,
        _Out_ uint64_t *counters)
{
    MUTEX();
    SWSS_LOG_ENTER();
    REDIS_CHECK_API_INITIALIZED();

    return m_sai->getStatsExt(
            object_type,
            object_id,
            number_of_counters,
            counter_ids,
            mode,
            counters);
}

sai_status_t ClientServerSai::clearStats(
        _In_ sai_object_type_t object_type,
        _In_ sai_object_id_t object_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids)
{
    MUTEX();
    SWSS_LOG_ENTER();
    REDIS_CHECK_API_INITIALIZED();

    return m_sai->clearStats(
            object_type,
            object_id,
            number_of_counters,
            counter_ids);
}

// BULK QUAD OID

sai_status_t ClientServerSai::bulkCreate(
        _In_ sai_object_type_t object_type,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t object_count,
        _In_ const uint32_t *attr_count,
        _In_ const sai_attribute_t **attr_list,
        _In_ sai_bulk_op_error_mode_t mode,
        _Out_ sai_object_id_t *object_id,
        _Out_ sai_status_t *object_statuses)
{
    MUTEX();
    SWSS_LOG_ENTER();
    REDIS_CHECK_API_INITIALIZED();

    return m_sai->bulkCreate(
            object_type,
            switch_id,
            object_count,
            attr_count,
            attr_list,
            mode,
            object_id,
            object_statuses);
}

sai_status_t ClientServerSai::bulkRemove(
        _In_ sai_object_type_t object_type,
        _In_ uint32_t object_count,
        _In_ const sai_object_id_t *object_id,
        _In_ sai_bulk_op_error_mode_t mode,
        _Out_ sai_status_t *object_statuses)
{
    MUTEX();
    SWSS_LOG_ENTER();
    REDIS_CHECK_API_INITIALIZED();

    return m_sai->bulkRemove(
            object_type,
            object_count,
            object_id,
            mode,
            object_statuses);
}

sai_status_t ClientServerSai::bulkSet(
        _In_ sai_object_type_t object_type,
        _In_ uint32_t object_count,
        _In_ const sai_object_id_t *object_id,
        _In_ const sai_attribute_t *attr_list,
        _In_ sai_bulk_op_error_mode_t mode,
        _Out_ sai_status_t *object_statuses)
{
    MUTEX();
    SWSS_LOG_ENTER();
    REDIS_CHECK_API_INITIALIZED();

    return m_sai->bulkSet(
            object_type,
            object_count,
            object_id,
            attr_list,
            mode,
            object_statuses);
}

// BULK QUAD ENTRY

#define DECLARE_BULK_CREATE_ENTRY(OT,ot)                    \
sai_status_t ClientServerSai::bulkCreate(                   \
        _In_ uint32_t object_count,                         \
        _In_ const sai_ ## ot ## _t* entries,               \
        _In_ const uint32_t *attr_count,                    \
        _In_ const sai_attribute_t **attr_list,             \
        _In_ sai_bulk_op_error_mode_t mode,                 \
        _Out_ sai_status_t *object_statuses)                \
{                                                           \
    MUTEX();                                                \
    SWSS_LOG_ENTER();                                       \
    REDIS_CHECK_API_INITIALIZED();                          \
    return m_sai->bulkCreate(                               \
            object_count,                                   \
            entries,                                        \
            attr_count,                                     \
            attr_list,                                      \
            mode,                                           \
            object_statuses);                               \
}

DECLARE_BULK_CREATE_ENTRY(ROUTE_ENTRY,route_entry)
DECLARE_BULK_CREATE_ENTRY(FDB_ENTRY,fdb_entry);
DECLARE_BULK_CREATE_ENTRY(INSEG_ENTRY,inseg_entry);
DECLARE_BULK_CREATE_ENTRY(NAT_ENTRY,nat_entry)


// BULK REMOVE

#define DECLARE_BULK_REMOVE_ENTRY(OT,ot)                    \
sai_status_t ClientServerSai::bulkRemove(                   \
        _In_ uint32_t object_count,                         \
        _In_ const sai_ ## ot ## _t *entries,               \
        _In_ sai_bulk_op_error_mode_t mode,                 \
        _Out_ sai_status_t *object_statuses)                \
{                                                           \
    MUTEX();                                                \
    SWSS_LOG_ENTER();                                       \
    REDIS_CHECK_API_INITIALIZED();                          \
    return m_sai->bulkRemove(                               \
            object_count,                                   \
            entries,                                        \
            mode,                                           \
            object_statuses);                               \
}

DECLARE_BULK_REMOVE_ENTRY(ROUTE_ENTRY,route_entry)
DECLARE_BULK_REMOVE_ENTRY(FDB_ENTRY,fdb_entry);
DECLARE_BULK_REMOVE_ENTRY(INSEG_ENTRY,inseg_entry);
DECLARE_BULK_REMOVE_ENTRY(NAT_ENTRY,nat_entry)

// BULK SET

#define DECLARE_BULK_SET_ENTRY(OT,ot)                       \
sai_status_t ClientServerSai::bulkSet(                      \
        _In_ uint32_t object_count,                         \
        _In_ const sai_ ## ot ## _t *entries,               \
        _In_ const sai_attribute_t *attr_list,              \
        _In_ sai_bulk_op_error_mode_t mode,                 \
        _Out_ sai_status_t *object_statuses)                \
{                                                           \
    MUTEX();                                                \
    SWSS_LOG_ENTER();                                       \
    REDIS_CHECK_API_INITIALIZED();                          \
    return m_sai->bulkSet(                                  \
            object_count,                                   \
            entries,                                        \
            attr_list,                                      \
            mode,                                           \
            object_statuses);                               \
}

DECLARE_BULK_SET_ENTRY(ROUTE_ENTRY,route_entry);
DECLARE_BULK_SET_ENTRY(FDB_ENTRY,fdb_entry);
DECLARE_BULK_SET_ENTRY(INSEG_ENTRY,inseg_entry);
DECLARE_BULK_SET_ENTRY(NAT_ENTRY,nat_entry);

// NON QUAD API

sai_status_t ClientServerSai::flushFdbEntries(
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list)
{
    MUTEX();
    SWSS_LOG_ENTER();
    REDIS_CHECK_API_INITIALIZED();

    return m_sai->flushFdbEntries(switch_id, attr_count, attr_list);
}

// SAI API

sai_status_t ClientServerSai::objectTypeGetAvailability(
        _In_ sai_object_id_t switchId,
        _In_ sai_object_type_t objectType,
        _In_ uint32_t attrCount,
        _In_ const sai_attribute_t *attrList,
        _Out_ uint64_t *count)
{
    MUTEX();
    SWSS_LOG_ENTER();
    REDIS_CHECK_API_INITIALIZED();

    return m_sai->objectTypeGetAvailability(
            switchId,
            objectType,
            attrCount,
            attrList,
            count);
}

sai_status_t ClientServerSai::queryAttributeCapability(
        _In_ sai_object_id_t switch_id,
        _In_ sai_object_type_t object_type,
        _In_ sai_attr_id_t attr_id,
        _Out_ sai_attr_capability_t *capability)
{
    MUTEX();
    SWSS_LOG_ENTER();
    REDIS_CHECK_API_INITIALIZED();

    return m_sai->queryAttributeCapability(
            switch_id,
            object_type,
            attr_id,
            capability);
}

sai_status_t ClientServerSai::queryAattributeEnumValuesCapability(
        _In_ sai_object_id_t switch_id,
        _In_ sai_object_type_t object_type,
        _In_ sai_attr_id_t attr_id,
        _Inout_ sai_s32_list_t *enum_values_capability)
{
    MUTEX();
    SWSS_LOG_ENTER();
    REDIS_CHECK_API_INITIALIZED();

    return m_sai->queryAattributeEnumValuesCapability(
            switch_id,
            object_type,
            attr_id,
            enum_values_capability);
}

sai_object_type_t ClientServerSai::objectTypeQuery(
        _In_ sai_object_id_t objectId)
{
    SWSS_LOG_ENTER();

    if (!m_apiInitialized)
    {
        SWSS_LOG_ERROR("%s: SAI API not initialized", __PRETTY_FUNCTION__);

        return SAI_OBJECT_TYPE_NULL;
    }

    return m_sai->objectTypeQuery(objectId);
}

sai_object_id_t ClientServerSai::switchIdQuery(
        _In_ sai_object_id_t objectId)
{
    SWSS_LOG_ENTER();

    if (!m_apiInitialized)
    {
        SWSS_LOG_ERROR("%s: SAI API not initialized", __PRETTY_FUNCTION__);

        return SAI_NULL_OBJECT_ID;
    }

    return m_sai->switchIdQuery(objectId);
}

sai_status_t ClientServerSai::logSet(
        _In_ sai_api_t api,
        _In_ sai_log_level_t log_level)
{
    MUTEX();
    SWSS_LOG_ENTER();
    REDIS_CHECK_API_INITIALIZED();

    return m_sai->logSet(api, log_level);
}
