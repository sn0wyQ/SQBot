#include "../../include/SQBot/API/keyboard_button_poll_type.h"

KeyboardButtonPollType::KeyboardButtonPollType(
    const Json& keyboard_button_poll_type)
  : type(SQBot::Utils::GetValue<std::string>(
        keyboard_button_poll_type, "type")) {}

Json KeyboardButtonPollType::ToJson() const {
  Json keyboard_button_poll_type;

  if (!type.empty()) {
    keyboard_button_poll_type["type"] = type;
  }

  return keyboard_button_poll_type;
}
