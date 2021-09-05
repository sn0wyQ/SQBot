#include "message.h"

Message::Message(const Json& message)
  : message_id(Utils::GetValue<int32_t>(message, "message_id")),
    from(Utils::GetPtr<User>(message, "from")),
    sender_chat(Utils::GetPtr<Chat>(message, "sender_chat")),
    date(Utils::GetValue<int32_t>(message, "date")),
    chat(Utils::GetPtr<Chat>(message, "chat")),
    forward_from(Utils::GetPtr<User>(message, "forward_from")),
    forward_from_chat(Utils::GetPtr<Chat>(message, "forward_from_chat")),
    forward_from_message_id(
        Utils::GetValue<int32_t>(message, "forward_from_message_id")),
    forward_signature(
        Utils::GetValue<std::string>(message, "forward_signature")),
    forward_sender_name(
        Utils::GetValue<std::string>(message, "forward_sender_name")),
    forward_date(Utils::GetValue<int32_t>(message, "forward_date")),
    reply_to_message(Utils::GetPtr<Message>(message, "reply_to_message")),
    via_bot(Utils::GetPtr<User>(message, "via_bot")),
    edit_date(Utils::GetValue<int32_t>(message, "edit_date")),
    media_group_id(Utils::GetValue<std::string>(message, "media_group_id")),
    author_signature(Utils::GetValue<std::string>(message, "author_signature")),
    text(Utils::GetValue<std::string>(message, "text")),
    animation(Utils::GetPtr<Animation>(message, "animation")),
    audio(Utils::GetPtr<Audio>(message, "audio")),
    document(Utils::GetPtr<Document>(message, "document")),
    sticker(Utils::GetPtr<Sticker>(message, "sticker")),
    video(Utils::GetPtr<Video>(message, "video")),
    video_note(Utils::GetPtr<VideoNote>(message, "video_note")),
    voice(Utils::GetPtr<Voice>(message, "voice")),
    caption(Utils::GetValue<std::string>(message, "caption")),
    contact(Utils::GetPtr<Contact>(message, "contact")),
    dice(Utils::GetPtr<Dice>(message, "dice")),
    game(Utils::GetPtr<Game>(message, "game")),
    poll(Utils::GetPtr<Poll>(message, "poll")),
    venue(Utils::GetPtr<Venue>(message, "venue")),
    location(Utils::GetPtr<Location>(message, "location")),
    left_chat_member(Utils::GetPtr<User>(message, "left_chat_member")),
    new_chat_title(Utils::GetValue<std::string>(message, "new_chat_title")),
    delete_chat_photo(Utils::GetValue<bool>(message, "delete_chat_photo")),
    group_chat_created(Utils::GetValue<bool>(message, "group_chat_created")),
    supergroup_chat_created(
        Utils::GetValue<bool>(message, "supergroup_chat_created")),
    channel_chat_created(
        Utils::GetValue<bool>(message, "channel_chat_created")),
    message_auto_delete_timer_changed(
        Utils::GetPtr<MessageAutoDeleteTimerChanged>(
            message, "message_auto_delete_timer_changed")),
    migrate_to_chat_id(Utils::GetValue<int64_t>(message, "migrate_to_chat_id")),
    migrate_from_chat_id(
        Utils::GetValue<int64_t>(message, "migrate_from_chat_id")),
    pinned_message(Utils::GetPtr<Message>(message, "pinned_message")),
    invoice(Utils::GetPtr<Invoice>(message, "invoice")),
    successful_payment(
        Utils::GetPtr<SuccessfulPayment>(message, "successful_payment")),
    connected_website(
        Utils::GetValue<std::string>(message, "connected_website")),
    passport_data(Utils::GetPtr<PassportData>(message, "passport_data")),
    proximity_alert_triggered(
        Utils::GetPtr<ProximityAlertTriggered>(
            message, "proximity_alert_triggered")),
    voice_chat_scheduled(
        Utils::GetPtr<VoiceChatScheduled>(message, "voice_chat_scheduled")),
    voice_chat_started(
        Utils::GetPtr<VoiceChatStarted>(message, "voice_chat_started")),
    voice_chat_ended(
        Utils::GetPtr<VoiceChatEnded>(message, "voice_chat_ended")),
    voice_chat_participants_invited(
        Utils::GetPtr<VoiceChatParticipantsInvited>(
            message, "voice_chat_participants_invited")),
    reply_markup(Utils::GetPtr<InlineKeyboardMarkup>(message, "reply_markup")) {
  // TODO(sn0wyQ): set 'std::vector<MessageEntity> entities'
  // TODO(sn0wyQ): set 'std::vector<PhotoSize> photo'
  // TODO(sn0wyQ): set 'std::vector<MessageEntity> caption_entities'
  // TODO(sn0wyQ): set 'std::vector<User> new_chat_members'
  // TODO(sn0wyQ): set 'std::vector<PhotoSize> new_chat_photo'
}
