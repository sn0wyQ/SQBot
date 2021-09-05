#ifndef CALLBACK_QUERY_H_
#define CALLBACK_QUERY_H_

#include <memory>
#include <string>

#include "json.h"

#include "../Message/message.h"
#include "../User/user.h"

#include "../../Utils/utils.h"

// This object represents an incoming callback query from a callback
// button in an inline keyboard. If the button that originated the query
// was attached to a message sent by the bot, the field message will be present.
// If the button was attached to a message sent via the bot (in inline mode),
// the field inline_message_id will be present. Exactly one of the fields data
// or game_short_name will be present
class CallbackQuery {
 public:
  CallbackQuery() = default;
  explicit CallbackQuery(const Json& callback_query);

  // Unique identifier for this query
  std::string id;

  // Sender
  std::shared_ptr<User> from;

  // OPTIONAL. Message with the callback button that originated the query.
  // Note that message content and message date
  // will not be available if the message is too old
  std::shared_ptr<Message> message;

  // OPTIONAL. Identifier of the message sent via the bot in inline mode,
  // that originated the query
  std::string inline_message_id;

  // Global identifier, uniquely corresponding to the chat to which the message
  // with the callback button was sent. Useful for high scores in games
  std::string chat_instance;

  // OPTIONAL. Data associated with the callback button.
  // Be aware that a bad client can send arbitrary data in this field
  std::string data;

  // OPTIONAL. Short name of a Game to be returned,
  // serves as the unique identifier for the game
  std::string game_short_name;
};

#endif  // CALLBACK_QUERY_H_