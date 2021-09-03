#include "shipping_address.h"

ShippingAddress::ShippingAddress(const Json& shipping_address)
  : country_code(
      Utils::GetValue<std::string>(shipping_address, "country_code")),
    state(Utils::GetValue<std::string>(shipping_address, "state")),
    city(Utils::GetValue<std::string>(shipping_address, "city")),
    street_line1(
        Utils::GetValue<std::string>(shipping_address, "street_line1")),
    street_line2(
        Utils::GetValue<std::string>(shipping_address, "street_line2")),
    post_code(Utils::GetValue<std::string>(shipping_address, "post_code")) {}
