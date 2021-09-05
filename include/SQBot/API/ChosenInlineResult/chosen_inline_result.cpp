#include "chosen_inline_result.h"

ChosenInlineResult::ChosenInlineResult(const Json& chosen_inline_result)
  : result_id(Utils::GetValue<std::string>(chosen_inline_result, "result_id")),
    from(Utils::GetPtr<User>(chosen_inline_result, "from")),
    location(Utils::GetPtr<Location>(chosen_inline_result, "location")),
    inline_message_id(Utils::GetValue<std::string>(
        chosen_inline_result, "inline_message_id")),
    query(Utils::GetValue<std::string>(chosen_inline_result, "query")) {}
