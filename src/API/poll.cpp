#include "../../include/SQBot/API/poll.h"

Poll::Poll(const Json& poll)
  : id(SQBot::Utils::GetValue<std::string>(poll, "id")),
    question(SQBot::Utils::GetValue<std::string>(poll, "question")),
    options(SQBot::Utils::GetPtrsArray<PollOption>(poll, "options")),
    total_voter_count(SQBot::Utils::GetValue<int32_t>(
        poll, "total_voter_count")),
    is_closed(SQBot::Utils::GetValue<bool>(poll, "is_closed")),
    is_anonymous(SQBot::Utils::GetValue<bool>(poll, "is_anonymous")),
    type(SQBot::Utils::GetValue<std::string>(poll, "type")),
    allows_multiple_answers(SQBot::Utils::GetValue<bool>(
        poll, "allows_multiple_answers")),
    correct_option_id(SQBot::Utils::GetValue<int32_t>(
        poll, "correct_option_id")),
    explanation(SQBot::Utils::GetValue<std::string>(poll, "explanation")),
    explanation_entities(SQBot::Utils::GetPtrsArray<MessageEntity>(
        poll, "explanation_entities")),
    open_period(SQBot::Utils::GetValue<int32_t>(poll, "open_period")),
    close_date(SQBot::Utils::GetValue<int32_t>(poll, "close_date")) {}
