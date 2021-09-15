#include "../../include/SQBot/API/inline_keyboard_markup.h"

InlineKeyboardMarkup::InlineKeyboardMarkup(const Json& inline_keyboard_markup) {
  if (inline_keyboard_markup.contains("inline_keyboard")) {
    const Json& inline_keyboard_json =
        inline_keyboard_markup.at("inline_keyboard");
    for (const auto& row : inline_keyboard_json) {
      std::vector<InlineKeyboardButtonPtr> current_row;
      for (const auto& button : row) {
        current_row.push_back(std::make_shared<InlineKeyboardButton>(button));
      }
      inline_keyboard.push_back(std::move(current_row));
    }
  }
}

Json InlineKeyboardMarkup::ToJson() const {
  Json inline_keyboard_markup;

  Json inline_keyboard_json;
  for (const auto& row : inline_keyboard) {
    Json current_row;
    for (const auto& button : row) {
      current_row.push_back(button->ToJson());
    }
    inline_keyboard_json.push_back(current_row);
  }
  inline_keyboard_markup["inline_keyboard"] = inline_keyboard_json;

  return inline_keyboard_markup;
}
