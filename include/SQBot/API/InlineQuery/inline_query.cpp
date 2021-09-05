#include "inline_query.h"

InlineQuery::InlineQuery(const Json& inline_query)
  : id(Utils::GetValue<std::string>(inline_query, "id")),
    from(Utils::GetPtr<User>(inline_query, "from")),
    query(Utils::GetValue<std::string>(inline_query, "query")),
    offset(Utils::GetValue<std::string>(inline_query, "offset")),
    chat_type(Utils::GetValue<std::string>(inline_query, "chat_type")),
    location(Utils::GetPtr<Location>(inline_query, "location")) {}
