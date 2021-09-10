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

Json Bot::Request(const std::string& method,
                  const Json& params,
                  const InputFilesList& input_files) {
  CURL* curl = curl_easy_init();
  curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 20);
  curl_easy_setopt(curl, CURLOPT_TIMEOUT, 25);
  curl_easy_setopt(curl,
                   CURLOPT_URL,
                   ("https://api.telegram.org/bot" + token_ + "/"
                       + method).c_str());

  struct curl_slist* headers = nullptr;
  headers = curl_slist_append(headers, "Connection: close");
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

  curl_mime* mime = curl_mime_init(curl);
  curl_mimepart* part;

  for (const auto&[key, value] : params.items()) {
    part = curl_mime_addpart(mime);
    std::string value_in_str;
    if (value.is_string()) {
      // value.dump() for string_t value will return "<str>" instead of <str>
      value_in_str = value;
    } else {
      value_in_str = value.dump();
    }
    curl_mime_data(part, value_in_str.c_str(), value_in_str.size());
    curl_mime_name(part, key.c_str());
  }

  for (const auto&[key, file] : input_files) {
    part = curl_mime_addpart(mime);
    curl_mime_data(part, file.GetDataPtr(), file.GetSize());
    curl_mime_type(part, file.GetMimeType().c_str());
    curl_mime_filename(part, file.GetFileName().c_str());
    curl_mime_name(part, key.c_str());
  }

  if (!params.empty() || !input_files.empty()) {
    curl_easy_setopt(curl, CURLOPT_MIMEPOST, mime);
  }

  std::string response_string;
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteFunction);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, & response_string);

  // If request is successful we will set this variable to 'true' before return
  is_last_request_successful_ = false;
  auto result = curl_easy_perform(curl);
  curl_mime_free(mime);
  curl_slist_free_all(headers);
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
  return std::make_shared<User>(Request("getMe").at("result"));
}

ChatPtr Bot::GetChat(int64_t chat_id) {
  return std::make_shared<Chat>(
      Request("getChat", {{"chat_id", chat_id}}).at("result"));
}

void Bot::HandleUpdate(const UpdatePtr& update) {
  event_manager_->CallCallbackFor(this, update);
}

void Bot::HandleUpdates() {
  Json params;

  if (updates_offset_) {
    params["offset"] = updates_offset_;
  }

  params["timeout"] = updates_timeout_;

  params["allowed_updates"] = allowed_updates_;

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
    // Delete handled updates from Telegram server manually
    Request("getUpdates", {{"offset", updates_offset_}});
  }
}

MessagePtr Bot::SendMessage_(Json params,
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

  if (reply_to_message_id) {
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

  if (reply_markup) {
    params["reply_markup"] = reply_markup->ToJson();
  }

  return std::make_shared<Message>(Request("sendMessage", params).at("result"));
}

MessagePtr Bot::ForwardMessage_(Json params,
                                int32_t message_id,
                                bool disable_notification) {
  params["message_id"] = message_id;

  if (disable_notification) {
    params["disable_notification"] = disable_notification;
  }

  return std::make_shared<Message>(
      Request("forwardMessage", params).at("result"));
}

MessageIdPtr Bot::CopyMessage_(
    Json params,
    int32_t message_id,
    bool disable_notification,
    const std::string& caption,
    int32_t reply_to_message_id,
    bool allow_sending_without_reply,
    const std::string& parse_mode,
    const std::vector<MessageEntityPtr>& caption_entities,
    const AbstractReplyMarkupPtr& reply_markup) {
  params["message_id"] = message_id;

  if (disable_notification) {
    params["disable_notification"] = disable_notification;
  }

  if (!caption.empty()) {
    params["caption"] = caption;
  }

  if (reply_to_message_id) {
    params["reply_to_message_id"] = reply_to_message_id;
  }

  if (allow_sending_without_reply) {
    params["allow_sending_without_reply"] = allow_sending_without_reply;
  }

  if (!parse_mode.empty()) {
    params["parse_mode"] = parse_mode;
  }

  for (const auto& caption_entity : caption_entities) {
    params["caption_entities"].push_back(caption_entity->ToJson());
  }

  if (reply_markup) {
    params["caption"] = reply_markup->ToJson();
  }

  return std::make_shared<MessageId>(
      Request("copyMessage", params).at("result"));
}

MessagePtr Bot::SendPhoto_(
    Json params,
    const InputFilesList& input_files,
    const std::string& caption,
    bool disable_notification,
    int32_t reply_to_message_id,
    bool allow_sending_without_reply,
    const std::string& parse_mode,
    const std::vector<MessageEntityPtr>& caption_entities,
    const AbstractReplyMarkupPtr& reply_markup) {
  if (!caption.empty()) {
    params["caption"] = caption;
  }

  if (disable_notification) {
    params["disable_notification"] = disable_notification;
  }

  if (reply_to_message_id) {
    params["reply_to_message_id"] = reply_to_message_id;
  }

  if (allow_sending_without_reply) {
    params["allow_sending_without_reply"] = allow_sending_without_reply;
  }

  if (!parse_mode.empty()) {
    params["parse_mode"] = parse_mode;
  }

  for (const auto& caption_entity : caption_entities) {
    params["caption_entities"].push_back(caption_entity->ToJson());
  }

  if (reply_markup) {
    params["reply_markup"] = reply_markup->ToJson();
  }

  return std::make_shared<Message>(
      Request("sendPhoto", params, input_files).at("result"));
}

MessagePtr Bot::SendAudio_(
    Json params,
    const InputFilesList& input_files,
    const std::string& caption,
    bool disable_notification,
    int32_t reply_to_message_id,
    bool allow_sending_without_reply,
    int32_t duration,
    const std::string& performer,
    const std::string& title,
    const std::string& parse_mode,
    const std::vector<MessageEntityPtr>& caption_entities,
    const AbstractReplyMarkupPtr& reply_markup) {
  if (!caption.empty()) {
    params["caption"] = caption;
  }

  if (disable_notification) {
    params["disable_notification"] = disable_notification;
  }

  if (reply_to_message_id) {
    params["reply_to_message_id"] = reply_to_message_id;
  }

  if (allow_sending_without_reply) {
    params["allow_sending_without_reply"] = allow_sending_without_reply;
  }

  if (duration) {
    params["duration"] = duration;
  }

  if (!performer.empty()) {
    params["performer"] = performer;
  }

  if (!title.empty()) {
    params["title"] = title;
  }

  if (!parse_mode.empty()) {
    params["parse_mode"] = parse_mode;
  }

  for (const auto& caption_entity : caption_entities) {
    params["caption_entities"].push_back(caption_entity->ToJson());
  }

  if (reply_markup) {
    params["reply_markup"] = reply_markup->ToJson();
  }

  return std::make_shared<Message>(
      Request("sendAudio", params, input_files).at("result"));
}

MessagePtr Bot::SendDocument_(
    Json params,
    const InputFilesList& input_files,
    const std::string& caption,
    bool disable_notification,
    int32_t reply_to_message_id,
    bool allow_sending_without_reply,
    bool disable_content_type_detection,
    const std::string& parse_mode,
    const std::vector<MessageEntityPtr>& caption_entities,
    const AbstractReplyMarkupPtr& reply_markup) {
  if (!caption.empty()) {
    params["caption"] = caption;
  }

  if (disable_notification) {
    params["disable_notification"] = disable_notification;
  }

  if (reply_to_message_id) {
    params["reply_to_message_id"] = reply_to_message_id;
  }

  if (allow_sending_without_reply) {
    params["allow_sending_without_reply"] = allow_sending_without_reply;
  }

  if (disable_content_type_detection) {
    params["disable_content_type_detection"] = disable_content_type_detection;
  }

  if (!parse_mode.empty()) {
    params["parse_mode"] = parse_mode;
  }

  for (const auto& caption_entity : caption_entities) {
    params["caption_entities"].push_back(caption_entity->ToJson());
  }

  if (reply_markup) {
    params["reply_markup"] = reply_markup->ToJson();
  }

  return std::make_shared<Message>(
      Request("sendDocument", params, input_files).at("result"));
}

MessagePtr Bot::SendVideo_(
    Json params,
    const InputFilesList& input_files,
    const std::string& caption,
    bool supports_streaming,
    bool disable_notification,
    int32_t reply_to_message_id,
    bool allow_sending_without_reply,
    int32_t duration,
    int32_t width,
    int32_t height,
    const std::string& parse_mode,
    const std::vector<MessageEntityPtr>& caption_entities,
    const AbstractReplyMarkupPtr& reply_markup) {
  if (!caption.empty()) {
    params["caption"] = caption;
  }

  if (supports_streaming) {
    params["supports_streaming"] = supports_streaming;
  }

  if (disable_notification) {
    params["disable_notification"] = disable_notification;
  }

  if (reply_to_message_id) {
    params["reply_to_message_id"] = reply_to_message_id;
  }

  if (allow_sending_without_reply) {
    params["allow_sending_without_reply"] = allow_sending_without_reply;
  }

  if (duration) {
    params["duration"] = duration;
  }

  if (width) {
    params["width"] = width;
  }

  if (height) {
    params["height"] = height;
  }

  if (!parse_mode.empty()) {
    params["parse_mode"] = parse_mode;
  }

  for (const auto& caption_entity : caption_entities) {
    params["caption_entities"].push_back(caption_entity->ToJson());
  }

  if (reply_markup) {
    params["reply_markup"] = reply_markup->ToJson();
  }

  return std::make_shared<Message>(
      Request("sendVideo", params, input_files).at("result"));
}

MessagePtr Bot::SendAnimation_(
    Json params,
    const InputFilesList& input_files,
    const std::string& caption,
    bool disable_notification,
    int32_t reply_to_message_id,
    bool allow_sending_without_reply,
    int32_t duration,
    int32_t width,
    int32_t height,
    const std::string& parse_mode,
    const std::vector<MessageEntityPtr>& caption_entities,
    const AbstractReplyMarkupPtr& reply_markup) {
  if (!caption.empty()) {
    params["caption"] = caption;
  }

  if (disable_notification) {
    params["disable_notification"] = disable_notification;
  }

  if (reply_to_message_id) {
    params["reply_to_message_id"] = reply_to_message_id;
  }

  if (allow_sending_without_reply) {
    params["allow_sending_without_reply"] = allow_sending_without_reply;
  }

  if (duration) {
    params["duration"] = duration;
  }

  if (width) {
    params["width"] = width;
  }

  if (height) {
    params["height"] = height;
  }

  if (!parse_mode.empty()) {
    params["parse_mode"] = parse_mode;
  }

  for (const auto& caption_entity : caption_entities) {
    params["caption_entities"].push_back(caption_entity->ToJson());
  }

  if (reply_markup) {
    params["reply_markup"] = reply_markup->ToJson();
  }

  return std::make_shared<Message>(
      Request("sendAnimation", params, input_files).at("result"));
}

MessagePtr Bot::SendVoice_(
    Json params,
    const InputFilesList& input_files,
    const std::string& caption,
    bool disable_notification,
    int32_t reply_to_message_id,
    bool allow_sending_without_reply,
    int32_t duration,
    const std::string& parse_mode,
    const std::vector<MessageEntityPtr>& caption_entities,
    const AbstractReplyMarkupPtr& reply_markup) {
  if (!caption.empty()) {
    params["caption"] = caption;
  }

  if (disable_notification) {
    params["disable_notification"] = disable_notification;
  }

  if (reply_to_message_id) {
    params["reply_to_message_id"] = reply_to_message_id;
  }

  if (allow_sending_without_reply) {
    params["allow_sending_without_reply"] = allow_sending_without_reply;
  }

  if (duration) {
    params["duration"] = duration;
  }

  if (!parse_mode.empty()) {
    params["parse_mode"] = parse_mode;
  }

  for (const auto& caption_entity: caption_entities) {
    params["caption_entities"].push_back(caption_entity->ToJson());
  }

  if (reply_markup) {
    params["reply_markup"] = reply_markup->ToJson();
  }

  return std::make_shared<Message>(
      Request("sendVoice", params, input_files).at("result"));
}

MessagePtr Bot::SendVideoNote_(
    Json params,
    const InputFilesList& input_files,
    const std::string& caption,
    bool disable_notification,
    int32_t reply_to_message_id,
    bool allow_sending_without_reply,
    int32_t duration,
    int32_t length,
    const std::string& parse_mode,
    const std::vector<MessageEntityPtr>& caption_entities,
    const AbstractReplyMarkupPtr& reply_markup) {
  if (!caption.empty()) {
    params["caption"] = caption;
  }

  if (disable_notification) {
    params["disable_notification"] = disable_notification;
  }

  if (reply_to_message_id) {
    params["reply_to_message_id"] = reply_to_message_id;
  }

  if (allow_sending_without_reply) {
    params["allow_sending_without_reply"] = allow_sending_without_reply;
  }

  if (duration) {
    params["duration"] = duration;
  }

  if (length) {
    params["length"] = length;
  }

  if (!parse_mode.empty()) {
    params["parse_mode"] = parse_mode;
  }

  for (const auto& caption_entity : caption_entities) {
    params["caption_entities"].push_back(caption_entity->ToJson());
  }

  if (reply_markup) {
    params["reply_markup"] = reply_markup->ToJson();
  }

  return std::make_shared<Message>(
      Request("sendAnimation", params, input_files).at("result"));
}

}  // namespace SQBot
