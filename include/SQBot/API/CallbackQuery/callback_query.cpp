#include "callback_query.h"

CallbackQuery::CallbackQuery(const Json& callback_query)
  : id(Utils::GetValue<std::string>(callback_query, "id")),
    from(Utils::GetPtr<User>(callback_query, "from")),
    message(Utils::GetPtr<Message>(callback_query, "message")),
    inline_message_id(
        Utils::GetValue<std::string>(callback_query, "inline_message_id")),
    chat_instance(
        Utils::GetValue<std::string>(callback_query, "chat_instance")),
    data(Utils::GetValue<std::string>(callback_query, "data")),
    game_short_name(
        Utils::GetValue<std::string>(callback_query, "game_short_name")) {}
