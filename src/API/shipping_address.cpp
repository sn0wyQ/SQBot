#include "../../include/SQBot/API/shipping_address.h"

ShippingAddress::ShippingAddress(const Json& shipping_address)
  : country_code(SQBot::Utils::GetValue<std::string>(
        shipping_address, "country_code")),
    state(SQBot::Utils::GetValue<std::string>(shipping_address, "state")),
    city(SQBot::Utils::GetValue<std::string>(shipping_address, "city")),
    street_line1(SQBot::Utils::GetValue<std::string>(
        shipping_address, "street_line1")),
    street_line2(SQBot::Utils::GetValue<std::string>(
        shipping_address, "street_line2")),
    post_code(SQBot::Utils::GetValue<std::string>(
        shipping_address, "post_code")) {}
