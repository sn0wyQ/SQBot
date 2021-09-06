#ifndef INCLUDE_SQBOT_API_INLINEKEYBOARDBUTTON_INLINE_KEYBOARD_BUTTON_H_
#define INCLUDE_SQBOT_API_INLINEKEYBOARDBUTTON_INLINE_KEYBOARD_BUTTON_H_

#include <memory>
#include <string>

#include "../../../nlohmann/json.h"

#include "../../Utils/utils.h"

// This object represents one button of an inline keyboard.
// You MUST use EXACTLY ONE of the optional fields
class InlineKeyboardButton {
 public:
  InlineKeyboardButton() = default;
  explicit InlineKeyboardButton(const Json& inline_keyboard_button);

  // Label text on the button
  std::string text;

  // OPTIONAL. HTTP or tg:// url to be opened when button is pressed
  std::string url;

  // TODO(sn0wyQ): Add LoginUrl class
  // OPTIONAL. An HTTP URL used to automatically authorize the user.
  // Can be used as a replacement for the Telegram Login Widget
  // std::shared_ptr<LoginUrl> login_url;

  // OPTIONAL. Data to be sent in a callback query to the bot
  // when button is pressed, 1-64 bytes
  std::string callback_data;

  // OPTIONAL. If set, pressing the button will prompt the user to select one of
  // their chats, open that chat and insert the bot's username and the specified
  // inline query in the input field. Can be empty, in which case just the bot's
  // username will be inserted.
  // NOTE: This offers an easy way for users to start using your bot in inline
  // mode when they are currently in a private chat with it. Especially useful
  // when combined with switch_pm… actions – in this case the user will be
  // automatically returned to the chat they switched from, skipping the chat
  // selection screen
  std::string switch_inline_query;

  // OPTIONAL. If set, pressing the button will insert the bot's username and
  // the specified inline query in the current chat's input field. Can be empty,
  // in which case only the bot's username will be inserted.
  // This offers a quick way for the user to open your bot in inline mode in the
  // same chat – good for selecting something from multiple options
  std::string switch_inline_query_current_chat;

  // TODO(sn0wyQ): Add CallbackGame class
  // OPTIONAL. Description of the game that will be launched when the user
  // presses the button.
  // NOTE: This type of button MUST always be the first button in the first row
  // std::shared_ptr<CallbackGame> callback_game;

  // Optional. Specify True, to send a Pay button
  // (https://core.telegram.org/bots/api#payments)
  // NOTE: This type of button must always be the first button in the first row
  bool pay{false};
};

#endif  // INCLUDE_SQBOT_API_INLINEKEYBOARDBUTTON_INLINE_KEYBOARD_BUTTON_H_
