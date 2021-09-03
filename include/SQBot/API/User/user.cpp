#include "user.h"

User::User(const Json& user)
  : id(Utils::GetValue<int64_t>(user, "id")),
    is_bot(Utils::GetValue<bool>(user, "is_bot")),
    first_name(Utils::GetValue<std::string>(user, "first_name")),
    last_name(Utils::GetValue<std::string>(user, "last_name")),
    username(Utils::GetValue<std::string>(user, "username")),
    language_code(Utils::GetValue<std::string>(user, "language_code")),
    can_join_groups(Utils::GetValue<bool>(user, "can_join_groups")),
    can_read_all_group_messages(
        Utils::GetValue<bool>(user, "can_read_all_group_messages")),
    supports_inline_queries(
        Utils::GetValue<bool>(user, "supports_inline_queries")) {}
