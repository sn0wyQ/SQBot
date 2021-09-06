#include "poll.h"

Poll::Poll(const Json& poll)
  : id(Utils::GetValue<std::string>(poll, "id")),
    question(Utils::GetValue<std::string>(poll, "question")),
    options(Utils::GetPtrsArray<PollOption>(poll, "options")),
    total_voter_count(Utils::GetValue<int32_t>(poll, "total_voter_count")),
    is_closed(Utils::GetValue<bool>(poll, "is_closed")),
    is_anonymous(Utils::GetValue<bool>(poll, "is_anonymous")),
    type(Utils::GetValue<std::string>(poll, "type")),
    allows_multiple_answers(
        Utils::GetValue<bool>(poll, "allows_multiple_answers")),
    correct_option_id(Utils::GetValue<int32_t>(poll, "correct_option_id")),
    explanation(Utils::GetValue<std::string>(poll, "explanation")),
    explanation_entities(
        Utils::GetPtrsArray<MessageEntity>(poll, "explanation_entities")),
    open_period(Utils::GetValue<int32_t>(poll, "open_period")),
    close_date(Utils::GetValue<int32_t>(poll, "close_date")) {}
