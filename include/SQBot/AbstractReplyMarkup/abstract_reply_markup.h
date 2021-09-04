#ifndef ABSTRACT_REPLY_H_
#define ABSTRACT_REPLY_H_

#include "json.h"

// Children: InlineKeyboardMarkup
// TODO(sn0wyQ): add ReplyKeyboardMarkup, ReplyKeyboardRemove and ForceReply
class AbstractReplyMarkup {
 public:
  AbstractReplyMarkup() = default;

  virtual Json ToJson() const = 0;
};

#endif  // ABSTRACT_REPLY_H_
