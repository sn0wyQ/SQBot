#include "../../include/SQBot/API/update.h"

Update::Update(const Json& update)
  : update_id(SQBot::Utils::GetValue<int32_t>(update, "update_id")),
    message(SQBot::Utils::GetPtr<Message>(update, "message")),
    edited_message(SQBot::Utils::GetPtr<Message>(update, "edited_message")),
    channel_post(SQBot::Utils::GetPtr<Message>(update, "channel_post")),
    edited_channel_post(SQBot::Utils::GetPtr<Message>(
        update, "edited_channel_post")),
    inline_query(SQBot::Utils::GetPtr<InlineQuery>(update, "inline_query")),
    chosen_inline_result(SQBot::Utils::GetPtr<ChosenInlineResult>(
        update, "chosen_inline_result")),
    callback_query(SQBot::Utils::GetPtr<CallbackQuery>(
        update, "callback_query")),
    shipping_query(SQBot::Utils::GetPtr<ShippingQuery>(
        update, "shipping_query")),
    pre_checkout_query(SQBot::Utils::GetPtr<PreCheckoutQuery>(
        update, "pre_checkout_query")),
    poll(SQBot::Utils::GetPtr<Poll>(update, "poll")),
    poll_answer(SQBot::Utils::GetPtr<PollAnswer>(update, "poll_answer")),
    my_chat_member(SQBot::Utils::GetPtr<ChatMemberUpdated>(
        update, "my_chat_member")),
    chat_member(SQBot::Utils::GetPtr<ChatMemberUpdated>(
        update, "chat_member")) {}
