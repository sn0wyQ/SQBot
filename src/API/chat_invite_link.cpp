#include "../../include/SQBot/API/chat_invite_link.h"

ChatInviteLink::ChatInviteLink(const Json& chat_invite_link)
  : invite_link(SQBot::Utils::GetValue<std::string>(
        chat_invite_link, "invite_link")),
    creator(SQBot::Utils::GetPtr<User>(chat_invite_link, "creator")),
    is_primary(SQBot::Utils::GetValue<bool>(chat_invite_link, "is_primary")),
    is_revoked(SQBot::Utils::GetValue<bool>(chat_invite_link, "is_revoked")),
    expire_date(SQBot::Utils::GetValue<int32_t>(
        chat_invite_link, "expire_date")),
    member_limit(SQBot::Utils::GetValue<int32_t>(
        chat_invite_link, "member_limit")) {}
