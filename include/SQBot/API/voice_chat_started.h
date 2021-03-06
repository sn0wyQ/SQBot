#ifndef INCLUDE_SQBOT_API_VOICE_CHAT_STARTED_H_
#define INCLUDE_SQBOT_API_VOICE_CHAT_STARTED_H_

#include <memory>

#include "../../nlohmann/json.h"

// This object represents a service message about a voice chat started
// in the chat. Currently holds no information
class VoiceChatStarted {
 public:
  VoiceChatStarted() = default;
  explicit VoiceChatStarted(const Json& voice_chat_started);
};

using VoiceChatStartedPtr = std::shared_ptr<VoiceChatStarted>;

#endif  // INCLUDE_SQBOT_API_VOICE_CHAT_STARTED_H_
