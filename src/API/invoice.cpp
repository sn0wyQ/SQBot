#include "../../include/SQBot/API/invoice.h"

Invoice::Invoice(const Json& invoice)
  : title(SQBot::Utils::GetValue<std::string>(invoice, "title")),
    description(SQBot::Utils::GetValue<std::string>(invoice, "description")),
    start_parameter(SQBot::Utils::GetValue<std::string>(
        invoice, "start_parameter")),
    currency(SQBot::Utils::GetValue<std::string>(invoice, "currency")),
    total_amount(SQBot::Utils::GetValue<int32_t>(invoice, "total_amount")) {}
