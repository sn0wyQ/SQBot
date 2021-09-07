#include "inline_keyboard_button.h"

InlineKeyboardButton::InlineKeyboardButton(const Json& inline_keyboard_button)
  : text(SQBot::Utils::GetValue<std::string>(inline_keyboard_button, "text")),
    url(SQBot::Utils::GetValue<std::string>(inline_keyboard_button, "url")),
    callback_data(SQBot::Utils::GetValue<std::string>(
        inline_keyboard_button, "callback_data")),
    switch_inline_query(SQBot::Utils::GetValue<std::string>(
        inline_keyboard_button, "switch_inline_query")),
    switch_inline_query_current_chat(SQBot::Utils::GetValue<std::string>(
        inline_keyboard_button, "switch_inline_query_current_chat")),
    pay(SQBot::Utils::GetValue<bool>(inline_keyboard_button, "pay")) {}

Json InlineKeyboardButton::ToJson() const {
  Json inline_keyboard_button;

  inline_keyboard_button["text"] = text;

  if (!url.empty()) {
    inline_keyboard_button["url"] = url;
  }

  if (login_url) {
    inline_keyboard_button["login_url"] = login_url->ToJson();
  }

  if (!callback_data.empty()) {
    inline_keyboard_button["callback_data"] = callback_data;
  }

  if (!switch_inline_query.empty()) {
    inline_keyboard_button["switch_inline_query"] = switch_inline_query;
  }

  if (!switch_inline_query_current_chat.empty()) {
    inline_keyboard_button["switch_inline_query_current_chat"] =
        switch_inline_query_current_chat;
  }

  return inline_keyboard_button;
}
