#include "poll.h"

Poll::Poll(const Json& poll)
  : id(Utils::GetValue<std::string>(poll, "id")),
    question(Utils::GetValue<std::string>(poll, "question")),
    total_voter_count(Utils::GetValue<int32_t>(poll, "total_voter_count")),
    is_closed(Utils::GetValue<bool>(poll, "is_closed")),
    is_anonymous(Utils::GetValue<bool>(poll, "is_anonymous")),
    type(Utils::GetValue<std::string>(poll, "type")),
    allows_multiple_answers(
        Utils::GetValue<bool>(poll, "allows_multiple_answers")),
    correct_option_id(Utils::GetValue<int32_t>(poll, "correct_option_id")),
    explanation(Utils::GetValue<std::string>(poll, "explanation")),
    open_period(Utils::GetValue<int32_t>(poll, "open_period")),
    close_date(Utils::GetValue<int32_t>(poll, "close_date")) {
  // TODO(sn0wyQ): set 'std::vector<PollOption> options'
  // TODO(sn0wyQ): set 'std::vector<MessageEntity> explanation_entities'
}
