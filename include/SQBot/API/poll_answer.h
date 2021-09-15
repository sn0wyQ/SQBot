#ifndef INCLUDE_SQBOT_API_POLL_ANSWER_H_
#define INCLUDE_SQBOT_API_POLL_ANSWER_H_

#include <memory>
#include <string>
#include <vector>

#include "../../nlohmann/json.h"

#include "user.h"

#include "../Utils/utils.h"

// This object represents an answer of a user in a non-anonymous poll
class PollAnswer {
 public:
  PollAnswer() = default;
  explicit PollAnswer(const Json& poll_answer);

  // Unique poll identifier
  std::string poll_id;

  // The user, who changed the answer to the poll
  UserPtr user;

  // 0-based identifiers of answer options, chosen by the user.
  // May be empty if the user retracted their vote
  std::vector<int32_t> option_ids;
};

using PollAnswerPtr = std::shared_ptr<PollAnswer>;

#endif  // INCLUDE_SQBOT_API_POLL_ANSWER_H_
