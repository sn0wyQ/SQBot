#ifndef KEYBOARD_BUTTON_POLL_TYPE_H_
#define KEYBOARD_BUTTON_POLL_TYPE_H_

#include <memory>
#include <string>

#include "../../../nlohmann/json.h"

#include "../../Utils/utils.h"

// This object represents a type of poll, which is allowed to be created and
// sent when the corresponding button is pressed
class KeyboardButtonPollType {
 public:
  KeyboardButtonPollType() = default;
  explicit KeyboardButtonPollType(const Json& keyboard_button_poll_type);

  // OPTIONAL. If quiz is passed, the user will be allowed to create only polls
  // in the quiz mode. If regular is passed, only regular polls will be allowed.
  // Otherwise, the user will be allowed to create a poll of any type
  std::string type;
};

using KeyboardButtonPollTypePtr = std::shared_ptr<KeyboardButtonPollType>;

#endif  // KEYBOARD_BUTTON_POLL_TYPE_H_
