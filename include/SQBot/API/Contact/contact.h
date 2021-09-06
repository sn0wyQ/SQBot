#ifndef INCLUDE_SQBOT_API_CONTACT_CONTACT_H_
#define INCLUDE_SQBOT_API_CONTACT_CONTACT_H_

#include <string>

#include "../../../nlohmann/json.h"

#include "../../Utils/utils.h"

// This object represents a phone contact
class Contact {
 public:
  Contact() = default;
  explicit Contact(const Json& contact);

  std::string phone_number;

  std::string first_name;

  std::string last_name;

  int64_t user_id{};

  std::string vcard;
};

using ContactPtr = std::shared_ptr<Contact>;

#endif  // INCLUDE_SQBOT_API_CONTACT_CONTACT_H_
