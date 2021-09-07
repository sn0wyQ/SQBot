#include "message_id.h"

MessageId::MessageId(const Json& message_id)
  : message_id(SQBot::Utils::GetValue<int32_t>(message_id, "message_id")) {}
