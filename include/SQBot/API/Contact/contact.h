#ifndef CONTACT_H_
#define CONTACT_H_

#include <string>

#include "json.h"

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

#endif  // CONTACT_H_
