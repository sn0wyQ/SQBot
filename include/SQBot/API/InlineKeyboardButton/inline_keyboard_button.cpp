#include "inline_keyboard_button.h"

InlineKeyboardButton::InlineKeyboardButton(const Json& inline_keyboard_button)
  : text(Utils::GetValue<std::string>(inline_keyboard_button, "text")),
    url(Utils::GetValue<std::string>(inline_keyboard_button, "url")),
    callback_data(
        Utils::GetValue<std::string>(inline_keyboard_button, "callback_data")),
    switch_inline_query(Utils::GetValue<std::string>(
        inline_keyboard_button, "switch_inline_query")),
    switch_inline_query_current_chat(Utils::GetValue<std::string>(
        inline_keyboard_button, "switch_inline_query_current_chat")),
    pay(Utils::GetValue<bool>(inline_keyboard_button, "pay")) {}
