#ifndef INCLUDE_SQBOT_API_VOICECHATENDED_VOICE_CHAT_ENDED_H_
#define INCLUDE_SQBOT_API_VOICECHATENDED_VOICE_CHAT_ENDED_H_

#include <memory>

#include "../../nlohmann/json.h"

#include "../Utils/utils.h"

// This object represents a service message about a voice chat ended in the chat
class VoiceChatEnded {
 public:
  VoiceChatEnded() = default;
  explicit VoiceChatEnded(const Json& voice_chat_ended);

  // Voice chat duration; in seconds
  int32_t duration;
};

using VoiceChatEndedPtr = std::shared_ptr<VoiceChatEnded>;

#endif  // INCLUDE_SQBOT_API_VOICECHATENDED_VOICE_CHAT_ENDED_H_
