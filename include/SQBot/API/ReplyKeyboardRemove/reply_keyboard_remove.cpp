#include "reply_keyboard_remove.h"

ReplyKeyboardRemove::ReplyKeyboardRemove(const Json& reply_keyboard_remove)
  : selective(Utils::GetValue<bool>(reply_keyboard_remove, "selective")) {}

Json ReplyKeyboardRemove::ToJson() const {
  Json reply_keyboard_remove;
  reply_keyboard_remove["remove_keyboard"] = remove_keyboard;
  if (selective) {
    reply_keyboard_remove["selective"] = selective;
  }
  return reply_keyboard_remove;
}
