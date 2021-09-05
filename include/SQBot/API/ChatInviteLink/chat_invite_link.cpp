#include "chat_invite_link.h"

ChatInviteLink::ChatInviteLink(const Json& chat_invite_link)
  : invite_link(Utils::GetValue<std::string>(chat_invite_link, "invite_link")),
    creator(Utils::GetPtr<User>(chat_invite_link, "creator")),
    is_primary(Utils::GetValue<bool>(chat_invite_link, "is_primary")),
    is_revoked(Utils::GetValue<bool>(chat_invite_link, "is_revoked")),
    expire_date(Utils::GetValue<int32_t>(chat_invite_link, "expire_date")),
    member_limit(Utils::GetValue<int32_t>(chat_invite_link, "member_limit")) {}
