#include "message.h"

Message::Message(const Json& message)
  : message_id(Utils::GetValue<int32_t>(message, "message_id")),
    from(Utils::GetValue<Json>(message, "from")),
    sender_chat(Utils::GetValue<Json>(message, "sender_chat")),
    date(Utils::GetValue<int32_t>(message, "date")),
    chat(Utils::GetValue<Json>(message, "chat")),
    forward_from(Utils::GetValue<Json>(message, "forward_from")),
    forward_from_chat(Utils::GetValue<Json>(message, "forward_from_chat")),
    forward_from_message_id(
        Utils::GetValue<int32_t>(message, "forward_from_message_id")),
    forward_signature(
        Utils::GetValue<std::string>(message, "forward_signature")),
    forward_sender_name(
        Utils::GetValue<std::string>(message, "forward_sender_name")),
    forward_date(Utils::GetValue<int32_t>(message, "forward_date")),
    reply_to_message(Utils::GetValue<Json>(message, "reply_to_message")),
    via_bot(Utils::GetValue<Json>(message, "via_bot")),
    edit_date(Utils::GetValue<int32_t>(message, "edit_date")),
    media_group_id(Utils::GetValue<std::string>(message, "media_group_id")),
    author_signature(Utils::GetValue<std::string>(message, "author_signature")),
    text(Utils::GetValue<std::string>(message, "text")),
    animation(Utils::GetValue<Json>(message, "animation")),
    audio(Utils::GetValue<Json>(message, "audio")),
    document(Utils::GetValue<Json>(message, "document")),
    sticker(Utils::GetValue<Json>(message, "sticker")),
    video(Utils::GetValue<Json>(message, "video")),
    video_note(Utils::GetValue<Json>(message, "video_note")),
    voice(Utils::GetValue<Json>(message, "voice")),
    caption(Utils::GetValue<std::string>(message, "caption")),
    contact(Utils::GetValue<Json>(message, "contact")),
    dice(Utils::GetValue<Json>(message, "dice")),
    game(Utils::GetValue<Json>(message, "game")),
    poll(Utils::GetValue<Json>(message, "poll")),
    venue(Utils::GetValue<Json>(message, "venue")),
    location(Utils::GetValue<Json>(message, "location")),
    left_chat_member(Utils::GetValue<Json>(message, "left_chat_member")),
    new_chat_title(Utils::GetValue<Json>(message, "new_chat_title")),
    delete_chat_photo(Utils::GetValue<bool>(message, "delete_chat_photo")),
    group_chat_created(Utils::GetValue<bool>(message, "group_chat_created")),
    supergroup_chat_created(
        Utils::GetValue<bool>(message, "supergroup_chat_created")),
    channel_chat_created(
        Utils::GetValue<bool>(message, "channel_chat_created")),
    message_auto_delete_timer_changed(
        Utils::GetValue<Json>(message, "message_auto_delete_timer_changed")),
    migrate_to_chat_id(Utils::GetValue<int64_t>(message, "migrate_to_chat_id")),
    migrate_from_chat_id(
        Utils::GetValue<int64_t>(message, "migrate_from_chat_id")),
    pinned_message(Utils::GetValue<Json>(message, "pinned_message")),
    invoice(Utils::GetValue<Json>(message, "invoice")),
    successful_payment(Utils::GetValue<Json>(message, "successful_payment")),
    connected_website(
        Utils::GetValue<std::string>(message, "connected_website")),
    passport_data(Utils::GetValue<Json>(message, "passport_data")),
    proximity_alert_triggered(
        Utils::GetValue<Json>(message, "proximity_alert_triggered")),
    voice_chat_scheduled(
        Utils::GetValue<Json>(message, "voice_chat_scheduled")),
    voice_chat_started(Utils::GetValue<Json>(message, "voice_chat_started")),
    voice_chat_ended(Utils::GetValue<Json>(message, "voice_chat_ended")),
    voice_chat_participants_invited(
        Utils::GetValue<Json>(message, "voice_chat_participants_invited")),
    reply_markup(Utils::GetValue<Json>(message, "reply_markup")) {
  // TODO(sn0wyQ): set 'std::vector<MessageEntity> entities'
  // TODO(sn0wyQ): set 'std::vector<PhotoSize> photo'
  // TODO(sn0wyQ): set 'std::vector<MessageEntity> caption_entities'
  // TODO(sn0wyQ): set 'std::vector<User> new_chat_members'
  // TODO(sn0wyQ): set 'std::vector<PhotoSize> new_chat_photo'
}
