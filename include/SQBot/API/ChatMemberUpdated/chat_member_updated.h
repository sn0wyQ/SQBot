#ifndef CHAT_MEMBER_UPDATED_H_
#define CHAT_MEMBER_UPDATED_H_

#include <memory>

#include "json.h"

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

  // Chat the user belongs to
  std::shared_ptr<Chat> chat;

  // Performer of the action, which resulted in the change
  std::shared_ptr<User> from;

  // Date the change was done in Unix time
  int32_t date{};

  // Previous information about the chat member
  std::shared_ptr<ChatMember> old_chat_member;

  // New information about the chat member
  std::shared_ptr<ChatMember> new_chat_member;

  // OPTIONAL. Chat invite link, which was used by the user to join the chat;
  // for joining by invite link events only
  std::shared_ptr<ChatInviteLink> invite_link;
};

#endif  // CHAT_MEMBER_UPDATED_H_
