#include "login_url.h"

LoginUrl::LoginUrl(const Json& login_url)
  : url(Utils::GetValue<std::string>(login_url, "url")),
    forward_text(Utils::GetValue<std::string>(login_url, "forward_text")),
    bot_username(Utils::GetValue<std::string>(login_url, "bot_username")),
    request_write_access(
        Utils::GetValue<bool>(login_url, "request_write_access")) {}
