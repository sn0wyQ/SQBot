#include "reply_keyboard_markup.h"

ReplyKeyboardMarkup::ReplyKeyboardMarkup(const Json& reply_keyboard_markup)
  : resize_keyboard(
      Utils::GetValue<bool>(reply_keyboard_markup, "resize_keyboard")),
    one_time_keyboard(
        Utils::GetValue<bool>(reply_keyboard_markup, "resize_keyboard")),
    input_field_placeholder(
        Utils::GetValue<std::string>(
            reply_keyboard_markup, "input_field_placeholder")),
    selective(Utils::GetValue<bool>(reply_keyboard_markup, "selective")) {
  if (reply_keyboard_markup.contains("keyboard")) {
    const Json& keyboard_json = reply_keyboard_markup.at("keyboard");
    for (const auto& row : keyboard_json) {
      std::vector<KeyboardButtonPtr> current_row;
      for (const auto& button : row) {
        current_row.push_back(std::make_shared<KeyboardButton>(button));
      }
      keyboard.push_back(std::move(current_row));
    }
  }
}

Json ReplyKeyboardMarkup::ToJson() const {
  // TODO(sn0wyQ): finish this
  return {};
}
