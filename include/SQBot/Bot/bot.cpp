#include "bot.h"

#include "../EventManager/event_manager.h"

namespace SQBot {

Bot::Bot(std::string token,
         int32_t delay_between_updates,
         int32_t updates_timeout)
  : event_manager_(std::make_shared<EventManager>()),
    token_(std::move(token)),
    delay_between_updates_(delay_between_updates),
    updates_timeout_(updates_timeout) {}

bool Bot::IsLastRequestSuccessful() const {
  return is_last_request_successful_;
}

void Bot::StartReceivingUpdates() {
  // We want only one thread receiving updates
  if (is_receiving_updates_) {
    throw Exception(ExceptionType::kUndefinedBehaviour,
                    "Bot is already receiving updates");
  }

  is_receiving_updates_ = true;
  while (is_receiving_updates_) {
    HandleUpdates();
    std::this_thread::sleep_for(delay_between_updates_);
  }
}

std::shared_ptr<std::thread> Bot::StartReceivingUpdatesInDedicatedThread() {
  // We want only one thread receiving updates
  if (is_receiving_updates_) {
    throw Exception(ExceptionType::kUndefinedBehaviour,
                    "Bot is already receiving updates");
  }

  dedicated_updates_thread_ =
      std::make_shared<std::thread>(&Bot::StartReceivingUpdates, this);
  dedicated_updates_thread_->detach();
  return dedicated_updates_thread_;
}

void Bot::StopReceivingUpdates(bool safe_stop) {
  is_receiving_updates_ = false;
  if (safe_stop && dedicated_updates_thread_) {
    if (!dedicated_updates_thread_->joinable()) {
      // We try to StopReceivingUpdates from dedicated thread itself which makes
      // impossible to safely stop receiving updates
      throw Exception(ExceptionType::kImpossibleToStopSafely,
                      "Can't join dedicated updates thread to the current one");
    }
    dedicated_updates_thread_->join();
    dedicated_updates_thread_.reset();
  }
}

bool Bot::IsReceivingUpdates() const {
  return is_receiving_updates_;
}

std::shared_ptr<EventManager> Bot::GetEventManager() {
  return event_manager_;
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

  // If request is successful we will set this variable to 'true' before return
  is_last_request_successful_ = false;
  auto result = curl_easy_perform(curl);
  curl_easy_cleanup(curl);

  if (result != CURLE_OK) {
    throw Exception(ExceptionType::kCurlError,
                    "code " + std::to_string(result));
  }

  Json response = Json::parse(response_string);

  if (!response.contains("ok")) {
    throw Exception(ExceptionType::kRequestError,
                    "Telegram API response doesn't contain field 'ok'");
  }

  if (response.at("ok") == false) {
    HandleUnsuccessfulRequest(response);
  }

  is_last_request_successful_ = true;
  return response;
}

UserPtr Bot::GetMe() {
  try {
    return Utils::GetPtr<User>(Request("getMe"), "result");
  } catch (const std::exception& e) {
    throw e;
  }
}

ChatPtr Bot::GetChat(int64_t chat_id) {
  try {
    return Utils::GetPtr<Chat>(
        Request("getChat", {{"chat_id", chat_id}}), "result");
  } catch (const std::exception& e) {
    throw e;
  }
}

void Bot::HandleUpdate(const UpdatePtr& update) {
  event_manager_->CallCallbackFor(this, update);
}

MessagePtr Bot::InternalSendMessage(
    Json params,
    const std::string& text,
    bool disable_notification,
    bool disable_web_page_preview,
    int32_t reply_to_message_id,
    bool allow_sending_without_reply,
    const std::string& parse_mode,
    const std::vector<MessageEntityPtr>& entities,
    const AbstractReplyMarkupPtr& reply_markup) {
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
    return Utils::GetPtr<Message>(Request("sendMessage", params), "result");
  } catch (const std::exception& e) {
    throw e;
  }
}

void Bot::HandleUpdates() {
  Json params;
  if (updates_offset_) {
    params["offset"] = updates_offset_;
  }
  params["timeout"] = updates_timeout_;
  params["allowed_updates"] = allowed_updates_;

  try {
    Json response = Request("getUpdates", params);
    const auto& updates = response.at("result");
    if (updates.empty()) {
      updates_offset_ = 0;
    } else {
      for (const auto& update : updates) {
        auto current_update = std::make_shared<Update>(update);
        HandleUpdate(current_update);
        updates_offset_ = current_update->update_id + 1;
      }
    }

    if (!is_receiving_updates_) {
      // Delete handled updates from Telegram server
      Request("getUpdates", {{"offset", updates_offset_}});
    }
  } catch (const std::exception& e) {
    throw e;
  }
}

}  // namespace SQBot
