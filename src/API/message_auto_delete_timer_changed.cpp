#include "../../include/SQBot/API/message_auto_delete_timer_changed.h"

MessageAutoDeleteTimerChanged::MessageAutoDeleteTimerChanged(
    const Json& message_auto_delete_timer_changed)
  : message_auto_delete_time(SQBot::Utils::GetValue<int32_t>(
      message_auto_delete_timer_changed, "message_auto_delete_time")) {}
