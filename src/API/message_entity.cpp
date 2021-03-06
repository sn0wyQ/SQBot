#include "../../include/SQBot/API/message_entity.h"

MessageEntity::MessageEntity(const Json& message_entity)
  : type(SQBot::Utils::GetValue<std::string>(message_entity, "type")),
    offset(SQBot::Utils::GetValue<int32_t>(message_entity, "offset")),
    length(SQBot::Utils::GetValue<int32_t>(message_entity, "length")),
    url(SQBot::Utils::GetValue<std::string>(message_entity, "url")),
    user(SQBot::Utils::GetPtr<User>(message_entity, "user")),
    language(SQBot::Utils::GetValue<std::string>(message_entity, "language")) {}

MessageEntity::MessageEntity(std::string type,
                             int32_t offset,
                             int32_t length,
                             std::string url,
                             UserPtr user,
                             std::string language)
    : type(std::move(type)),
      offset(offset),
      length(length),
      url(std::move(url)),
      user(std::move(user)),
      language(std::move(language)) {}

Json MessageEntity::ToJson() const {
  Json message_entity;

  message_entity["type"] = type;
  message_entity["offset"] = offset;
  message_entity["length"] = length;

  if (!url.empty()) {
    message_entity["url"] = url;
  }

  if (user) {
    message_entity["user"] = user->ToJson();
  }

  if (!language.empty()) {
    message_entity["language"] = language;
  }

  return message_entity;
}
