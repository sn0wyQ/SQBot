#ifndef INLINE_KEYBOARD_MARKUP_H_
#define INLINE_KEYBOARD_MARKUP_H_

#include <memory>
#include <vector>

#include "json.h"

#include "../InlineKeyboardButton/inline_keyboard_button.h"

// This object represents an inline keyboard
// that appears right next to the message it belongs to
class InlineKeyboardMarkup {
 public:
  InlineKeyboardMarkup() = default;
  explicit InlineKeyboardMarkup(const Json& inline_keyboard_markup);

  // Array of button rows, each represented by an Array
  // of InlineKeyboardButton objects
  std::vector<std::vector<std::shared_ptr<InlineKeyboardButton>>>
      inline_keyboard;
};

#endif  // INLINE_KEYBOARD_MARKUP_H_
