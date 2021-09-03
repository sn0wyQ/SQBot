#ifndef INCLUDE_SQBOT_API_ORDERINFO_ORDER_INFO_H_
#define INCLUDE_SQBOT_API_ORDERINFO_ORDER_INFO_H_

#include <memory>
#include <string>

#include "json.h"

#include "../ShippingAddress/shipping_address.h"

#include "../../Utils/utils.h"

// This object represents information about an order
class OrderInfo {
 public:
  OrderInfo() = default;
  explicit OrderInfo(const Json& order_info);

  // Optional. User's name
  std::string name;

  // Optional. User's phone number
  std::string phone_number;

  // Optional. User's email
  std::string email;

  // Optional. User's shipping address
  std::shared_ptr<ShippingAddress> shipping_address;
};

#endif  // INCLUDE_SQBOT_API_ORDERINFO_ORDER_INFO_H_
