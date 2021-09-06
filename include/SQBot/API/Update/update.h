#ifndef INCLUDE_SQBOT_API_UPDATE_UPDATE_H_
#define INCLUDE_SQBOT_API_UPDATE_UPDATE_H_

#include <memory>

#include "../../../nlohmann/json.h"

#include "../CallbackQuery/callback_query.h"
#include "../ChatMemberUpdated/chat_member_updated.h"
#include "../ChosenInlineResult/chosen_inline_result.h"
#include "../Message/message.h"
#include "../InlineQuery/inline_query.h"
#include "../PollAnswer/poll_answer.h"
#include "../Poll/poll.h"
#include "../PreCheckoutQuery/pre_checkout_query.h"
#include "../ShippingQuery/shipping_query.h"

#include "../../Utils/utils.h"

// This object represents an incoming update.
// At most ONE of the optional parameters can be present in any given update
class Update {
 public:
  Update() = default;
  explicit Update(const Json& update);

  // The update's unique identifier. Update identifiers start from a certain
  // positive number and increase sequentially.
  // If there are no new updates for at least a week, then identifier of the
  // next update will be chosen randomly instead of sequentially
  int32_t update_id{};

  // Optional. New incoming message of any kind — text, photo, sticker, etc.
  std::shared_ptr<Message> message;

  // Optional. New version of a message that is known to the bot and was edited
  std::shared_ptr<Message> edited_message;

  // Optional. New incoming channel post of any kind —
  // text, photo, sticker, etc.
  std::shared_ptr<Message> channel_post;

  // Optional. New version of a channel post that is known to the bot
  // and was edited
  std::shared_ptr<Message> edited_channel_post;

  // Optional. New incoming inline query
  std::shared_ptr<InlineQuery> inline_query;

  // Optional. The result of an inline query that was chosen by a user
  // and sent to their chat partner. Please see our documentation on the
  // feedback collecting for details on how to enable these updates for your bot
  std::shared_ptr<ChosenInlineResult> chosen_inline_result;

  // Optional. New incoming callback query
  std::shared_ptr<CallbackQuery> callback_query;

  // Optional. New incoming shipping query.
  // Only for invoices with flexible price
  std::shared_ptr<ShippingQuery> shipping_query;

  // Optional. New incoming pre-checkout query.
  // Contains full information about checkout
  std::shared_ptr<PreCheckoutQuery> pre_checkout_query;

  // Optional. New poll state. Bots receive only updates about stopped polls
  // and polls, which are sent by the bot
  std::shared_ptr<Poll> poll;

  // Optional. A user changed their answer in a non-anonymous poll.
  // Bots receive new votes only in polls that were sent by the bot itself
  std::shared_ptr<PollAnswer> poll_answer;

  // Optional. The bot's chat member status was updated in a chat. For private
  // chats, this update is received only when the bot is blocked
  // or unblocked by the user
  std::shared_ptr<ChatMemberUpdated> my_chat_member;

  // Optional. A chat member's status was updated in a chat.
  // The bot must be an administrator in the chat and must explicitly
  // specify “chat_member” in the list of allowed_updates
  // to receive these updates
  std::shared_ptr<ChatMemberUpdated> chat_member;
};

#endif  // INCLUDE_SQBOT_API_UPDATE_UPDATE_H_
