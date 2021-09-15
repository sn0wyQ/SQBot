#ifndef INCLUDE_SQBOT_API_CHOSENINLINERESULT_CHOSEN_INLINE_RESULT_H_
#define INCLUDE_SQBOT_API_CHOSENINLINERESULT_CHOSEN_INLINE_RESULT_H_

#include <memory>
#include <string>

#include "../../nlohmann/json.h"

#include "location.h"
#include "user.h"

#include "../Utils/utils.h"

// Represents a result of an inline query that was chosen by the user
// and sent to their chat partner.
class ChosenInlineResult {
 public:
  ChosenInlineResult() = default;
  explicit ChosenInlineResult(const Json& chosen_inline_result);

  // The unique identifier for the result that was chosen
  std::string result_id;

  // The user that chose the result
  UserPtr from;

  // OPTIONAL. Sender location, only for bots that require user location
  LocationPtr location;

  // OPTIONAL. Identifier of the sent inline message.
  // Available only if there is an inline keyboard attached to the message.
  // Will be also received in callback queries
  // and can be used to edit the message
  std::string inline_message_id;

  // The query that was used to obtain the result
  std::string query;
};

using ChosenInlineResultPtr = std::shared_ptr<ChosenInlineResult>;

#endif  // INCLUDE_SQBOT_API_CHOSENINLINERESULT_CHOSEN_INLINE_RESULT_H_
