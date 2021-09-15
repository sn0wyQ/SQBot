#include "../../include/SQBot/API/chat_permissions.h"

ChatPermissions::ChatPermissions(const Json& chat_permissions)
  : can_send_messages(SQBot::Utils::GetValue<bool>(
        chat_permissions, "can_send_messages")),
    can_send_media_messages(SQBot::Utils::GetValue<bool>(
        chat_permissions, "can_send_media_messages")),
    can_send_polls(SQBot::Utils::GetValue<bool>(
        chat_permissions, "can_send_polls")),
    can_send_other_messages(SQBot::Utils::GetValue<bool>(
        chat_permissions, "can_send_other_messages")),
    can_add_web_page_previews(SQBot::Utils::GetValue<bool>(
        chat_permissions, "can_add_web_page_previews")),
    can_change_info(SQBot::Utils::GetValue<bool>(
        chat_permissions, "can_change_info")),
    can_invite_users(SQBot::Utils::GetValue<bool>(
        chat_permissions, "can_invite_users")),
    can_pin_messages(SQBot::Utils::GetValue<bool>(
        chat_permissions, "can_pin_messages")) {}
