cmake_minimum_required(VERSION 3.19)
project(SQBot_example)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(
        "$<$<CONFIG:RELEASE>:-O3>"
        "$<$<CONFIG:DEBUG>:-O0>"
)

# libcurl
find_package(CURL REQUIRED)

set(SOURCES
        include/SQBot/API/Animation/animation.cpp
        include/SQBot/API/Audio/audio.cpp
        include/SQBot/API/ChatLocation/chat_location.cpp
        include/SQBot/API/ChatPermissions/chat_permissions.cpp
        include/SQBot/API/ChatPhoto/chat_photo.cpp
        include/SQBot/API/Chat/chat.cpp
        include/SQBot/API/Contact/contact.cpp
        include/SQBot/API/Dice/dice.cpp
        include/SQBot/API/Document/document.cpp
        include/SQBot/API/EncryptedCredentials/encrypted_credentials.cpp
        include/SQBot/API/EncryptedPassportElement/encrypted_passport_element.cpp
        include/SQBot/API/Game/game.cpp
        include/SQBot/API/InlineKeyboardButton/inline_keyboard_button.cpp
        include/SQBot/API/InlineKeyboardMarkup/inline_keyboard_markup.cpp
        include/SQBot/API/Invoice/invoice.cpp
        include/SQBot/API/Location/location.cpp
        include/SQBot/API/MaskPosition/mask_position.cpp
        include/SQBot/API/MessageAutoDeleteTimerChanged/message_auto_delete_timer_changed.cpp
        include/SQBot/API/MessageEntity/message_entity.cpp
        include/SQBot/API/MessageId/message_id.cpp
        include/SQBot/API/Message/message.cpp
        include/SQBot/API/OrderInfo/order_info.cpp
        include/SQBot/API/PassportData/passport_data.cpp
        include/SQBot/API/PassportFile/passport_file.cpp
        include/SQBot/API/PhotoSize/photo_size.cpp
        include/SQBot/API/PollOption/poll_option.cpp
        include/SQBot/API/Poll/poll.cpp
        include/SQBot/API/ProximityAlertTriggered/proximity_alert_triggered.cpp
        include/SQBot/API/ShippingAddress/shipping_address.cpp
        include/SQBot/API/Sticker/sticker.cpp
        include/SQBot/API/SuccessfulPayment/successful_payment.cpp
        include/SQBot/API/User/user.cpp
        include/SQBot/API/Video/video.cpp
        include/SQBot/API/VideoNote/video_note.cpp
        include/SQBot/API/VoiceChatEnded/voice_chat_ended.cpp
        include/SQBot/API/VoiceChatParticipantsInvited/voice_chat_participants_invited.cpp
        include/SQBot/API/VoiceChatScheduled/voice_chat_scheduled.cpp
        include/SQBot/API/VoiceChatStarted/voice_chat_started.cpp
        include/SQBot/API/Voice/voice.cpp
        include/SQBot/API/Venue/venue.cpp
        include/SQBot/Bot/bot.cpp
        include/SQBot/Utils/utils.h
        )

set(LIBS
        ${CURL_LIBRARY})

add_executable(SQBot_example example.cpp ${SOURCES})
target_link_libraries(SQBot_example ${LIBS})

target_include_directories(SQBot_example PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/SQBot>
        $<INSTALL_INTERFACE:include/SQBot>
        )
target_include_directories(SQBot_example PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/nlohmann>
        $<INSTALL_INTERFACE:include/nlohmann>
        )
include_directories(${CURL_INCLUDE_DIR})
