#include "successful_payment.h"

SuccessfulPayment::SuccessfulPayment(const Json& successful_payment)
  : currency(Utils::GetValue<std::string>(successful_payment, "currency")),
    total_amount(Utils::GetValue<int32_t>(successful_payment, "total_amount")),
    invoice_payload(
        Utils::GetValue<std::string>(successful_payment, "invoice_payload")),
    shipping_option_id(
        Utils::GetValue<std::string>(successful_payment, "shipping_option_id")),
    order_info(Utils::GetPtr<OrderInfo>(successful_payment, "order_info")),
    telegram_payment_charge_id(
        Utils::GetValue<std::string>(
            successful_payment, "telegram_payment_charge_id")),
    provider_payment_charge_id(
        Utils::GetValue<std::string>(
            successful_payment, "provider_payment_charge_id")) {}
