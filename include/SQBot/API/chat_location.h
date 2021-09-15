#ifndef INCLUDE_SQBOT_API_CHATLOCATION_CHAT_LOCATION_H_
#define INCLUDE_SQBOT_API_CHATLOCATION_CHAT_LOCATION_H_

#include <memory>
#include <string>

#include "../../nlohmann/json.h"

#include "location.h"

#include "../Utils/utils.h"

// Represents a location to which a chat is connected
class ChatLocation {
 public:
  ChatLocation() = default;
  explicit ChatLocation(const Json& chat_location);

  // The location to which the supergroup is connected. Can't be a live location
  LocationPtr location;

  // Location address; 1-64 characters, as defined by the chat owner
  std::string address;
};

using ChatLocationPtr = std::shared_ptr<ChatLocation>;

#endif  // INCLUDE_SQBOT_API_CHATLOCATION_CHAT_LOCATION_H_
