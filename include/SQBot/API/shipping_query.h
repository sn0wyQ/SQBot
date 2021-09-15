#ifndef INCLUDE_SQBOT_API_SHIPPING_QUERY_H_
#define INCLUDE_SQBOT_API_SHIPPING_QUERY_H_

#include <memory>
#include <string>

#include "../../nlohmann/json.h"

#include "shipping_address.h"
#include "user.h"

#include "../Utils/utils.h"

// This object contains information about an incoming shipping query
class ShippingQuery {
 public:
  ShippingQuery() = default;
  explicit ShippingQuery(const Json& shipping_query);

  // Unique query identifier
  std::string id;

  // User who sent the query
  UserPtr from;

  // Bot specified invoice payload
  std::string invoice_payload;

  // User specified shipping address
  ShippingAddressPtr shipping_address;
};

using ShippingQueryPtr = std::shared_ptr<ShippingQuery>;

#endif  // INCLUDE_SQBOT_API_SHIPPING_QUERY_H_
