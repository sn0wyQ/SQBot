#ifndef INCLUDE_SQBOT_API_CHATLOCATION_CHAT_LOCATION_H_
#define INCLUDE_SQBOT_API_CHATLOCATION_CHAT_LOCATION_H_

#include <memory>
#include <string>

#include "../../../nlohmann/json.h"

#include "../Location/location.h"

#include "../../Utils/utils.h"

// Represents a location to which a chat is connected
class ChatLocation {
 public:
  ChatLocation() = default;
  explicit ChatLocation(const Json& chat_location);

  // The location to which the supergroup is connected. Can't be a live location
  std::shared_ptr<Location> location;

  // Location address; 1-64 characters, as defined by the chat owner
  std::string address;
};

#endif  // INCLUDE_SQBOT_API_CHATLOCATION_CHAT_LOCATION_H_
