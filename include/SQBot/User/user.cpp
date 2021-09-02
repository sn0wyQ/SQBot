#include "user.h"

User::User(const Json& user) {
  Utils::GetValue(&id, user, "id");
  Utils::GetValue(&is_bot, user, "is_bot");
  Utils::GetValue(&first_name, user, "first_name");
  Utils::GetValue(&last_name, user, "last_name");
  Utils::GetValue(&username, user, "username");
  Utils::GetValue(&language_code, user, "language_code");
  Utils::GetValue(&can_join_groups, user, "can_join_groups");
  Utils::GetValue(&can_read_all_group_messages, user,
                  "can_read_all_group_messages");
  Utils::GetValue(& supports_inline_queries, user, "supports_inline_queries");
}
