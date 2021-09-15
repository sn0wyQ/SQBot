#ifndef INCLUDE_SQBOT_API_REPLYKEYBOARDREMOVE_REPLY_KEYBOARD_REMOVE_H_
#define INCLUDE_SQBOT_API_REPLYKEYBOARDREMOVE_REPLY_KEYBOARD_REMOVE_H_

#include <memory>

#include "../../nlohmann/json.h"

#include "../AbstractReplyMarkup/abstract_reply_markup.h"
#include "../Utils/utils.h"

// Upon receiving a message with this object, Telegram clients will remove the
// current custom keyboard and display the default letter-keyboard. By default,
// custom keyboards are displayed until a new keyboard is sent by a bot.
// An exception is made for one-time keyboards that are hidden immediately
// after the user presses a button (see ReplyKeyboardMarkup)
class ReplyKeyboardRemove : public AbstractReplyMarkup {
 public:
  ReplyKeyboardRemove() = default;
  explicit ReplyKeyboardRemove(const Json& reply_keyboard_remove);

  Json ToJson() const override;

  // Requests clients to remove the custom keyboard(user will not be able to
  // summon this keyboard; if you want to hide the keyboard from sight but
  // keep it accessible, use one_time_keyboard in ReplyKeyboardMarkup)
  const bool remove_keyboard{true};

  // OPTIONAL. Use this parameter if you want to show the keyboard to specific
  // users only. Targets: 1) users that are @mentioned in the text of the
  // Message object; 2) if the bot's message is a reply
  // (has reply_to_message_id), sender of the original message.
  // EXAMPLE: A user requests to change the bot's language, bot replies to the
  // request with a keyboard to select the new language. Other users in the
  // group don't see the keyboard
  bool selective{false};
};

using ReplyKeyboardRemovePtr = std::shared_ptr<ReplyKeyboardRemove>;

#endif  // INCLUDE_SQBOT_API_REPLYKEYBOARDREMOVE_REPLY_KEYBOARD_REMOVE_H_
