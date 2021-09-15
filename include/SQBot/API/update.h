#ifndef INCLUDE_SQBOT_API_UPDATE_UPDATE_H_
#define INCLUDE_SQBOT_API_UPDATE_UPDATE_H_

#include <memory>

#include "../../nlohmann/json.h"

#include "callback_query.h"
#include "chat_member_updated.h"
#include "chosen_inline_result.h"
#include "message.h"
#include "inline_query.h"
#include "poll_answer.h"
#include "poll.h"
#include "pre_checkout_query.h"
#include "shipping_query.h"

#include "../Utils/utils.h"

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

  // OPTIONAL. New incoming message of any kind — text, photo, sticker, etc.
  MessagePtr message;

  // OPTIONAL. New version of a message that is known to the bot and was edited
  MessagePtr edited_message;

  // OPTIONAL. New incoming channel post of any kind —
  // text, photo, sticker, etc.
  MessagePtr channel_post;

  // OPTIONAL. New version of a channel post that is known to the bot
  // and was edited
  MessagePtr edited_channel_post;

  // OPTIONAL. New incoming inline query
  InlineQueryPtr inline_query;

  // OPTIONAL. The result of an inline query that was chosen by a user
  // and sent to their chat partner. Please see our documentation on the
  // feedback collecting for details on how to enable these updates for your bot
  ChosenInlineResultPtr chosen_inline_result;

  // OPTIONAL. New incoming callback query
  CallbackQueryPtr callback_query;

  // OPTIONAL. New incoming shipping query.
  // Only for invoices with flexible price
  ShippingQueryPtr shipping_query;

  // OPTIONAL. New incoming pre-checkout query.
  // Contains full information about checkout
  PreCheckoutQueryPtr pre_checkout_query;

  // OPTIONAL. New poll state. Bots receive only updates about stopped polls
  // and polls, which are sent by the bot
  PollPtr poll;

  // OPTIONAL. A user changed their answer in a non-anonymous poll.
  // Bots receive new votes only in polls that were sent by the bot itself
  PollAnswerPtr poll_answer;

  // OPTIONAL. The bot's chat member status was updated in a chat. For private
  // chats, this update is received only when the bot is blocked
  // or unblocked by the user
  ChatMemberUpdatedPtr my_chat_member;

  // OPTIONAL. A chat member's status was updated in a chat.
  // The bot must be an administrator in the chat and must explicitly
  // specify “chat_member” in the list of allowed_updates
  // to receive these updates
  ChatMemberUpdatedPtr chat_member;
};

using UpdatePtr = std::shared_ptr<Update>;

#endif  // INCLUDE_SQBOT_API_UPDATE_UPDATE_H_
