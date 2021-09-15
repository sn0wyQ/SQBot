#ifndef INCLUDE_SQBOT_API_MESSAGE_MESSAGE_H_
#define INCLUDE_SQBOT_API_MESSAGE_MESSAGE_H_

#include <memory>
#include <string>
#include <vector>

#include "../../nlohmann/json.h"

#include "animation.h"
#include "audio.h"
#include "chat.h"
#include "contact.h"
#include "dice.h"
#include "document.h"
#include "game.h"
#include "inline_keyboard_markup.h"
#include "invoice.h"
#include "location.h"
#include "message_auto_delete_timer_changed.h"
#include "message_entity.h"
#include "message.h"
#include "passport_data.h"
#include "proximity_alert_triggered.h"
#include "photo_size.h"
#include "poll.h"
#include "sticker.h"
#include "successful_payment.h"
#include "user.h"
#include "venue.h"
#include "video.h"
#include "video_note.h"
#include "voice_chat_ended.h"
#include "voice_chat_participants_invited.h"
#include "voice_chat_scheduled.h"
#include "voice_chat_started.h"
#include "voice.h"

#include "../Utils/utils.h"

// This object represents a message
class Message {
 public:
  Message() = default;
  explicit Message(const Json& message);

  // Unique message identifier inside this chat
  int32_t message_id{};

  // OPTIONAL. Sender, empty for messages sent to channels
  UserPtr from;

  // OPTIONAL. Sender of the message, sent on behalf of a chat.
  // The channel itself for channel messages.
  // The supergroup itself for messages from anonymous group administrators.
  // The linked channel for messages automatically
  // forwarded to the discussion group
  ChatPtr sender_chat;

  // Date the message was sent in Unix time
  int32_t date{};

  // Conversation the message belongs to
  ChatPtr chat;

  // OPTIONAL. For forwarded messages, sender of the original message
  UserPtr forward_from;

  // OPTIONAL. For messages forwarded from channels or
  // from anonymous administrators, information about the original sender chat
  ChatPtr forward_from_chat;

  // OPTIONAL. For messages forwarded from channels, identifier of the original
  // message in the channel
  int32_t forward_from_message_id{};

  // OPTIONAL. For messages forwarded from channels,
  // signature of the post author if present
  std::string forward_signature;

  // OPTIONAL. Sender's name for messages forwarded from users
  // who disallow adding a link to their account in forwarded messages
  std::string forward_sender_name;

  // OPTIONAL. For forwarded messages, date the original message was sent
  // in Unix time
  int32_t forward_date{};

  // OPTIONAL. For replies, the original message.
  // Note that the Message object in this field will not contain further
  // reply_to_message fields even if it itself is a reply
  std::shared_ptr<Message> reply_to_message;

  // OPTIONAL. Bot through which the message was sent
  UserPtr via_bot;

  // OPTIONAL. Date the message was last edited in Unix time
  int32_t edit_date{};

  // OPTIONAL. The unique identifier of a media message group
  // this message belongs to
  std::string media_group_id;

  // OPTIONAL. Signature of the post author for messages in channels,
  // or the custom title of an anonymous group administrator
  std::string author_signature;

  // OPTIONAL. For text messages, the actual UTF-8 text of the message,
  // 0-4096 characters
  std::string text;

  // OPTIONAL. For text messages, special entities like usernames, URLs,
  // bot commands, etc. that appear in the text
  std::vector<MessageEntityPtr> entities;

  // OPTIONAL. Message is an animation, information about the animation.
  // For backward compatibility, when this field is set,
  // the document field will also be set
  AnimationPtr animation;

  // OPTIONAL. Message is an audio file, information about the file
  AudioPtr audio;

  // OPTIONAL. Message is a general file, information about the file
  DocumentPtr document;

  // OPTIONAL. Message is a photo, available sizes of the photo
  std::vector<PhotoSizePtr> photo;

  // OPTIONAL. Message is a sticker, information about the sticker
  StickerPtr sticker;

  // OPTIONAL. Message is a video, information about the video
  VideoPtr video;

  // OPTIONAL. Message is a video note, information about the video message
  VideoNotePtr video_note;

  // OPTIONAL. Message is a voice message, information about the file
  VoicePtr voice;

  // OPTIONAL. Caption for the animation, audio, document, photo,
  // video or voice, 0-1024 characters
  std::string caption;

  // OPTIONAL. For messages with a caption, special entities like
  // usernames, URLs, bot commands, etc. that appear in the caption
  std::vector<MessageEntityPtr> caption_entities;

  // OPTIONAL. Message is a shared contact, information about the contact
  ContactPtr contact;

  // OPTIONAL. Message is a dice with random value
  DicePtr dice;

  // OPTIONAL. Message is a game, information about the game
  GamePtr game;

  // OPTIONAL. Message is a native poll, information about the poll
  PollPtr poll;

  // OPTIONAL. Message is a venue, information about the venue.
  // For backward compatibility, when this field is set,
  // the location field will also be set
  VenuePtr venue;

  // OPTIONAL. Message is a shared location, information about the location
  LocationPtr location;

  // OPTIONAL. New members that were added to the group or
  // supergroup and information about them
  // (the bot itself may be one of these members)
  std::vector<UserPtr> new_chat_members;

  // OPTIONAL. A member was removed from the group, information about them
  // (this member may be the bot itself)
  UserPtr left_chat_member;

  // OPTIONAL. A chat title was changed to this value
  std::string new_chat_title;

  // OPTIONAL. A chat photo was change to this value
  std::vector<PhotoSizePtr> new_chat_photo;

  // OPTIONAL. Service message: the chat photo was deleted
  bool delete_chat_photo{false};

  // OPTIONAL. Service message: the group has been created
  bool group_chat_created{false};

  // OPTIONAL. Service message: the supergroup has been created.
  // This field can't be received in a message coming through updates,
  // because bot can't be a member of a supergroup when it is created.
  // It can only be found in reply_to_message if someone replies to
  // a very first message in a directly created supergroup
  bool supergroup_chat_created{false};

  // OPTIONAL. Service message: the channel has been created.
  // This field can't be received in a message coming through updates,
  // because bot can't be a member of a channel when it is created.
  // It can only be found in reply_to_message if someone replies to
  // a very first message in a channel
  bool channel_chat_created{false};

  // OPTIONAL. Service message: auto-delete timer settings changed in the chat
  MessageAutoDeleteTimerChangedPtr message_auto_delete_timer_changed;

  // OPTIONAL. The group has been migrated to a supergroup
  // with the specified identifier
  int64_t migrate_to_chat_id{};

  // OPTIONAL. The supergroup has been migrated from a group
  // with the specified identifier
  int64_t migrate_from_chat_id{};

  // OPTIONAL. Specified message was pinned.
  // Note that the Message object in this field will not contain
  // further reply_to_message fields even if it is itself a reply
  std::shared_ptr<Message> pinned_message;

  // OPTIONAL. Message is an invoice for a payment,
  // information about the invoice
  InvoicePtr invoice;

  // OPTIONAL. Message is a service message about a successful payment,
  // information about the payment
  SuccessfulPaymentPtr successful_payment;

  // OPTIONAL. The domain name of the website on which the user has logged in
  std::string connected_website;

  // OPTIONAL. Telegram Passport data
  PassportDataPtr passport_data;

  // OPTIONAL. Service message. A user in the chat triggered
  // another user's proximity alert while sharing Live Location
  ProximityAlertTriggeredPtr proximity_alert_triggered;

  // OPTIONAL. Service message: voice chat scheduled
  VoiceChatScheduledPtr voice_chat_scheduled;

  // OPTIONAL. Service message: voice chat started
  VoiceChatStartedPtr voice_chat_started;

  // OPTIONAL. Service message: voice chat ended
  VoiceChatEndedPtr voice_chat_ended;

  // OPTIONAL. Service message: new participants invited to a voice chat
  VoiceChatParticipantsInvitedPtr voice_chat_participants_invited;

  // OPTIONAL. Inline keyboard attached to the message.
  // login_url buttons are represented as ordinary url buttons
  InlineKeyboardMarkupPtr reply_markup;
};

using MessagePtr = std::shared_ptr<Message>;

#endif  // INCLUDE_SQBOT_API_MESSAGE_MESSAGE_H_
