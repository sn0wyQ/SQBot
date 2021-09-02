#include "bot.h"

namespace SQBot {

Bot::Bot(std::string token) : token_(std::move(token)) {
  curl_ = curl_easy_init();
}

void Bot::ProcessUpdates() {
  if (!curl_) {
    // TODO(sn0wyQ): throw some error instead
    return;
  }


}

Json Bot::Request(const std::string& request) {
  curl_easy_setopt(curl_, CURLOPT_URL, request.c_str());
  curl_easy_setopt(curl_, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_0);
  curl_easy_setopt(curl_, CURLOPT_HTTPGET, 1L);
}

}  // namespace SQBot
