#include "../../include/SQBot/API/shipping_query.h"

ShippingQuery::ShippingQuery(const Json& shipping_address)
  : id(SQBot::Utils::GetValue<std::string>(shipping_address, "id")),
    from(SQBot::Utils::GetPtr<User>(shipping_address, "from")),
    invoice_payload(SQBot::Utils::GetValue<std::string>(
        shipping_address, "invoice_payload")),
    shipping_address(SQBot::Utils::GetPtr<ShippingAddress>(
        shipping_address, "shipping_address")) {}

