#include "chat_member.h"

ChatMember::ChatMember(const Json& chat_member)
  : status(Utils::GetValue<std::string>(chat_member, "status")),
    user(Utils::GetPtr<User>(chat_member, "user")),
    is_anonymous(Utils::GetValue<bool>(chat_member, "is_anonymous")),
    custom_title(Utils::GetValue<std::string>(chat_member, "custom_title")) {}
