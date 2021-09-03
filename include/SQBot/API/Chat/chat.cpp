#include "chat.h"

Chat::Chat(const Json& chat)
  : id(Utils::GetValue<int64_t>(chat, "id")),
    type(Utils::GetValue<std::string>(chat, "type")),
    title(Utils::GetValue<std::string>(chat, "title")),
    username(Utils::GetValue<std::string>(chat, "username")),
    first_name(Utils::GetValue<std::string>(chat, "first_name")),
    last_name(Utils::GetValue<std::string>(chat, "last_name")),
    chat_photo(Utils::GetValue<Json>(chat, "chat_photo")),
    bio(Utils::GetValue<std::string>(chat, "bio")),
    description(Utils::GetValue<std::string>(chat, "description")),
    invite_link(Utils::GetValue<std::string>(chat, "invite_link")),
    pinned_message(Utils::GetValue<Json>(chat, "pinned_message")),
    chat_permissions(Utils::GetValue<Json>(chat, "chat_permissions")),
    slow_mode_delay(Utils::GetValue<int32_t>(chat, "slow_mode_delay")),
    message_auto_delay_time(
        Utils::GetValue<int32_t>(chat, "message_auto_delay_time")),
    sticker_set_name(Utils::GetValue<std::string>(chat, "sticker_set_name")),
    can_set_sticker_set(Utils::GetValue<bool>(chat, "can_set_sticker_set")),
    linked_chat_id(Utils::GetValue<int64_t>(chat, "linked_chat_id")),
    location(Utils::GetValue<Json>(chat, "location")) {}
