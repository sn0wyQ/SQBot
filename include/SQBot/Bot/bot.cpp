#include "bot.h"

namespace SQBot {

Bot::Bot(std::string token) : token_(std::move(token)) {}

void Bot::ProcessUpdates() {}

bool Bot::IsLastRequestSuccessful() const {
  return is_last_request_successful_;
}

std::shared_ptr<User> Bot::GetMe() {
  try {
    return std::make_shared<User>(Utils::GetValue<Json>(
        Request("getMe"), "result"));
  } catch (std::exception& e) {
    throw e;
  }
}

std::shared_ptr<Message>
Bot::SendMessage(const std::string& chat_id,
                 const std::string& text,
                 bool disable_notification,
                 bool disable_web_page_preview,
                 int32_t reply_to_message_id,
                 bool allow_sending_without_reply,
                 const std::string& parse_mode,
                 const std::vector<std::shared_ptr<MessageEntity>>& entities,
                 const std::shared_ptr<AbstractReplyMarkup>& reply_markup) {
  Json params;
  params["chat_id"] = chat_id;
  params["text"] = text;
  if (disable_notification) {
    params["disable_notification"] = disable_notification;
  }
  if (disable_web_page_preview) {
    params["disable_web_page_preview"] = disable_web_page_preview;
  }
  if (reply_to_message_id != 0) {
    params["reply_to_message_id"] = reply_to_message_id;
  }
  if (allow_sending_without_reply) {
    params["allow_sending_without_reply"] = allow_sending_without_reply;
  }
  if (!parse_mode.empty()) {
    params["parse_mode"] = parse_mode;
  }
  for (const auto& entity : entities) {
    params["entities"].push_back(entity->ToJson());
  }
  // TODO(sn0wyQ): add params["reply_markup"] = reply_markup->ToJson();
  try {
    return std::make_shared<Message>(Utils::GetValue<Json>(
        Request("sendMessage", params), "result"));
  } catch (std::exception& e) {
    throw e;
  }
}

size_t WriteFunction(void* ptr, size_t size, size_t n, std::string* data) {
  data->append(reinterpret_cast<char*>(ptr), size * n);
  return size * n;
}

Json Bot::Request(const std::string& request, const Json& params) {
  CURL* curl = curl_easy_init();
  curl_easy_setopt(curl,
                   CURLOPT_URL,
                   ("https://api.telegram.org/bot" + token_ + "/"
                       + request).c_str());

  std::string response_string;
  struct curl_slist *headers = nullptr;
  headers = curl_slist_append(headers, "Accept: application/json");
  headers = curl_slist_append(headers, "Content-Type: application/json");

  curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
  curl_easy_setopt(curl, CURLOPT_COPYPOSTFIELDS, params.dump().c_str());
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteFunction);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

  auto result = curl_easy_perform(curl);
  curl_easy_cleanup(curl);
  if (result != CURLE_OK) {
    std::cout << "curl error " << result << std::endl;
    // TODO(sn0wyQ): throw some error instead
    return {};
  }

  Json response = Json::parse(response_string);

  // If request is successful we will set this variable to 'true' before return
  is_last_request_successful_ = false;

  if (!response.contains("ok")) {
    // TODO(sn0wyQ): throw some error instead
    return {};
  }

  if (response.at("ok") == false) {
    HandleUnsuccessfulRequest(response);
  }

  is_last_request_successful_ = true;
  return response;
}

}  // namespace SQBot
