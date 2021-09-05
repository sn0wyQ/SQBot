#include "invoice.h"

Invoice::Invoice(const Json& invoice)
  : title(Utils::GetValue<std::string>(invoice, "title")),
    description(Utils::GetValue<std::string>(invoice, "description")),
    start_parameter(Utils::GetValue<std::string>(invoice, "start_parameter")),
    currency(Utils::GetValue<std::string>(invoice, "currency")),
    total_amount(Utils::GetValue<int32_t>(invoice, "total_amount")) {}
