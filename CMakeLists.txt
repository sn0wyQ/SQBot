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
        src/API/animation.cpp
        src/API/audio.cpp
        src/API/callback_game.cpp
        src/API/callback_query.cpp
        src/API/chat_invite_link.cpp
        src/API/chat_location.cpp
        src/API/chat_member_updated.cpp
        src/API/chat_member.cpp
        src/API/chat_permissions.cpp
        src/API/chat_photo.cpp
        src/API/chat.cpp
        src/API/chosen_inline_result.cpp
        src/API/contact.cpp
        src/API/dice.cpp
        src/API/document.cpp
        src/API/encrypted_credentials.cpp
        src/API/encrypted_passport_element.cpp
        src/API/file.cpp
        src/API/force_reply.cpp
        src/API/game.cpp
        src/API/inline_keyboard_button.cpp
        src/API/inline_keyboard_markup.cpp
        src/API/inline_query.cpp
        src/API/invoice.cpp
        src/API/keyboard_button_poll_type.cpp
        src/API/keyboard_button.cpp
        src/API/location.cpp
        src/API/login_url.cpp
        src/API/mask_position.cpp
        src/API/message_auto_delete_timer_changed.cpp
        src/API/message_entity.cpp
        src/API/message_id.cpp
        src/API/message.cpp
        src/API/order_info.cpp
        src/API/passport_data.cpp
        src/API/passport_file.cpp
        src/API/photo_size.cpp
        src/API/poll_answer.cpp
        src/API/poll_option.cpp
        src/API/poll.cpp
        src/API/pre_checkout_query.cpp
        src/API/proximity_alert_triggered.cpp
        src/API/reply_keyboard_markup.cpp
        src/API/reply_keyboard_remove.cpp
        src/API/shipping_address.cpp
        src/API/shipping_query.cpp
        src/API/sticker.cpp
        src/API/successful_payment.cpp
        src/API/update.cpp
        src/API/user_profile_photos.cpp
        src/API/user.cpp
        src/API/video.cpp
        src/API/video_note.cpp
        src/API/voice_chat_ended.cpp
        src/API/voice_chat_participants_invited.cpp
        src/API/voice_chat_scheduled.cpp
        src/API/voice_chat_started.cpp
        src/API/voice.cpp
        src/API/venue.cpp

        include/SQBot/AbstractReplyMarkup/abstract_reply_markup.h
        src/EventManager/event_manager.cpp
        src/Exception/exception.cpp
        src/InputFile/input_file.cpp
        src/Utils/utils.cpp
        src/Bot/bot.cpp
        include/SQBot/API/chat_member_updated.h)

set(LIBS
        ${CURL_LIBRARY})

add_executable(EchoBotExample examples/echo_bot.cpp ${BOT_SOURCES})
target_link_libraries(EchoBotExample ${LIBS})

include_directories(${CURL_INCLUDE_DIR})
include_directories(include)
