#ifndef INCLUDE_SQBOT_API_INLINE_QUERY_H_
#define INCLUDE_SQBOT_API_INLINE_QUERY_H_

#include <memory>
#include <string>

#include "../../nlohmann/json.h"

#include "location.h"
#include "user.h"

#include "../Utils/utils.h"

// This object represents an incoming inline query. When the user sends
// an empty query, your bot could return some default or trending results
class InlineQuery {
 public:
  InlineQuery() = default;
  explicit InlineQuery(const Json& inline_query);

  // Unique identifier for this query
  std::string id;

  // Sender
  UserPtr from;

  // Text of the query (up to 256 characters)
  std::string query;

  // Offset of the results to be returned, can be controlled by the bot
  std::string offset;

  // OPTIONAL. Type of the chat, from which the inline query was sent.
  // Can be either “sender” for a private chat with the inline query sender,
  // “private”, “group”, “supergroup”, or “channel”.
  // The chat type should be always known for requests sent
  // from official clients and most third-party clients,
  // unless the request was sent from a secret chat
  std::string chat_type;

  // OPTIONAL. Sender location, only for bots that request user location
  LocationPtr location;
};

using InlineQueryPtr = std::shared_ptr<InlineQuery>;

#endif  // INCLUDE_SQBOT_API_INLINE_QUERY_H_
