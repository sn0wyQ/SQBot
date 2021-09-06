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

Json User::ToJson() const {
  Json user;

  user["id"] = id;

  user["is_bot"] = is_bot;

  user["first_name"] = first_name;

  if (!last_name.empty()) {
    user["last_name"] = last_name;
  }

  if (!username.empty()) {
    user["username"] = username;
  }

  if (!language_code.empty()) {
    user["language_code"] = language_code;
  }

  if (can_join_groups) {
    user["can_join_groups"] = can_join_groups;
  }

  if (can_read_all_group_messages) {
    user["can_read_all_group_messages"] = can_read_all_group_messages;
  }

  if (supports_inline_queries) {
    user["supports_inline_queries"] = supports_inline_queries;
  }

  return user;
}
