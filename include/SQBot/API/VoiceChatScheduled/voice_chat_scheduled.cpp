#include "voice_chat_scheduled.h"

VoiceChatScheduled::VoiceChatScheduled(const Json& voice_chat_scheduled)
  : start_date(Utils::GetValue<int32_t>(voice_chat_scheduled, "start_date")) {}
