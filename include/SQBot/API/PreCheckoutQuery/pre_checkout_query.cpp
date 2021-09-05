#include "pre_checkout_query.h"

PreCheckoutQuery::PreCheckoutQuery(const Json& pre_checkout_query)
  : id(Utils::GetValue<std::string>(pre_checkout_query, "id")),
    from(Utils::GetPtr<User>(pre_checkout_query, "from")),
    currency(Utils::GetValue<std::string>(pre_checkout_query, "currency")),
    total_amount(Utils::GetValue<int32_t>(pre_checkout_query, "total_amount")),
    invoice_payload(
        Utils::GetValue<std::string>(pre_checkout_query, "invoice_payload")),
    shipping_option_id(
        Utils::GetValue<std::string>(pre_checkout_query, "shipping_option_id")),
    order_info(Utils::GetPtr<OrderInfo>(pre_checkout_query, "order_info")) {}
