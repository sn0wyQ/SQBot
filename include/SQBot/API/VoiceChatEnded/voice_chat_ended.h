#ifndef VOICE_CHAT_ENDED_H_
#define VOICE_CHAT_ENDED_H_

#include "json.h"

#include "../../Utils/utils.h"

// This object represents a service message about a voice chat ended in the chat
class VoiceChatEnded {
 public:
  VoiceChatEnded() = default;
  explicit VoiceChatEnded(const Json& voice_chat_ended);

  // Voice chat duration; in seconds
  int32_t duration;
};

#endif  // VOICE_CHAT_ENDED_H_
