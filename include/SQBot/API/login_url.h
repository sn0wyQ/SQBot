#ifndef INCLUDE_SQBOT_API_LOGIN_URL_H_
#define INCLUDE_SQBOT_API_LOGIN_URL_H_

#include <memory>
#include <string>

#include "../../nlohmann/json.h"

#include "../Utils/utils.h"

// This object represents a parameter of the inline keyboard button used to
// automatically authorize a user. Serves as a great replacement for the
// Telegram Login Widget when the user is coming from Telegram. All the
// user needs to do is tap/click a button and confirm that they want to log in
class LoginUrl {
 public:
  LoginUrl() = default;
  explicit LoginUrl(const Json& login_url);

  Json ToJson() const;

  // An HTTP URL to be opened with user authorization data added to the query
  // string when the button is pressed. If the user refuses to provide
  // authorization data, the original URL without information about the
  // user will be opened. The data added is the same as described in
  // Receiving authorization data.
  // NOTE: You must always check the hash of the received data to verify
  // the authentication and the integrity of the data as described in
  // Checking authorization
  std::string url;

  // Optional. New text of the button in forwarded messages
  std::string forward_text;

  // Optional. Username of a bot, which will be used for user authorization.
  // See Setting up a bot for more details. If not specified, the current bot's
  // username will be assumed. The url's domain must be the same as the domain
  // linked with the bot. See Linking your domain to the bot for more details
  std::string bot_username;

  // Optional. Pass True to request the permission for your bot
  // to send messages to the user
  bool request_write_access{false};
};

using LoginUrlPtr = std::shared_ptr<LoginUrl>;

#endif  // INCLUDE_SQBOT_API_LOGIN_URL_H_
