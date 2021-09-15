#ifndef INCLUDE_SQBOT_API_REPLY_KEYBOARD_REMOVE_H_
#define INCLUDE_SQBOT_API_REPLY_KEYBOARD_REMOVE_H_

#include <memory>
#include <string>

#include "../../nlohmann/json.h"

#include "../Utils/utils.h"

// This object represents a shipping address
class ShippingAddress {
 public:
  ShippingAddress() = default;
  explicit ShippingAddress(const Json& shipping_address);

  // ISO 3166-1 alpha-2 country code
  std::string country_code;

  // State, if applicable
  std::string state;

  // City
  std::string city;

  // First line for the address
  std::string street_line1;

  // Second line for the address
  std::string street_line2;

  // Address post code
  std::string post_code;
};

using ShippingAddressPtr = std::shared_ptr<ShippingAddress>;

#endif  // INCLUDE_SQBOT_API_REPLY_KEYBOARD_REMOVE_H_
