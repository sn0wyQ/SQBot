#ifndef INCLUDE_SQBOT_API_MESSAGEENTITY_MESSAGE_ENTITY_H_
#define INCLUDE_SQBOT_API_MESSAGEENTITY_MESSAGE_ENTITY_H_

#include <memory>
#include <string>
#include <utility>

#include "../../../nlohmann/json.h"

#include "../User/user.h"

#include "../../Utils/utils.h"

// This object represents one special entity in a text message.
// For example, hashtags, usernames, URLs, etc.
class MessageEntity {
 public:
  MessageEntity() = default;
  explicit MessageEntity(const Json& message_entity);
  MessageEntity(std::string type,
                int32_t offset,
                int32_t length,
                std::string url = "",
                std::shared_ptr<User> user = {},
                std::string language = "");

  Json ToJson() const;

  // Type of the entity. Can be “mention” (@username), “hashtag” (#hashtag),
  // “cashtag” ($USD), “bot_command” (/start@jobs_bot),
  // “url” (https://telegram.org), “email” (do-not-reply@telegram.org),
  // “phone_number” (+1-212-555-0123), “bold” (bold text),
  // “italic” (italic text), “underline” (underlined text),
  // “strikethrough” (strikethrough text), “code” (monowidth string),
  // “pre” (monowidth block), “text_link” (for clickable text URLs),
  // “text_mention” (for users without usernames)
  std::string type;

  // Offset in UTF-16 code units to the start of the entity
  int32_t offset{};

  // Length of the entity in UTF-16 code units
  int32_t length{};

  // OPTIONAL. For “text_link” only, url that
  // will be opened after user taps on the text
  std::string url;

  // OPTIONAL. For “text_mention” only, the mentioned user
  std::shared_ptr<User> user;

  // OPTIONAL. For “pre” only, the programming language of the entity text
  std::string language;
};

#endif  // INCLUDE_SQBOT_API_MESSAGEENTITY_MESSAGE_ENTITY_H_
