#ifndef INCLUDE_SQBOT_API_VOICECHATSCHEDULED_VOICE_CHAT_SCHEDULED_H_
#define INCLUDE_SQBOT_API_VOICECHATSCHEDULED_VOICE_CHAT_SCHEDULED_H_

#include <memory>

#include "../../../nlohmann/json.h"

#include "../../Utils/utils.h"

// This object represents a service message
// about a voice chat scheduled in the chat
class VoiceChatScheduled {
 public:
  VoiceChatScheduled() = default;
  explicit VoiceChatScheduled(const Json& voice_chat_scheduled);

  // Point in time (Unix timestamp) when the voice chat
  // is supposed to be started by a chat administrator
  int32_t start_date;
};

using VoiceChatScheduledPtr = std::shared_ptr<VoiceChatScheduled>;

#endif  // INCLUDE_SQBOT_API_VOICECHATSCHEDULED_VOICE_CHAT_SCHEDULED_H_
