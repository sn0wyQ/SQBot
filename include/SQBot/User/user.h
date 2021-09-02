#ifndef USER_H_
#define USER_H_

#include "json.h"

#include "../Utils/utils.h"

class User {
 public:
  explicit User(const Json& user);

  // Unique identifier for this user or bot
  int64_t id;

  // True, if this user is a bot
  bool is_bot;

  // User's or bot's first name
  std::string first_name;

  // OPTIONAL. User's or bot's last name
  std::string last_name;

  // OPTIONAL. User's or bot's username
  std::string username;

  // OPTIONAL. IETF language tag of the user's language
  std::string language_code;

  // OPTIONAL. True, if the bot can be invited to groups. Returned only in getMe.
  bool can_join_groups;

  // OPTIONAL. True, if privacy mode is disabled for the bot. Returned only in getMe.
  bool can_read_all_group_messages;

  // OPTIONAL. True, if the bot supports inline queries. Returned only in getMe.
  bool supports_inline_queries;
};

#endif  // USER_H_
