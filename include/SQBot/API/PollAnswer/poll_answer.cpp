#include "poll_answer.h"

PollAnswer::PollAnswer(const Json& poll_answer)
  : poll_id(Utils::GetValue<std::string>(poll_answer, "poll_id")),
    user(Utils::GetPtr<User>(poll_answer, "user")),
    option_ids(
        Utils::GetValue<std::vector<int32_t>>(poll_answer, "option_ids")) {}
