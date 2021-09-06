#ifndef INCLUDE_SQBOT_ABSTRACTREPLYMARKUP_ABSTRACT_REPLY_MARKUP_H_
#define INCLUDE_SQBOT_ABSTRACTREPLYMARKUP_ABSTRACT_REPLY_MARKUP_H_

#include <memory>

#include "../../nlohmann/json.h"

// Children: InlineKeyboardMarkup, ReplyKeyboardMarkup,
// ReplyKeyboardRemove and ForceReply
class AbstractReplyMarkup {
 public:
  AbstractReplyMarkup() = default;

  virtual Json ToJson() const = 0;
};

using AbstractReplyMarkupPtr = std::shared_ptr<AbstractReplyMarkup>;

#endif  // INCLUDE_SQBOT_ABSTRACTREPLYMARKUP_ABSTRACT_REPLY_MARKUP_H_
