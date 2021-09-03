#include "order_info.h"

OrderInfo::OrderInfo(const Json& order_info)
  : name(Utils::GetValue<std::string>(order_info, "name")),
    phone_number(Utils::GetValue<std::string>(order_info, "phone_number")),
    email(Utils::GetValue<std::string>(order_info, "email")),
    shipping_address(Utils::GetValue<Json>(order_info, "shipping_address")) {}
