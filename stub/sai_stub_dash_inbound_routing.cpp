#include "sai_stub.h"

STUB_GENERIC_QUAD_ENTRY(INBOUND_ROUTING_ENTRY, inbound_routing_entry);
STUB_BULK_CREATE_ENTRY_EX(INBOUND_ROUTING_ENTRY, inbound_routing_entry, inbound_routing_entries);
STUB_BULK_REMOVE_ENTRY_EX(INBOUND_ROUTING_ENTRY, inbound_routing_entry, inbound_routing_entries);

const sai_dash_inbound_routing_api_t stub_dash_inbound_routing_api = {
    STUB_GENERIC_QUAD_API(inbound_routing_entry)
    stub_bulk_create_inbound_routing_entries,
    stub_bulk_remove_inbound_routing_entries,
};
