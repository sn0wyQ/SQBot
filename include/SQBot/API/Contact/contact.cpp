#include "contact.h"

Contact::Contact(const Json& contact)
  : phone_number(Utils::GetValue<std::string>(contact, "phone_number")),
    first_name(Utils::GetValue<std::string>(contact, "first_name")),
    last_name(Utils::GetValue<std::string>(contact, "last_name")),
    user_id(Utils::GetValue<int64_t>(contact, "user_id")),
    vcard(Utils::GetValue<std::string>(contact, "vcard")) {}
