#ifndef INCLUDE_SQBOT_API_SHIPPINGQUERY_SHIPPING_QUERY_H_
#define INCLUDE_SQBOT_API_SHIPPINGQUERY_SHIPPING_QUERY_H_

#include <memory>
#include <string>

#include "json.h"

#include "../ShippingAddress/shipping_address.h"
#include "../User/user.h"

#include "../../Utils/utils.h"

// This object contains information about an incoming shipping query
class ShippingQuery {
 public:
  ShippingQuery() = default;
  explicit ShippingQuery(const Json& shipping_query);

  // Unique query identifier
  std::string id;

  // User who sent the query
  std::shared_ptr<User> from;

  // Bot specified invoice payload
  std::string invoice_payload;

  // User specified shipping address
  std::shared_ptr<ShippingAddress> shipping_address;
};

#endif  // INCLUDE_SQBOT_API_SHIPPINGQUERY_SHIPPING_QUERY_H_
