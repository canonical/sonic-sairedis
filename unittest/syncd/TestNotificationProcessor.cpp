#include "VirtualOidTranslator.h"
#include "RedisNotificationProducer.h"
#include "NotificationProcessor.h"
#include "lib/RedisVidIndexGenerator.h"
#include "lib/sairediscommon.h"
#include "vslib/Sai.h"

#include <gtest/gtest.h>

using namespace syncd;

static std::string natData =
"[{\"nat_entry\":\"{\\\"nat_data\\\":{\\\"key\\\":{\\\"dst_ip\\\":\\\"10.10.10.10\\\",\\\"l4_dst_port\\\":\\\"20006\\\",\\\"l4_src_port\\\":\\\"0\\\",\\\"proto\\\":\\\"6\\\",\\\"src_ip\\\":\\\"0.0.0.0\\\"},\\\"mask\\\":{\\\"dst_ip\\\":\\\"255.255.255.255\\\",\\\"l4_dst_port\\\":\\\"65535\\\",\\\"l4_src_port\\\":\\\"0\\\",\\\"proto\\\":\\\"255\\\",\\\"src_ip\\\":\\\"0.0.0.0\\\"}},\\\"nat_type\\\":\\\"SAI_NAT_TYPE_DESTINATION_NAT\\\",\\\"switch_id\\\":\\\"oid:0x21000000000000\\\",\\\"vr\\\":\\\"oid:0x3000000000048\\\"}\",\"nat_event\":\"SAI_NAT_EVENT_AGED\"}]";

TEST(NotificationProcessor, NotificationProcessorTest)
{
    auto sai = std::make_shared<saivs::Sai>();
    auto dbAsic = std::make_shared<swss::DBConnector>("ASIC_DB", 0);
    auto client = std::make_shared<RedisClient>(dbAsic);
    auto producer = std::make_shared<syncd::RedisNotificationProducer>("ASIC_DB");

    auto notificationProcessor = std::make_shared<NotificationProcessor>(producer, client,
                                                             [](const swss::KeyOpFieldsValuesTuple&){});
    EXPECT_NE(notificationProcessor, nullptr);

    auto switchConfigContainer = std::make_shared<sairedis::SwitchConfigContainer>();
    auto redisVidIndexGenerator = std::make_shared<sairedis::RedisVidIndexGenerator>(dbAsic, REDIS_KEY_VIDCOUNTER);
    EXPECT_NE(redisVidIndexGenerator, nullptr);

    auto virtualObjectIdManager = std::make_shared<sairedis::VirtualObjectIdManager>(0, switchConfigContainer, redisVidIndexGenerator);
    EXPECT_NE(virtualObjectIdManager, nullptr);

    auto translator = std::make_shared<VirtualOidTranslator>(client,
                                                             virtualObjectIdManager,
                                                             sai);
    EXPECT_NE(translator, nullptr);
    notificationProcessor->m_translator = translator;

    // Check NAT notification without RIDs
    std::vector<swss::FieldValueTuple> natEntry;
    swss::KeyOpFieldsValuesTuple natFV(SAI_SWITCH_NOTIFICATION_NAME_NAT_EVENT, natData, natEntry);
    notificationProcessor->syncProcessNotification(natFV);

    // Check NAT notification with RIDs present
    translator->insertRidAndVid(0x21000000000000,0x210000000000);
    translator->insertRidAndVid(0x3000000000048,0x30000000048);

    notificationProcessor->syncProcessNotification(natFV);

    translator->eraseRidAndVid(0x21000000000000,0x210000000000);
    translator->eraseRidAndVid(0x3000000000048,0x30000000048);

    // Test FDB MOVE event
    std::string key = "ASIC_STATE:SAI_OBJECT_TYPE_FDB_ENTRY:{\"bvid\":\"oid:0x26000000000001\",\"mac\":\"00:00:00:00:00:01\",\"switch_id\":\"oid:0x21000000000000\"}";
    dbAsic->hset(key, "SAI_FDB_ENTRY_ATTR_BRIDGE_PORT_ID", "oid:0x3a000000000a98");
    dbAsic->hset(key, "SAI_FDB_ENTRY_ATTR_TYPE", "SAI_FDB_ENTRY_TYPE_STATIC");
    dbAsic->hset(key, "SAI_FDB_ENTRY_ATTR_ENDPOINT_IP", "10.0.0.1");

    sai_fdb_event_notification_data_t fdb;
    memset(&fdb, 0, sizeof(sai_fdb_event_notification_data_t));
    fdb.event_type = SAI_FDB_EVENT_MOVED;
    fdb.fdb_entry.switch_id = 0x21000000000000;
    fdb.fdb_entry.mac_address[5] = 1;
    fdb.fdb_entry.bv_id = 0x26000000000001;
    fdb.attr_count = 1;
    sai_attribute_t attr[1];
    attr[0].id = SAI_FDB_ENTRY_ATTR_BRIDGE_PORT_ID;
    attr[0].value.oid = 0x3a000000000a99;
    fdb.attr = attr;

    notificationProcessor->redisPutFdbEntryToAsicView(&fdb);
    string bridgeport = dbAsic->hget(key, "SAI_FDB_ENTRY_ATTR_BRIDGE_PORT_ID");
    string ip = dbAsic->hget(key, "SAI_FDB_ENTRY_ATTR_ENDPOINT_IP");
    EXPECT_EQ(bridgeport, "0x3a000000000a99");
    EXPECT_EQ(ip, "");
}
