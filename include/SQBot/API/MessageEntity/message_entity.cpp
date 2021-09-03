#include "message_entity.h"

MessageEntity::MessageEntity(const Json& message_entity)
  : type(Utils::GetValue<std::string>(message_entity, "type")),
    offset(Utils::GetValue<int32_t>(message_entity, "offset")),
    length(Utils::GetValue<int32_t>(message_entity, "length")),
    url(Utils::GetValue<std::string>(message_entity, "url")),
    user(Utils::GetValue<Json>(message_entity, "user")),
    language(Utils::GetValue<std::string>(message_entity, "language")) {}
