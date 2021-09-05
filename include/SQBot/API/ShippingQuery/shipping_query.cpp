#include "shipping_query.h"

ShippingQuery::ShippingQuery(const Json& shipping_address)
  : id(Utils::GetValue<std::string>(shipping_address, "id")),
    from(Utils::GetPtr<User>(shipping_address, "from")),
    invoice_payload(
        Utils::GetValue<std::string>(shipping_address, "invoice_payload")),
    shipping_address(
        Utils::GetPtr<ShippingAddress>(shipping_address, "shipping_address")) {}

