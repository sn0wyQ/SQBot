#include "../../include/SQBot/API/voice_chat_scheduled.h"

VoiceChatScheduled::VoiceChatScheduled(const Json& voice_chat_scheduled)
  : start_date(SQBot::Utils::GetValue<int32_t>(
        voice_chat_scheduled, "start_date")) {}
