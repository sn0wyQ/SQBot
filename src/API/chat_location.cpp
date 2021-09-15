#include "../../include/SQBot/API/chat_location.h"

ChatLocation::ChatLocation(const Json& location)
  : location(SQBot::Utils::GetPtr<Location>(location, "location")),
    address(SQBot::Utils::GetValue<std::string>(address, "address")) {}
