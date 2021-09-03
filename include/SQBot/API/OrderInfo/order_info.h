#ifndef ORDER_INFO_H_
#define ORDER_INFO_H_

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
  ShippingAddress shipping_address;
};

#endif  // ORDER_INFO_H_
