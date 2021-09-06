#ifndef INCLUDE_SQBOT_API_CHAT_CHAT_H_
#define INCLUDE_SQBOT_API_CHAT_CHAT_H_

#include <memory>
#include <string>

#include "../../../nlohmann/json.h"

#include "../ChatLocation/chat_location.h"
#include "../ChatPermissions/chat_permissions.h"
#include "../ChatPhoto/chat_photo.h"

#include "../../Utils/utils.h"

class Message;

// This object represents a chat
class Chat {
 public:
  Chat() = default;
  explicit Chat(const Json& chat);

  // Unique identifier for this chat
  int64_t id{};

  // Type of chat, can be either “private”, “group”, “supergroup” or “channel”
  std::string type;

  // OPTIONAL. Title, for supergroups, channels and group chats
  std::string title;

  // OPTIONAL. Username, for private chats, supergroups and channels
  // if available
  std::string username;

  // OPTIONAL. First name of the other party in a private chat
  std::string first_name;

  // OPTIONAL. Last name of the other party in a private chat
  std::string last_name;

  // OPTIONAL. Chat photo. Returned only in getChat
  std::shared_ptr<ChatPhoto> chat_photo;

  // OPTIONAL. Bio of the other party in a private chat.
  // Returned only in getChat
  std::string bio;

  // OPTIONAL. Description, for groups, supergroups and channel chats.
  // Returned only in getChat
  std::string description;

  // OPTIONAL. Primary invite link, for groups, supergroups and channel chats.
  // Returned only in getChat
  std::string invite_link;

  // OPTIONAL. The most recent pinned message (by sending date).
  // Returned only in getChat
  std::shared_ptr<Message> pinned_message;

  // OPTIONAL. Default chat member permissions, for groups and supergroups.
  // Returned only in getChat
  std::shared_ptr<ChatPermissions> chat_permissions;

  // OPTIONAL. For supergroups, the minimum allowed delay
  // between consecutive messages sent by each unprivileged user.
  // Returned only in getChat
  int32_t slow_mode_delay{};

  // OPTIONAL. The time after which all messages sent to the chat
  // will be automatically deleted; in seconds. Returned only in getChat
  int32_t message_auto_delay_time{};

  // OPTIONAL. For supergroups, name of group sticker set.
  // Returned only in getChat
  std::string sticker_set_name;

  // OPTIONAL. True, if the bot can change the group sticker set.
  // Returned only in getChat
  bool can_set_sticker_set{};

  // OPTIONAL. Unique identifier for the linked chat,
  // i.e. the discussion group identifier for a channel and vice versa;
  // for supergroups and channel chats
  int64_t linked_chat_id{};

  // OPTIONAL. For supergroups, the location to which the supergroup
  // is connected. Returned only in getChat.
  std::shared_ptr<ChatLocation> location;
};

#endif  // INCLUDE_SQBOT_API_CHAT_CHAT_H_
