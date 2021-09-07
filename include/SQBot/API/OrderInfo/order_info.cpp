#include "order_info.h"

OrderInfo::OrderInfo(const Json& order_info)
  : name(SQBot::Utils::GetValue<std::string>(order_info, "name")),
    phone_number(SQBot::Utils::GetValue<std::string>(
        order_info, "phone_number")),
    email(SQBot::Utils::GetValue<std::string>(order_info, "email")),
    shipping_address(SQBot::Utils::GetPtr<ShippingAddress>(
        order_info, "shipping_address")) {}
