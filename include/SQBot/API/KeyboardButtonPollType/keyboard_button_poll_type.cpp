#include "keyboard_button_poll_type.h"

KeyboardButtonPollType::KeyboardButtonPollType(
    const Json& keyboard_button_poll_type)
  : type(Utils::GetValue<std::string>(keyboard_button_poll_type, "type")) {}
