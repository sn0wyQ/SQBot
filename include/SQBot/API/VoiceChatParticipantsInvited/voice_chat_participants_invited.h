#ifndef VOICE_CHAT_PARTICIPANTS_INVITED_H_
#define VOICE_CHAT_PARTICIPANTS_INVITED_H_

#include <memory>
#include <vector>

#include "json.h"

#include "../User/user.h"

#include "../../Utils/utils.h"

// This object represents a service message
// about new members invited to a voice chat
class VoiceChatParticipantsInvited {
 public:
  VoiceChatParticipantsInvited() = default;
  explicit VoiceChatParticipantsInvited(
      const Json& voice_chat_participants_invited);

  // OPTIONAL. New members that were invited to the voice chat
  std::vector<std::shared_ptr<User>> users;
};

#endif  // VOICE_CHAT_PARTICIPANTS_INVITED_H_
