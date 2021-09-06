#include "voice_chat_participants_invited.h"

VoiceChatParticipantsInvited::VoiceChatParticipantsInvited(
    const Json& voice_chat_participants_invited)
  : users(Utils::GetPtrsArray<User>(
      voice_chat_participants_invited, "users")) {}
