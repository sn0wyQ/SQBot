#include "keyboard_button.h"

KeyboardButton::KeyboardButton(const Json& keyboard_button)
  : text(SQBot::Utils::GetValue<std::string>(keyboard_button, "text")),
    request_contact(SQBot::Utils::GetValue<bool>(
        keyboard_button, "request_contact")),
    request_location(SQBot::Utils::GetValue<bool>(
        keyboard_button, "request_location")),
    request_poll(SQBot::Utils::GetPtr<KeyboardButtonPollType>(
        keyboard_button, "request_poll")) {}

Json KeyboardButton::ToJson() const {
  Json keyboard_button;

  keyboard_button["text"] = text;

  if (request_contact) {
    keyboard_button["request_contact"] = request_contact;
  }

  if (request_location) {
    keyboard_button["request_location"] = request_location;
  }

  if (request_poll) {
    keyboard_button["request_poll"] = request_poll->ToJson();
  }

  return keyboard_button;
}
