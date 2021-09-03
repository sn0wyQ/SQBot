#ifndef INCLUDE_SQBOT_API_CHATPERMISSIONS_CHAT_PERMISSIONS_H_
#define INCLUDE_SQBOT_API_CHATPERMISSIONS_CHAT_PERMISSIONS_H_

#include "json.h"

#include "../../Utils/utils.h"

class ChatPermissions {
 public:
  ChatPermissions() = default;
  explicit ChatPermissions(const Json& chat_permissions);

  // OPTIONAL. True, if the user is allowed to
  // send text messages, contacts, locations and venues
  bool can_send_messages;

  // OPTIONAL. True, if the user is allowed to
  // send audios, documents, photos, videos, video notes and voice notes,
  // implies can_send_messages
  bool can_send_media_messages;

  // OPTIONAL. True, if the user is allowed to send polls,
  // implies can_send_messages
  bool can_send_polls;

  // OPTIONAL. True, if the user is allowed to
  // send animations, games, stickers and use inline bots,
  // implies can_send_media_messages
  bool can_send_other_messages;

  // OPTIONAL. True, if the user is allowed to
  // add web page previews to their messages,
  // implies can_send_media_messages
  bool can_add_web_page_previews;

  // OPTIONAL. True, if the user is allowed to
  // change the chat title, photo and other settings.
  // Ignored in public supergroups
  bool can_change_info;

  // OPTIONAL. True, if the user is allowed to invite new users to the chat
  bool can_invite_users;

  // OPTIONAL. True, if the user is allowed to pin messages.
  // Ignored in public supergroups
  bool can_pin_messages;
};

#endif  // INCLUDE_SQBOT_API_CHATPERMISSIONS_CHAT_PERMISSIONS_H_
