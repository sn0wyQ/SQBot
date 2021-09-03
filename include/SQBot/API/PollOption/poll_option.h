#ifndef POLL_OPTION_H_
#define POLL_OPTION_H_

#include <string>

#include "json.h"

#include "../../Utils/utils.h"

// This object contains information about one answer option in a poll
class PollOption {
 public:
  PollOption() = default;
  explicit PollOption(const Json& poll_option);

  // Option text, 1-100 characters
  std::string text;

  // Number of users that voted for this option
  int32_t voter_count{};
};

#endif  // POLL_OPTION_H_
