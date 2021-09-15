#ifndef INCLUDE_SQBOT_API_CHATMEMBER_CHAT_MEMBER_H_
#define INCLUDE_SQBOT_API_CHATMEMBER_CHAT_MEMBER_H_

#include <memory>
#include <string>

#include "../../nlohmann/json.h"

#include "user.h"

#include "../Utils/utils.h"

// This object contains information about one member of a chat.
// Currently, the following 6 types of chat members are supported:
// - ChatMemberOwner
// - ChatMemberAdministrator
// - ChatMemberMember
// - ChatMemberRestricted
// - ChatMemberLeft
// - ChatMemberBanned
class ChatMember {
 public:
  ChatMember() = default;
  explicit ChatMember(const Json& chat_member);

  // The member's status in the chat, always “creator”
  std::string status;

  // Information about the user
  UserPtr user;

  // True, if the user's presence in the chat is hidden
  bool is_anonymous{false};

  // OPTIONAL. Custom title for this user
  std::string custom_title;
};

using ChatMemberPtr = std::shared_ptr<ChatMember>;

#endif  // INCLUDE_SQBOT_API_CHATMEMBER_CHAT_MEMBER_H_
