#ifndef INCLUDE_SQBOT_API_CHATMEMBERUPDATED_CHAT_MEMBER_UPDATED_H_
#define INCLUDE_SQBOT_API_CHATMEMBERUPDATED_CHAT_MEMBER_UPDATED_H_

#include <memory>

#include "../../../nlohmann/json.h"

#include "../ChatInviteLink/chat_invite_link.h"
#include "../ChatMember/chat_member.h"
#include "../Chat/chat.h"
#include "../User/user.h"

#include "../../Utils/utils.h"

// This object represents changes in the status of a chat member
class ChatMemberUpdated {
 public:
  ChatMemberUpdated() = default;
  explicit ChatMemberUpdated(const Json& chat_member_updated);

  ChatPtr chat;

  // Performer of the action, which resulted in the change
  UserPtr from;

  // Date the change was done in Unix time
  int32_t date{};

  // Previous information about the chat member
  ChatMemberPtr old_chat_member;

  // New information about the chat member
  ChatMemberPtr new_chat_member;

  // OPTIONAL. Chat invite link, which was used by the user to join the chat;
  // for joining by invite link events only
  ChatInviteLinkPtr invite_link;
};

using ChatMemberUpdatedPtr = std::shared_ptr<ChatMemberUpdated>;

#endif  // INCLUDE_SQBOT_API_CHATMEMBERUPDATED_CHAT_MEMBER_UPDATED_H_
