#ifndef INCLUDE_SQBOT_API_INVOICE_INVOICE_H_
#define INCLUDE_SQBOT_API_INVOICE_INVOICE_H_

#include <string>

#include "../../../nlohmann/json.h"

#include "../../Utils/utils.h"

// This object contains basic information about an invoice
class Invoice {
 public:
  Invoice() = default;
  explicit Invoice(const Json& invoice);

  // Product name
  std::string title;

  // Product description
  std::string description;

  // Unique bot deep-linking parameter that can be used to generate this invoice
  std::string start_parameter;

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
};

#endif  // INCLUDE_SQBOT_API_INVOICE_INVOICE_H_
