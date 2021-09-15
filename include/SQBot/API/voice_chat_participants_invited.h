#ifndef INCLUDE_SQBOT_API_VOICE_CHAT_PARTICIPANTS_INVITED_H_
#define INCLUDE_SQBOT_API_VOICE_CHAT_PARTICIPANTS_INVITED_H_

#include <memory>
#include <vector>

#include "../../nlohmann/json.h"

#include "user.h"

#include "../Utils/utils.h"

// This object represents a service message
// about new members invited to a voice chat
class VoiceChatParticipantsInvited {
 public:
  VoiceChatParticipantsInvited() = default;
  explicit VoiceChatParticipantsInvited(
      const Json& voice_chat_participants_invited);

  // OPTIONAL. New members that were invited to the voice chat
  std::vector<UserPtr> users;
};

using VoiceChatParticipantsInvitedPtr =
    std::shared_ptr<VoiceChatParticipantsInvited>;

#endif  // INCLUDE_SQBOT_API_VOICE_CHAT_PARTICIPANTS_INVITED_H_
