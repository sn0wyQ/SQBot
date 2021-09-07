#include "chat_member.h"

ChatMember::ChatMember(const Json& chat_member)
  : status(SQBot::Utils::GetValue<std::string>(chat_member, "status")),
    user(SQBot::Utils::GetPtr<User>(chat_member, "user")),
    is_anonymous(SQBot::Utils::GetValue<bool>(chat_member, "is_anonymous")),
    custom_title(SQBot::Utils::GetValue<std::string>(chat_member, "custom_title")) {}
