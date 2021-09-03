#ifndef INCLUDE_SQBOT_BOT_BOT_H_
#define INCLUDE_SQBOT_BOT_BOT_H_

#include <exception>
#include <iostream>
#include <string>
#include <utility>

#include "curl/curl.h"
#include "json.h"

#include "../API/Message/message.h"
#include "../API/User/user.h"

namespace SQBot {

class Bot {
 public:
  explicit Bot(std::string token);
  ~Bot();

  bool IsLastRequestSuccessful() const;

  virtual void HandleUnsuccessfulRequest(const Json& response) {}

  User GetMe();

 private:
  void ProcessUpdates();
  Json Request(const std::string& request);

  CURL* curl_;
  std::string token_;
  bool is_last_request_successful_{true};
};

}  // namespace SQBot

#endif  // INCLUDE_SQBOT_BOT_BOT_H_
