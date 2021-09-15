#include "../../include/SQBot/API/chat.h"

#include "../../include/SQBot/API/message.h"

Chat::Chat(const Json& chat)
  : id(SQBot::Utils::GetValue<int64_t>(chat, "id")),
    type(SQBot::Utils::GetValue<std::string>(chat, "type")),
    title(SQBot::Utils::GetValue<std::string>(chat, "title")),
    username(SQBot::Utils::GetValue<std::string>(chat, "username")),
    first_name(SQBot::Utils::GetValue<std::string>(chat, "first_name")),
    last_name(SQBot::Utils::GetValue<std::string>(chat, "last_name")),
    chat_photo(SQBot::Utils::GetPtr<ChatPhoto>(chat, "chat_photo")),
    bio(SQBot::Utils::GetValue<std::string>(chat, "bio")),
    description(SQBot::Utils::GetValue<std::string>(chat, "description")),
    invite_link(SQBot::Utils::GetValue<std::string>(chat, "invite_link")),
    pinned_message(SQBot::Utils::GetPtr<Message>(chat, "pinned_message")),
    chat_permissions(SQBot::Utils::GetPtr<ChatPermissions>(
        chat, "chat_permissions")),
    slow_mode_delay(SQBot::Utils::GetValue<int32_t>(chat, "slow_mode_delay")),
    message_auto_delay_time(SQBot::Utils::GetValue<int32_t>(
        chat, "message_auto_delay_time")),
    sticker_set_name(SQBot::Utils::GetValue<std::string>(
        chat, "sticker_set_name")),
    can_set_sticker_set(SQBot::Utils::GetValue<bool>(
        chat, "can_set_sticker_set")),
    linked_chat_id(SQBot::Utils::GetValue<int64_t>(chat, "linked_chat_id")),
    location(SQBot::Utils::GetPtr<ChatLocation>(chat, "location")) {}
