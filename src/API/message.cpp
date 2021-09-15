#include "../../include/SQBot/API/message.h"

Message::Message(const Json& message)
  : message_id(SQBot::Utils::GetValue<int32_t>(message, "message_id")),
    from(SQBot::Utils::GetPtr<User>(message, "from")),
    sender_chat(SQBot::Utils::GetPtr<Chat>(message, "sender_chat")),
    date(SQBot::Utils::GetValue<int32_t>(message, "date")),
    chat(SQBot::Utils::GetPtr<Chat>(message, "chat")),
    forward_from(SQBot::Utils::GetPtr<User>(message, "forward_from")),
    forward_from_chat(SQBot::Utils::GetPtr<Chat>(message, "forward_from_chat")),
    forward_from_message_id(SQBot::Utils::GetValue<int32_t>(
        message, "forward_from_message_id")),
    forward_signature(SQBot::Utils::GetValue<std::string>(
        message, "forward_signature")),
    forward_sender_name(SQBot::Utils::GetValue<std::string>(
        message, "forward_sender_name")),
    forward_date(SQBot::Utils::GetValue<int32_t>(message, "forward_date")),
    reply_to_message(SQBot::Utils::GetPtr<Message>(
        message, "reply_to_message")),
    via_bot(SQBot::Utils::GetPtr<User>(message, "via_bot")),
    edit_date(SQBot::Utils::GetValue<int32_t>(message, "edit_date")),
    media_group_id(SQBot::Utils::GetValue<std::string>(
        message, "media_group_id")),
    author_signature(SQBot::Utils::GetValue<std::string>(
        message, "author_signature")),
    text(SQBot::Utils::GetValue<std::string>(message, "text")),
    entities(SQBot::Utils::GetPtrsArray<MessageEntity>(message, "entities")),
    animation(SQBot::Utils::GetPtr<Animation>(message, "animation")),
    audio(SQBot::Utils::GetPtr<Audio>(message, "audio")),
    document(SQBot::Utils::GetPtr<Document>(message, "document")),
    photo(SQBot::Utils::GetPtrsArray<PhotoSize>(message, "photo")),
    sticker(SQBot::Utils::GetPtr<Sticker>(message, "sticker")),
    video(SQBot::Utils::GetPtr<Video>(message, "video")),
    video_note(SQBot::Utils::GetPtr<VideoNote>(message, "video_note")),
    voice(SQBot::Utils::GetPtr<Voice>(message, "voice")),
    caption(SQBot::Utils::GetValue<std::string>(message, "caption")),
    caption_entities(SQBot::Utils::GetPtrsArray<MessageEntity>(
        message, "caption_entities")),
    contact(SQBot::Utils::GetPtr<Contact>(message, "contact")),
    dice(SQBot::Utils::GetPtr<Dice>(message, "dice")),
    game(SQBot::Utils::GetPtr<Game>(message, "game")),
    poll(SQBot::Utils::GetPtr<Poll>(message, "poll")),
    venue(SQBot::Utils::GetPtr<Venue>(message, "venue")),
    location(SQBot::Utils::GetPtr<Location>(message, "location")),
    new_chat_members(SQBot::Utils::GetPtrsArray<User>(
        message, "new_chat_members")),
    left_chat_member(SQBot::Utils::GetPtr<User>(message, "left_chat_member")),
    new_chat_title(SQBot::Utils::GetValue<std::string>(
        message, "new_chat_title")),
    new_chat_photo(SQBot::Utils::GetPtrsArray<PhotoSize>(
        message, "new_chat_photo")),
    delete_chat_photo(SQBot::Utils::GetValue<bool>(
        message, "delete_chat_photo")),
    group_chat_created(SQBot::Utils::GetValue<bool>(
        message, "group_chat_created")),
    supergroup_chat_created(SQBot::Utils::GetValue<bool>(
        message, "supergroup_chat_created")),
    channel_chat_created(SQBot::Utils::GetValue<bool>(
        message, "channel_chat_created")),
    message_auto_delete_timer_changed(
        SQBot::Utils::GetPtr<MessageAutoDeleteTimerChanged>(
            message, "message_auto_delete_timer_changed")),
    migrate_to_chat_id(SQBot::Utils::GetValue<int64_t>(
        message, "migrate_to_chat_id")),
    migrate_from_chat_id(SQBot::Utils::GetValue<int64_t>(
        message, "migrate_from_chat_id")),
    pinned_message(SQBot::Utils::GetPtr<Message>(message, "pinned_message")),
    invoice(SQBot::Utils::GetPtr<Invoice>(message, "invoice")),
    successful_payment(SQBot::Utils::GetPtr<SuccessfulPayment>(
        message, "successful_payment")),
    connected_website(SQBot::Utils::GetValue<std::string>(
        message, "connected_website")),
    passport_data(SQBot::Utils::GetPtr<PassportData>(message, "passport_data")),
    proximity_alert_triggered(SQBot::Utils::GetPtr<ProximityAlertTriggered>(
            message, "proximity_alert_triggered")),
    voice_chat_scheduled(SQBot::Utils::GetPtr<VoiceChatScheduled>(
        message, "voice_chat_scheduled")),
    voice_chat_started(SQBot::Utils::GetPtr<VoiceChatStarted>(
        message, "voice_chat_started")),
    voice_chat_ended(SQBot::Utils::GetPtr<VoiceChatEnded>(
        message, "voice_chat_ended")),
    voice_chat_participants_invited(
        SQBot::Utils::GetPtr<VoiceChatParticipantsInvited>(
            message, "voice_chat_participants_invited")),
    reply_markup(SQBot::Utils::GetPtr<InlineKeyboardMarkup>(
        message, "reply_markup")) {}
