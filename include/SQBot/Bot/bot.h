#ifndef INCLUDE_SQBOT_BOT_BOT_H_
#define INCLUDE_SQBOT_BOT_BOT_H_

#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include "curl/curl.h"
#include "../../nlohmann/json.h"

#include "../API/Chat/chat.h"
#include "../API/MessageEntity/message_entity.h"
#include "../API/Message/message.h"
#include "../API/Update/update.h"
#include "../API/User/user.h"

#include "../AbstractReplyMarkup/abstract_reply_markup.h"
#include "../Exception/exception.h"

class EventManager;

namespace SQBot {

class Bot {
 public:
  // token - your bot token received from BotFather
  // delay_between_updates - delay between "getUpdate" requests in milliseconds
  // update_timeout - timeout for long polling in seconds
  Bot(std::string token,
      int32_t delay_between_updates = 0,
      int32_t updates_timeout = 1);

  // Returns true if last request was successful.
  // If no requests were made then return value is false
  bool IsLastRequestSuccessful() const;

  // Starts receiving updates in current thread.
  // NOTE that current thread is BLOCKED until it handles all updates
  // that were received prior to the moment of call to StopReceivingUpdates()
  void StartReceivingUpdates();

  // Starts receiving updates in new dedicated thread.
  // Returns shared pointer to thread dedicated to handling updates
  std::shared_ptr<std::thread> StartReceivingUpdatesInDedicatedThread();

  // Stops receiving updates.
  // If updates were handling in dedicated thread, then if safe_stop is true
  // bot will handle all updates that were received prior to the moment of
  // call to StopReceivingUpdates()
  void StopReceivingUpdates(bool safe_stop = true);

  // Returns true if bot is receiving new updates
  bool IsReceivingUpdates() const;

  std::shared_ptr<EventManager> GetEventManager();

  // Method to manually send requests. Avoid using it as it returns JSON instead
  // of basic type or one of Telegram API specified types
  // request - name of method as specified in Telegram API
  // params - JSON file with params (names as specified in Telegram API)
  Json Request(const std::string& request, const Json& params = {});

  // A simple method for testing your bot's auth token.
  //
  // Return value:
  // Returns basic information about the bot in form of a User object
  UserPtr GetMe();

  // Use this method to get up-to-date information about the chat
  // (current name of the user for one-on-one conversations,
  // current username of a user, group or channel, etc.).
  //
  // Params:
  // chat_id - Unique identifier for the target chat or username of the target
  //    supergroup or channel (in the format @channelusername)
  //
  // Return value:
  // Returns a Chat object on success
  ChatPtr GetChat(int64_t chat_id);

  // Use this method to send text messages.
  //
  // Params:
  // chat_id - Unique identifier for the target chat or username of the target
  //    channel (in the format @channelusername)
  //
  // Return value:
  // On success, sent Message is returned
  template<typename T>
  MessagePtr SendMessage(const T& chat_id,
                         const std::string& text,
                         bool disable_notification = false,
                         bool disable_web_page_preview = false,
                         int32_t reply_to_message_id = 0,
                         bool allow_sending_without_reply = false,
                         const std::string& parse_mode = "",
                         const std::vector<MessageEntityPtr>& entities = {},
                         const AbstractReplyMarkupPtr& reply_markup = {}) {
    return InternalSendMessage({{"chat_id", chat_id}},
                               text,
                               disable_notification,
                               disable_web_page_preview,
                               reply_to_message_id,
                               allow_sending_without_reply,
                               parse_mode,
                               entities,
                               reply_markup);
  }

 protected:
  // This method is called every time when response from Telegram API has
  // field "ok" set to false
  virtual void HandleUnsuccessfulRequest(const Json& response) {}

  // This method is called for every new update received
  virtual void HandleUpdate(const std::shared_ptr<Update>& update);

 private:
  MessagePtr InternalSendMessage(
      Json params,
      const std::string& text,
      bool disable_notification,
      bool disable_web_page_preview,
      int32_t reply_to_message_id,
      bool allow_sending_without_reply,
      const std::string& parse_mode,
      const std::vector<MessageEntityPtr>& entities,
      const AbstractReplyMarkupPtr& reply_markup);

  void HandleUpdates();

  std::shared_ptr<EventManager> event_manager_;
  std::string token_;
  bool is_receiving_updates_{false};
  std::chrono::milliseconds delay_between_updates_;
  int32_t updates_offset_{0};
  int32_t updates_timeout_;
  std::vector<std::string> allowed_updates_;
  std::shared_ptr<std::thread> dedicated_updates_thread_;
  bool is_last_request_successful_{false};
};

}  // namespace SQBot

#endif  // INCLUDE_SQBOT_BOT_BOT_H_
