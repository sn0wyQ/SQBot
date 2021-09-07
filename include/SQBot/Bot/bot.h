#ifndef INCLUDE_SQBOT_BOT_BOT_H_
#define INCLUDE_SQBOT_BOT_BOT_H_

#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <type_traits>
#include <utility>
#include <vector>

#include "curl/curl.h"
#include "../../nlohmann/json.h"

#include "../API/Chat/chat.h"
#include "../API/MessageEntity/message_entity.h"
#include "../API/MessageId/message_id.h"
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
  // max_request_retries - max allowed request retries
  //    before throwing kCurlError exception
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
  // method - name of method as specified in Telegram API
  // params - JSON file with params (names as specified in Telegram API)
  Json Request(const std::string& method, const Json& params = {});

  // A simple method for testing your bot's auth token.
  //
  // Return value:
  // Returns basic information about the bot in form of a User object
  //
  // Telegram API link:
  // https://core.telegram.org/bots/api#getme
  UserPtr GetMe();

  // Use this method to get up-to-date information about the chat
  // (current name of the user for one-on-one conversations,
  // current username of a user, group or channel, etc.).
  //
  // Return value:
  // Returns a Chat object on success
  //
  // Telegram API link:
  // https://core.telegram.org/bots/api#getchat
  ChatPtr GetChat(int64_t chat_id);

  // Use this method to send text messages.
  //
  // Return value:
  // On success, sent Message is returned
  //
  // Telegram API link:
  // https://core.telegram.org/bots/api#sendmessage
  template<typename ChatIdType>
  MessagePtr SendMessage(const ChatIdType& chat_id,
                         const std::string& text,
                         bool disable_notification = false,
                         bool disable_web_page_preview = false,
                         int32_t reply_to_message_id = 0,
                         bool allow_sending_without_reply = false,
                         const std::string& parse_mode = "",
                         const std::vector<MessageEntityPtr>& entities = {},
                         const AbstractReplyMarkupPtr& reply_markup = {}) {
    return SendMessage_({{"chat_id", chat_id}},
                        text,
                        disable_notification,
                        disable_web_page_preview,
                        reply_to_message_id,
                        allow_sending_without_reply,
                        parse_mode,
                        entities,
                        reply_markup);
  }

  // Use this method to forward messages of any kind.
  // Service messages can't be forwarded
  //
  // Return value:
  // On success, sent Message is returned
  //
  // Telegram API link:
  // https://core.telegram.org/bots/api#forwardmessage
  template<typename ChatIdType, typename FromChatIdType>
  MessagePtr ForwardMessage(const ChatIdType& chat_id,
                            const FromChatIdType& from_chat_id,
                            int32_t message_id,
                            bool disable_notification = false) {
    return ForwardMessage_({{"chat_id", chat_id},
                            {"from_chat_id", from_chat_id}},
                           message_id,
                           disable_notification);
  }

  // Use this method to copy messages of any kind. Service messages and invoice
  // messages can't be copied. The method is analogous to the method
  // forwardMessage, but the copied message doesn't have a link to the original
  // message
  //
  // Return value:
  // Returns the MessageId of sent message on success
  //
  // Telegram API link:
  // https://core.telegram.org/bots/api#copymessage
  template<typename ChatIdType, typename FromChatIdType>
  MessageIdPtr CopyMessage(
      const ChatIdType& chat_id,
      const FromChatIdType& from_chat_id,
      int32_t message_id,
      const std::string& caption = "",
      bool disable_notification = false,
      int32_t reply_to_message_id = 0,
      bool allow_sending_without_reply = false,
      const std::string& parse_mode = "",
      const std::vector<MessageEntityPtr>& caption_entities = {},
      const AbstractReplyMarkupPtr& reply_markup = {}) {
    return CopyMessage_({{"chat_id", chat_id},
                         {"from_chat_id", from_chat_id}},
                        message_id,
                        disable_notification,
                        caption,
                        reply_to_message_id,
                        allow_sending_without_reply,
                        parse_mode,
                        caption_entities,
                        reply_markup);
  }

  // Use this method to send photos
  //
  // Return value:
  // On success, the sent Message is returned
  //
  // Telegram API link:
  // https://core.telegram.org/bots/api#sendphoto
  template<typename ChatIdType>
  MessagePtr SendPhoto(
      const ChatIdType& chat_id,
      const std::string& photo,
      const std::string& caption = "",
      bool disable_notification = false,
      int32_t reply_to_message_id = 0,
      bool allow_sending_without_reply = false,
      const std::string& parse_mode = "",
      const std::vector<MessageEntityPtr>& caption_entities = {},
      const AbstractReplyMarkupPtr& reply_markup = {}) {
    Json params;

    params["chat_id"] = chat_id;

    return SendPhoto_(params,
                      photo,
                      caption,
                      disable_notification,
                      reply_to_message_id,
                      allow_sending_without_reply,
                      parse_mode,
                      caption_entities,
                      reply_markup);
  }

 protected:
  // This method is called every time when response from Telegram API has
  // field "ok" set to false
  virtual void HandleUnsuccessfulRequest(const Json& response) {}

  // This method is called for every new update received
  virtual void HandleUpdate(const std::shared_ptr<Update>& update);

 private:
  MessagePtr SendMessage_(Json params,
                          const std::string& text,
                          bool disable_notification,
                          bool disable_web_page_preview,
                          int32_t reply_to_message_id,
                          bool allow_sending_without_reply,
                          const std::string& parse_mode,
                          const std::vector<MessageEntityPtr>& entities,
                          const AbstractReplyMarkupPtr& reply_markup);

  MessagePtr ForwardMessage_(Json params,
                             int32_t message_id,
                             bool disable_notification);

  MessageIdPtr CopyMessage_(
      Json params,
      int32_t message_id,
      bool disable_notification,
      const std::string& caption,
      int32_t reply_to_message_id,
      bool allow_sending_without_reply,
      const std::string& parse_mode,
      const std::vector<MessageEntityPtr>& caption_entities,
      const AbstractReplyMarkupPtr& reply_markup);

  MessagePtr SendPhoto_(
      Json params,
      const std::string& photo,
      const std::string& caption,
      bool disable_notification,
      int32_t reply_to_message_id,
      bool allow_sending_without_reply,
      const std::string& parse_mode,
      const std::vector<MessageEntityPtr>& caption_entities,
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
