#ifndef INCLUDE_SQBOT_API_POLL_POLL_H_
#define INCLUDE_SQBOT_API_POLL_POLL_H_

#include <memory>
#include <string>
#include <vector>

#include "../../../nlohmann/json.h"

#include "../MessageEntity/message_entity.h"
#include "../PollOption/poll_option.h"

#include "../../Utils/utils.h"

// This object contains information about a poll
class Poll {
 public:
  Poll() = default;
  explicit Poll(const Json& poll);

  // Unique poll identifier
  std::string id;

  // Poll question, 1-300 characters
  std::string question;

  // List of poll options
  std::vector<PollOptionPtr> options;

  // Total number of users that voted in the poll
  int32_t total_voter_count{};

  // True, if the poll is closed
  bool is_closed{};

  // True, if the poll is anonymous
  bool is_anonymous{};

  // Poll type, currently can be “regular” or “quiz”
  std::string type;

  // True, if the poll allows multiple answers
  bool allows_multiple_answers{};

  // OPTIONAL. 0-based identifier of the correct answer option.
  // Available only for polls in the quiz mode, which are closed,
  // or was sent (not forwarded) by the bot or to the private chat with the bot.
  int32_t correct_option_id{};

  // OPTIONAL. Text that is shown when a user chooses an incorrect answer
  // or taps on the lamp icon in a quiz-style poll, 0-200 characters
  std::string explanation;

  // OPTIONAL. Special entities like usernames, URLs, bot commands, etc.
  // that appear in the explanation
  std::vector<MessageEntityPtr> explanation_entities;

  // OPTIONAL. Amount of time in seconds the poll will be active after creation
  int32_t open_period{};

  // OPTIONAL. Point in time (Unix timestamp)
  // when the poll will be automatically closed
  int32_t close_date{};
};

using PollPtr = std::shared_ptr<Poll>;

#endif  // INCLUDE_SQBOT_API_POLL_POLL_H_
