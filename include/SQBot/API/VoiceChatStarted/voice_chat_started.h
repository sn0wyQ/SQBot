#ifndef VOICE_CHAT_STARTED_H_
#define VOICE_CHAT_STARTED_H_

#include "json.h"

// This object represents a service message about a voice chat started
// in the chat. Currently holds no information
class VoiceChatStarted {
 public:
  VoiceChatStarted() = default;
  explicit VoiceChatStarted(const Json& voice_chat_started);
};

#endif  // VOICE_CHAT_STARTED_H_
