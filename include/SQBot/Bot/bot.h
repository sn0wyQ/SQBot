#ifndef BOT_H_
#define BOT_H_

#include <exception>
#include <string>
#include <utility>

#include "curl.h"
#include "json.hpp"

using Json = nlohmann::json;

namespace SQBot {

class Bot {
 public:
  explicit Bot(std::string token);

  void ProcessUpdates();

  Json Request(const std::string& request);

 private:
  CURL* curl_;

  std::string token_;
};

}  // namespace SQBot

#endif  // BOT_H_
