#ifndef INCLUDE_SQBOT_API_SUCCESSFULPAYMENT_SUCCESSFUL_PAYMENT_H_
#define INCLUDE_SQBOT_API_SUCCESSFULPAYMENT_SUCCESSFUL_PAYMENT_H_

#include <memory>
#include <string>

#include "../../nlohmann/json.h"

#include "order_info.h"

#include "../Utils/utils.h"

// This object contains basic information about a successful payment
class SuccessfulPayment {
 public:
  SuccessfulPayment() = default;
  explicit SuccessfulPayment(const Json& successful_payment);

  // Three-letter ISO 4217 currency code
  // https://core.telegram.org/bots/payments#supported-currencies
  std::string currency;

  // Total price in the smallest units of the currency
  // (integer, not float/double). For example, for a price of US$ 1.45
  // pass amount = 145. See the exp parameter in currencies.json,
  // it shows the number of digits past the decimal point for each currency
  // (2 for the majority of currencies).
  // currencies.json link:
  // https://core.telegram.org/bots/payments/currencies.json
  int32_t total_amount{};

  // Bot specified invoice payload
  std::string invoice_payload;

  // OPTIONAL. Identifier of the shipping option chosen by the user
  std::string shipping_option_id;

  // OPTIONAL. Order info provided by the user
  OrderInfoPtr order_info;

  // Telegram payment identifier
  std::string telegram_payment_charge_id;

  // Provider payment identifier
  std::string provider_payment_charge_id;
};

using SuccessfulPaymentPtr = std::shared_ptr<SuccessfulPayment>;

#endif  // INCLUDE_SQBOT_API_SUCCESSFULPAYMENT_SUCCESSFUL_PAYMENT_H_
