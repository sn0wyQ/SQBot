#include "bot.h"

namespace SQBot {

Bot::Bot(std::string token)
  : curl_(curl_easy_init()),
    token_(std::move(token)) {}

Bot::~Bot() {
  curl_easy_cleanup(curl_);
}

void Bot::ProcessUpdates() {
  if (!curl_) {
    // TODO(sn0wyQ): throw some error instead
    return;
  }
}

size_t WriteFunction(void* ptr, size_t size, size_t n, std::string* data) {
  data->append(reinterpret_cast<char*>(ptr), size * n);
  return size * n;
}

bool Bot::IsLastRequestSuccessful() const {
  return is_last_request_successful_;
}

User Bot::GetMe() {
  Json response;
  try {
    response = Request("getMe");
  } catch (std::exception& e) {
    throw e;
  }

  if (!is_last_request_successful_) {
    // TODO(sn0wyQ): throw some error
  }

  return User(response["result"]);
}

Json Bot::Request(const std::string& request) {
  curl_easy_setopt(curl_,
                   CURLOPT_URL,
                   ("https://api.telegram.org/bot" + token_ + "/"
                       + request).c_str());
  curl_easy_setopt(curl_, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_0);
  curl_easy_setopt(curl_, CURLOPT_HTTPGET, 1L);

  std::string response_string;
  std::string header_string;
  curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, WriteFunction);
  curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &response_string);
  curl_easy_setopt(curl_, CURLOPT_HEADERDATA, &header_string);

  curl_easy_perform(curl_);
  Json response = Json::parse(response_string);

  // If request is successful we will set this variable to 'true' before return
  is_last_request_successful_ = false;

  if (!response.contains("ok")) {
    // TODO(sn0wyQ): throw some error instead
    return {};
  }

  if (response["ok"] == false) {
    HandleUnsuccessfulRequest(response);
  }

  is_last_request_successful_ = true;
  return response;
}

}  // namespace SQBot
