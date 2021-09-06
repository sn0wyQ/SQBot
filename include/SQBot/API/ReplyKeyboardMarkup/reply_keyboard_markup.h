#ifndef INCLUDE_SQBOT_API_REPLYKEYBOARDMARKUP_REPLY_KEYBOARD_MARKUP_H_
#define INCLUDE_SQBOT_API_REPLYKEYBOARDMARKUP_REPLY_KEYBOARD_MARKUP_H_

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "../../../nlohmann/json.h"

#include "../KeyboardButton/keyboard_button.h"

#include "../../AbstractReplyMarkup/abstract_reply_markup.h"
#include "../../Utils/utils.h"

// This object represents a custom keyboard with reply options
// (see Introduction to bots for details and examples)
class ReplyKeyboardMarkup : public AbstractReplyMarkup {
 public:
  ReplyKeyboardMarkup() = default;
  explicit ReplyKeyboardMarkup(const Json& reply_keyboard_markup);

  Json ToJson() const override;

  // Array of button rows, each represented by
  // an Array of KeyboardButton objects
  std::vector<std::vector<KeyboardButtonPtr>> keyboard;

  // OPTIONAL. Requests clients to resize the keyboard vertically for optimal
  // fit (e.g., make the keyboard smaller if there are just two rows of
  // buttons). Defaults to false, in which case the custom keyboard is always of
  // the same height as the app's standard keyboard
  bool resize_keyboard{false};

  // OPTIONAL. Requests clients to hide the keyboard as soon as it's been used.
  // The keyboard will still be available, but clients will automatically
  // display the usual letter-keyboard in the chat – the user can press a
  // special button in the input field to see the custom keyboard again.
  // Defaults to false
  bool one_time_keyboard{false};

  // OPTIONAL. The placeholder to be shown in the input field when
  // the keyboard is active; 1-64 characters
  std::string input_field_placeholder;

  // OPTIONAL. Use this parameter if you want to show the keyboard to specific
  // users only. Targets: 1) users that are @mentioned in the text of the
  // Message object; 2) if the bot's message is a reply
  // (has reply_to_message_id), sender of the original message.
  // EXAMPLE: A user requests to change the bot's language, bot replies to the
  // request with a keyboard to select the new language. Other users in the
  // group don't see the keyboard
  bool selective{false};
};

using ReplyKeyboardMarkupPtr = std::shared_ptr<ReplyKeyboardMarkup>;

#endif  // INCLUDE_SQBOT_API_REPLYKEYBOARDMARKUP_REPLY_KEYBOARD_MARKUP_H_
