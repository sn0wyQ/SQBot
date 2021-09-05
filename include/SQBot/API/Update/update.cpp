#include "update.h"

Update::Update(const Json& update)
  : update_id(Utils::GetValue<int32_t>(update, "update_id")),
    message(Utils::GetPtr<Message>(update, "message")),
    edited_message(Utils::GetPtr<Message>(update, "edited_message")),
    channel_post(Utils::GetPtr<Message>(update, "channel_post")),
    edited_channel_post(Utils::GetPtr<Message>(update, "edited_channel_post")),
    inline_query(Utils::GetPtr<InlineQuery>(update, "inline_query")),
    chosen_inline_result(Utils::GetPtr<ChosenInlineResult>(update, "chosen_inline_result")),
    callback_query(Utils::GetPtr<CallbackQuery>(update, "callback_query")),
    shipping_query(Utils::GetPtr<ShippingQuery>(update, "shipping_query")),
    pre_checkout_query(Utils::GetPtr<PreCheckoutQuery>(update, "pre_checkout_query")),
    poll(Utils::GetPtr<Poll>(update, "poll")),
    poll_answer(Utils::GetPtr<PollAnswer>(update, "poll_answer")),
    my_chat_member(Utils::GetPtr<ChatMemberUpdated>(update, "my_chat_member")),
    chat_member(Utils::GetPtr<ChatMemberUpdated>(update, "chat_member")) {}
