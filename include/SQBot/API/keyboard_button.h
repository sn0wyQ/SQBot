#ifndef INCLUDE_SQBOT_API_KEYBOARD_BUTTON_H_
#define INCLUDE_SQBOT_API_KEYBOARD_BUTTON_H_

#include <memory>
#include <string>

#include "../../nlohmann/json.h"

#include "keyboard_button_poll_type.h"

#include "../Utils/utils.h"

// This object represents one button of the reply keyboard. For simple text
// buttons String can be used instead of this object to specify text of the
// button. Optional fields request_contact, request_location, and request_poll
// are mutually exclusive
class KeyboardButton {
 public:
  KeyboardButton() = default;
  explicit KeyboardButton(const Json& keyboard_button);

  Json ToJson() const;

  // Text of the button. If none of the optional fields are used,
  // it will be sent as a message when the button is pressed
  std::string text;

  // OPTIONAL. If True, the user's phone number will be sent as a contact
  // when the button is pressed. Available in private chats only
  bool request_contact{false};

  // OPTIONAL. If True, the user's current location will be sent when the button
  // is pressed. Available in private chats only
  bool request_location{false};

  // OPTIONAL. If specified, the user will be asked to create a poll and send it
  // to the bot when the button is pressed. Available in private chats only.
  // NOTE: this option will only work in Telegram versions released
  // after 23 January 2020. Older clients will display unsupported message
  KeyboardButtonPollTypePtr request_poll;
};

using KeyboardButtonPtr = std::shared_ptr<KeyboardButton>;

#endif  // INCLUDE_SQBOT_API_KEYBOARD_BUTTON_H_
