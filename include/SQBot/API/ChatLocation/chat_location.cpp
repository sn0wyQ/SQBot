#include "chat_location.h"

ChatLocation::ChatLocation(const Json& location)
  : location(Utils::GetValue<Json>(location, "location")),
    address(Utils::GetValue<std::string>(address, "address")) {}
