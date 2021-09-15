#include "../../include/SQBot/API/pre_checkout_query.h"

PreCheckoutQuery::PreCheckoutQuery(const Json& pre_checkout_query)
  : id(SQBot::Utils::GetValue<std::string>(pre_checkout_query, "id")),
    from(SQBot::Utils::GetPtr<User>(pre_checkout_query, "from")),
    currency(SQBot::Utils::GetValue<std::string>(
        pre_checkout_query, "currency")),
    total_amount(SQBot::Utils::GetValue<int32_t>(
        pre_checkout_query, "total_amount")),
    invoice_payload(SQBot::Utils::GetValue<std::string>(
        pre_checkout_query, "invoice_payload")),
    shipping_option_id(SQBot::Utils::GetValue<std::string>(
        pre_checkout_query, "shipping_option_id")),
    order_info(SQBot::Utils::GetPtr<OrderInfo>(
        pre_checkout_query, "order_info")) {}
