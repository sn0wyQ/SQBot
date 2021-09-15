#ifndef INCLUDE_SQBOT_API_CHATINVITELINK_CHAT_INVITE_LINK_H_
#define INCLUDE_SQBOT_API_CHATINVITELINK_CHAT_INVITE_LINK_H_

#include <memory>
#include <string>

#include "../../nlohmann/json.h"

#include "user.h"

#include "../Utils/utils.h"

// Represents an invite link for a chat
class ChatInviteLink {
 public:
  ChatInviteLink() = default;
  explicit ChatInviteLink(const Json& chat_invite_link);

  // The invite link. If the link was created by another chat administrator,
  // then the second part of the link will be replaced with "..."
  std::string invite_link;

  // Creator of the link
  UserPtr creator;

  // True, if the link is primary
  bool is_primary{false};

  // True, if the link is revoked
  bool is_revoked{false};

  // OPTIONAL. Point in time (Unix timestamp) when the link
  // will expire or has been expired
  int32_t expire_date{};

  // OPTIONAL. Maximum number of users that can be members of the chat
  // simultaneously after joining the chat via this invite link; 1-99999
  int32_t member_limit{};
};

using ChatInviteLinkPtr = std::shared_ptr<ChatInviteLink>;

#endif  // INCLUDE_SQBOT_API_CHATINVITELINK_CHAT_INVITE_LINK_H_
