#include "../../include/SQBot/API/chosen_inline_result.h"

ChosenInlineResult::ChosenInlineResult(const Json& chosen_inline_result)
  : result_id(SQBot::Utils::GetValue<std::string>(
      chosen_inline_result, "result_id")),
    from(SQBot::Utils::GetPtr<User>(chosen_inline_result, "from")),
    location(SQBot::Utils::GetPtr<Location>(chosen_inline_result, "location")),
    inline_message_id(SQBot::Utils::GetValue<std::string>(
        chosen_inline_result, "inline_message_id")),
    query(SQBot::Utils::GetValue<std::string>(chosen_inline_result, "query")) {}
