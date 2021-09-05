#include "chat_location.h"

ChatLocation::ChatLocation(const Json& location)
  : location(Utils::GetPtr<Location>(location, "location")),
    address(Utils::GetValue<std::string>(address, "address")) {}
