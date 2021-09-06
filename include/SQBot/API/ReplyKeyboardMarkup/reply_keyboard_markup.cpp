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
  Json reply_keyboard_markup;

  Json reply_keyboard_json;
  for (const auto& row : keyboard) {
    Json current_row;
    for (const auto& button : row) {
      current_row.push_back(button->ToJson());
    }
    reply_keyboard_json.push_back(std::move(current_row));
  }
  reply_keyboard_markup["keyboard"] = reply_keyboard_json;

  if (resize_keyboard) {
    reply_keyboard_markup["resize_keyboard"] = resize_keyboard;
  }

  if (one_time_keyboard) {
    reply_keyboard_markup["one_time_keyboard"] = one_time_keyboard;
  }

  if (!input_field_placeholder.empty()) {
    reply_keyboard_markup["input_field_placeholder"] = input_field_placeholder;
  }

  if (selective) {
    reply_keyboard_markup["selective"] = selective;
  }

  return reply_keyboard_markup;
}
