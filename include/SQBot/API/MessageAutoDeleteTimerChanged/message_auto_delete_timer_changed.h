#ifndef MESSAGE_AUTO_DELETE_TIMER_CHANGED_H_
#define MESSAGE_AUTO_DELETE_TIMER_CHANGED_H_

#include "json.h"

#include "../../Utils/utils.h"

// This object represents a service message about a change
// in auto-delete timer settings
class MessageAutoDeleteTimerChanged {
 public:
  MessageAutoDeleteTimerChanged() = default;
  explicit MessageAutoDeleteTimerChanged(
      const Json& message_auto_delete_timer_changed);

  // New auto-delete time for messages in the chat
  int32_t message_auto_delete_time{};
};

#endif  // MESSAGE_AUTO_DELETE_TIMER_CHANGED_H_
