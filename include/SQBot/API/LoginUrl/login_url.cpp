#include "login_url.h"

LoginUrl::LoginUrl(const Json& login_url)
  : url(Utils::GetValue<std::string>(login_url, "url")),
    forward_text(Utils::GetValue<std::string>(login_url, "forward_text")),
    bot_username(Utils::GetValue<std::string>(login_url, "bot_username")),
    request_write_access(
        Utils::GetValue<bool>(login_url, "request_write_access")) {}

Json LoginUrl::ToJson() const {
  Json login_url;

  login_url["url"] = url;

  if (!forward_text.empty()) {
    login_url["forward_text"] = forward_text;
  }

  if (!bot_username.empty()) {
    login_url["bot_username"] = bot_username;
  }

  if (request_write_access) {
    login_url["request_write_access"] = request_write_access;
  }

  return login_url;
}
