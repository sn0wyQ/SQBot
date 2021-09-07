#include "poll_answer.h"

PollAnswer::PollAnswer(const Json& poll_answer)
  : poll_id(SQBot::Utils::GetValue<std::string>(poll_answer, "poll_id")),
    user(SQBot::Utils::GetPtr<User>(poll_answer, "user")),
    option_ids(SQBot::Utils::GetValue<std::vector<int32_t>>(
        poll_answer, "option_ids")) {}
