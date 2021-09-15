#include "../../include/SQBot/API/voice_chat_participants_invited.h"

VoiceChatParticipantsInvited::VoiceChatParticipantsInvited(
    const Json& voice_chat_participants_invited)
  : users(SQBot::Utils::GetPtrsArray<User>(
      voice_chat_participants_invited, "users")) {}
