#include "inline_query.h"

InlineQuery::InlineQuery(const Json& inline_query)
  : id(SQBot::Utils::GetValue<std::string>(inline_query, "id")),
    from(SQBot::Utils::GetPtr<User>(inline_query, "from")),
    query(SQBot::Utils::GetValue<std::string>(inline_query, "query")),
    offset(SQBot::Utils::GetValue<std::string>(inline_query, "offset")),
    chat_type(SQBot::Utils::GetValue<std::string>(inline_query, "chat_type")),
    location(SQBot::Utils::GetPtr<Location>(inline_query, "location")) {}
