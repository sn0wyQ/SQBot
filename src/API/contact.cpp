#include "../../include/SQBot/API/contact.h"

Contact::Contact(const Json& contact)
  : phone_number(SQBot::Utils::GetValue<std::string>(contact, "phone_number")),
    first_name(SQBot::Utils::GetValue<std::string>(contact, "first_name")),
    last_name(SQBot::Utils::GetValue<std::string>(contact, "last_name")),
    user_id(SQBot::Utils::GetValue<int64_t>(contact, "user_id")),
    vcard(SQBot::Utils::GetValue<std::string>(contact, "vcard")) {}
