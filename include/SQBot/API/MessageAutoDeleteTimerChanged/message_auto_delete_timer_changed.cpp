#include "message_auto_delete_timer_changed.h"

MessageAutoDeleteTimerChanged::MessageAutoDeleteTimerChanged(
    const Json& message_auto_delete_timer_changed)
  : message_auto_delete_time(
      Utils::GetValue<int32_t>(
          message_auto_delete_timer_changed, "message_auto_delete_time")) {}
