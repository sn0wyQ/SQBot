#ifndef CHOSEN_INLINE_RESULT_H_
#define CHOSEN_INLINE_RESULT_H_

#include <memory>
#include <string>

#include "json.h"

#include "../Location/location.h"
#include "../User/user.h"

#include "../../Utils/utils.h"

// Represents a result of an inline query that was chosen by the user
// and sent to their chat partner.
class ChosenInlineResult {
 public:
  ChosenInlineResult() = default;
  explicit ChosenInlineResult(const Json& chosen_inline_result);

  // The unique identifier for the result that was chosen
  std::string result_id;

  // The user that chose the result
  std::shared_ptr<User> from;

  // OPTIONAL. Sender location, only for bots that require user location
  std::shared_ptr<Location> location;

  // OPTIONAL. Identifier of the sent inline message.
  // Available only if there is an inline keyboard attached to the message.
  // Will be also received in callback queries
  // and can be used to edit the message
  std::string inline_message_id;

  // The query that was used to obtain the result
  std::string query;
};

#endif  // CHOSEN_INLINE_RESULT_H_