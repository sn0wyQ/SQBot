#include "../../include/SQBot/API/voice_chat_ended.h"

VoiceChatEnded::VoiceChatEnded(const Json& voice_chat_ended)
  : duration(SQBot::Utils::GetValue<int32_t>(voice_chat_ended, "duration")) {}
