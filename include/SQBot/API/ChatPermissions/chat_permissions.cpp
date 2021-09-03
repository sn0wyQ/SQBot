#include "chat_permissions.h"

ChatPermissions::ChatPermissions(const Json& chat_permissions)
  : can_send_messages(
      Utils::GetValue<bool>(chat_permissions, "can_send_messages")),
    can_send_media_messages(
        Utils::GetValue<bool>(chat_permissions, "can_send_media_messages")),
    can_send_polls(Utils::GetValue<bool>(chat_permissions, "can_send_polls")),
    can_send_other_messages(
        Utils::GetValue<bool>(chat_permissions, "can_send_other_messages")),
    can_add_web_page_previews(
        Utils::GetValue<bool>(chat_permissions, "can_add_web_page_previews")),
    can_change_info(Utils::GetValue<bool>(chat_permissions, "can_change_info")),
    can_invite_users(
        Utils::GetValue<bool>(chat_permissions, "can_invite_users")),
    can_pin_messages(
        Utils::GetValue<bool>(chat_permissions, "can_pin_messages")) {}
