#include "../../include/SQBot/API/poll_option.h"

PollOption::PollOption(const Json& poll_option)
  : text(SQBot::Utils::GetValue<std::string>(poll_option, "text")),
    voter_count(SQBot::Utils::GetValue<int32_t>(poll_option, "voter_count")) {}
