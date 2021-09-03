#include "poll_option.h"

PollOption::PollOption(const Json& poll_option)
  : text(Utils::GetValue<std::string>(poll_option, "text")),
    voter_count(Utils::GetValue<int32_t>(poll_option, "voter_count")) {}
