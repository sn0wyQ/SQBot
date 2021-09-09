cmake_minimum_required(VERSION 3.19)
project(SQBot_example)

set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_compile_options(
        "$<$<CONFIG:RELEASE>:-O3>"
        "$<$<CONFIG:DEBUG>:-O0>"
)

# libcurl
find_package(CURL REQUIRED)

set(BOT_SOURCES
        include/SQBot/API/Animation/animation.cpp
        include/SQBot/API/Audio/audio.cpp
        include/SQBot/API/CallbackGame/callback_game.cpp
        include/SQBot/API/CallbackQuery/callback_query.cpp
        include/SQBot/API/ChatInviteLink/chat_invite_link.cpp
        include/SQBot/API/ChatLocation/chat_location.cpp
        include/SQBot/API/ChatMemberUpdated/chat_member_updated.cpp
        include/SQBot/API/ChatMember/chat_member.cpp
        include/SQBot/API/ChatPermissions/chat_permissions.cpp
        include/SQBot/API/ChatPhoto/chat_photo.cpp
        include/SQBot/API/Chat/chat.cpp
        include/SQBot/API/ChosenInlineResult/chosen_inline_result.cpp
        include/SQBot/API/Contact/contact.cpp
        include/SQBot/API/Dice/dice.cpp
        include/SQBot/API/Document/document.cpp
        include/SQBot/API/EncryptedCredentials/encrypted_credentials.cpp
        include/SQBot/API/EncryptedPassportElement/encrypted_passport_element.cpp
        include/SQBot/API/File/file.cpp
        include/SQBot/API/ForceReply/force_reply.cpp
        include/SQBot/API/Game/game.cpp
        include/SQBot/API/InlineKeyboardButton/inline_keyboard_button.cpp
        include/SQBot/API/InlineKeyboardMarkup/inline_keyboard_markup.cpp
        include/SQBot/API/InlineQuery/inline_query.cpp
        include/SQBot/API/Invoice/invoice.cpp
        include/SQBot/API/KeyboardButtonPollType/keyboard_button_poll_type.cpp
        include/SQBot/API/KeyboardButton/keyboard_button.cpp
        include/SQBot/API/Location/location.cpp
        include/SQBot/API/LoginUrl/login_url.cpp
        include/SQBot/API/MaskPosition/mask_position.cpp
        include/SQBot/API/MessageAutoDeleteTimerChanged/message_auto_delete_timer_changed.cpp
        include/SQBot/API/MessageEntity/message_entity.cpp
        include/SQBot/API/MessageId/message_id.cpp
        include/SQBot/API/Message/message.cpp
        include/SQBot/API/OrderInfo/order_info.cpp
        include/SQBot/API/PassportData/passport_data.cpp
        include/SQBot/API/PassportFile/passport_file.cpp
        include/SQBot/API/PhotoSize/photo_size.cpp
        include/SQBot/API/PollAnswer/poll_answer.cpp
        include/SQBot/API/PollOption/poll_option.cpp
        include/SQBot/API/Poll/poll.cpp
        include/SQBot/API/PreCheckoutQuery/pre_checkout_query.cpp
        include/SQBot/API/ProximityAlertTriggered/proximity_alert_triggered.cpp
        include/SQBot/API/ReplyKeyboardMarkup/reply_keyboard_markup.cpp
        include/SQBot/API/ReplyKeyboardRemove/reply_keyboard_remove.cpp
        include/SQBot/API/ShippingAddress/shipping_address.cpp
        include/SQBot/API/ShippingQuery/shipping_query.cpp
        include/SQBot/API/Sticker/sticker.cpp
        include/SQBot/API/SuccessfulPayment/successful_payment.cpp
        include/SQBot/API/Update/update.cpp
        include/SQBot/API/UserProfilePhotos/user_profile_photos.cpp
        include/SQBot/API/User/user.cpp
        include/SQBot/API/Video/video.cpp
        include/SQBot/API/VideoNote/video_note.cpp
        include/SQBot/API/VoiceChatEnded/voice_chat_ended.cpp
        include/SQBot/API/VoiceChatParticipantsInvited/voice_chat_participants_invited.cpp
        include/SQBot/API/VoiceChatScheduled/voice_chat_scheduled.cpp
        include/SQBot/API/VoiceChatStarted/voice_chat_started.cpp
        include/SQBot/API/Voice/voice.cpp
        include/SQBot/API/Venue/venue.cpp
        include/SQBot/AbstractReplyMarkup/abstract_reply_markup.h
        include/SQBot/Bot/bot.cpp
        include/SQBot/EventManager/event_manager.cpp
        include/SQBot/Exception/exception.cpp
        include/SQBot/Utils/utils.cpp
        include/SQBot/InputFile/input_file.cpp include/SQBot/InputFile/input_file.h)

set(LIBS
        ${CURL_LIBRARY})

add_executable(EchoBotExample examples/echo_bot.cpp ${BOT_SOURCES})
target_link_libraries(EchoBotExample ${LIBS})

include_directories(${CURL_INCLUDE_DIR})
include_directories(include)
