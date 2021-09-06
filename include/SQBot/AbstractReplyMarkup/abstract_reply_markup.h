#ifndef INCLUDE_SQBOT_ABSTRACTREPLYMARKUP_ABSTRACT_REPLY_MARKUP_H_
#define INCLUDE_SQBOT_ABSTRACTREPLYMARKUP_ABSTRACT_REPLY_MARKUP_H_

#include "../../nlohmann/json.h"

// Children: InlineKeyboardMarkup
// TODO(sn0wyQ): add ReplyKeyboardMarkup, ReplyKeyboardRemove and ForceReply
class AbstractReplyMarkup {
 public:
  AbstractReplyMarkup() = default;

  virtual Json ToJson() const = 0;
};

#endif  // INCLUDE_SQBOT_ABSTRACTREPLYMARKUP_ABSTRACT_REPLY_MARKUP_H_
