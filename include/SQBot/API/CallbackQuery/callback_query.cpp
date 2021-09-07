#include "callback_query.h"

CallbackQuery::CallbackQuery(const Json& callback_query)
  : id(SQBot::Utils::GetValue<std::string>(callback_query, "id")),
    from(SQBot::Utils::GetPtr<User>(callback_query, "from")),
    message(SQBot::Utils::GetPtr<Message>(callback_query, "message")),
    inline_message_id(SQBot::Utils::GetValue<std::string>(
        callback_query, "inline_message_id")),
    chat_instance(SQBot::Utils::GetValue<std::string>(
        callback_query, "chat_instance")),
    data(SQBot::Utils::GetValue<std::string>(callback_query, "data")),
    game_short_name(SQBot::Utils::GetValue<std::string>(
        callback_query, "game_short_name")) {}
