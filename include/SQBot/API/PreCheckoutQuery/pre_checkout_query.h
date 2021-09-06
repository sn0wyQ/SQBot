#ifndef INCLUDE_SQBOT_API_PRECHECKOUTQUERY_PRE_CHECKOUT_QUERY_H_
#define INCLUDE_SQBOT_API_PRECHECKOUTQUERY_PRE_CHECKOUT_QUERY_H_

#include <memory>
#include <string>

#include "../../../nlohmann/json.h"

#include "../OrderInfo/order_info.h"
#include "../User/user.h"

#include "../../Utils/utils.h"

// This object contains information about an incoming pre-checkout query
class PreCheckoutQuery {
 public:
  PreCheckoutQuery() = default;
  explicit PreCheckoutQuery(const Json& pre_checkout_query);

  // Unique query identifier
  std::string id;

  // User who sent the query
  std::shared_ptr<User> from;

  // Three-letter ISO 4217 currency code
  // https://core.telegram.org/bots/payments#supported-currencies
  std::string currency;

  // Total price in the smallest units of the currency
  // (integer, not float/double). For example, for a price of
  // US$ 1.45 pass amount = 145. See the exp parameter in currencies.json,
  // it shows the number of digits past the decimal point for each currency
  // (2 for the majority of currencies)
  // currencies.json: https://core.telegram.org/bots/payments/currencies.json
  int32_t total_amount{};

  // Bot specified invoice payload
  std::string invoice_payload;

  // OPTIONAL. Identifier of the shipping option chosen by the user
  std::string shipping_option_id;

  // OPTIONAL. Order info provided by the user
  std::shared_ptr<OrderInfo> order_info;
};

#endif  // INCLUDE_SQBOT_API_PRECHECKOUTQUERY_PRE_CHECKOUT_QUERY_H_
