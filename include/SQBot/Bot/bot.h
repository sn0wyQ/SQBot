#ifndef INCLUDE_SQBOT_BOT_BOT_H_
#define INCLUDE_SQBOT_BOT_BOT_H_

#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <utility>

#include "curl/curl.h"
#include "json.h"

#include "../API/Chat/chat.h"
#include "../API/MessageEntity/message_entity.h"
#include "../API/Message/message.h"
#include "../API/User/user.h"

#include "../AbstractReplyMarkup/abstract_reply_markup.h"

namespace SQBot {

class Bot {
 public:
  explicit Bot(std::string token);

  bool IsLastRequestSuccessful() const;

  virtual void HandleUnsuccessfulRequest(const Json& response) {}

  // A simple method for testing your bot's auth token.
  // Returns basic information about the bot in form of a User object
  std::shared_ptr<User> GetMe();

  // Use this method to get up-to-date information about the chat
  // (current name of the user for one-on-one conversations,
  // current username of a user, group or channel, etc.).
  // Returns a Chat object on success
  std::shared_ptr<Chat> GetChat();

  // Use this method to send text messages.
  // On success, sent Message is returned
  std::shared_ptr<Message>
  SendMessage(int64_t chat_id,
              const std::string& text,
              bool disable_notification = false,
              bool disable_web_page_preview = false,
              int32_t reply_to_message_id = 0,
              bool allow_sending_without_reply = false,
              const std::string& parse_mode = "",
              const std::vector<std::shared_ptr<MessageEntity>>& entities = {},
              const std::shared_ptr<AbstractReplyMarkup>& reply_markup = {}) {
    return SendMessage(std::to_string(chat_id),
                       text,
                       disable_notification,
                       disable_web_page_preview,
                       reply_to_message_id,
                       allow_sending_without_reply,
                       parse_mode,
                       entities,
                       reply_markup);
  }

  // Use this method to send text messages.
  // On success, sent Message is returned
  std::shared_ptr<Message>
  SendMessage(const std::string& chat_id,
              const std::string& text,
              bool disable_notification = false,
              bool disable_web_page_preview = false,
              int32_t reply_to_message_id = 0,
              bool allow_sending_without_reply = false,
              const std::string& parse_mode = "",
              const std::vector<std::shared_ptr<MessageEntity>>& entities = {},
              const std::shared_ptr<AbstractReplyMarkup>& reply_markup = {});

 private:
  void ProcessUpdates();
  Json Request(const std::string& request, const Json& params = {});

  std::string token_;
  bool is_last_request_successful_{false};
};

}  // namespace SQBot

#endif  // INCLUDE_SQBOT_BOT_BOT_H_
