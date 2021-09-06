#ifndef INCLUDE_SQBOT_API_INLINEKEYBOARDMARKUP_INLINE_KEYBOARD_MARKUP_H_
#define INCLUDE_SQBOT_API_INLINEKEYBOARDMARKUP_INLINE_KEYBOARD_MARKUP_H_

#include <memory>
#include <utility>
#include <vector>

#include "../../../nlohmann/json.h"

#include "../InlineKeyboardButton/inline_keyboard_button.h"

#include "../../AbstractReplyMarkup/abstract_reply_markup.h"

// This object represents an inline keyboard
// that appears right next to the message it belongs to
class InlineKeyboardMarkup : public AbstractReplyMarkup {
 public:
  InlineKeyboardMarkup() = default;
  explicit InlineKeyboardMarkup(const Json& inline_keyboard_markup);

  Json ToJson() const override;

  // Array of button rows, each represented by an Array
  // of InlineKeyboardButton objects
  std::vector<std::vector<std::shared_ptr<InlineKeyboardButton>>>
      inline_keyboard;
};

#endif  // INCLUDE_SQBOT_API_INLINEKEYBOARDMARKUP_INLINE_KEYBOARD_MARKUP_H_
