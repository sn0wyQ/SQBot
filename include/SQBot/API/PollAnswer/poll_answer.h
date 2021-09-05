#ifndef POLL_ANSWER_H_
#define POLL_ANSWER_H_

#include <memory>
#include <string>
#include <vector>

#include "json.h"

#include "../User/user.h"

#include "../../Utils/utils.h"

// This object represents an answer of a user in a non-anonymous poll
class PollAnswer {
 public:
  PollAnswer() = default;
  explicit PollAnswer(const Json& poll_answer);

  // Unique poll identifier
  std::string poll_id;

  // The user, who changed the answer to the poll
  std::shared_ptr<User> user;

  // 0-based identifiers of answer options, chosen by the user.
  // May be empty if the user retracted their vote
  std::vector<int32_t> option_ids;
};

#endif  // POLL_ANSWER_H_
