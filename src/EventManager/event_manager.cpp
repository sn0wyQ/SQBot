#include "../../include/SQBot/EventManager/event_manager.h"

#include "../../include/SQBot/Bot/bot.h"

void EventManager::CallCallbackFor(SQBot::Bot* bot, const UpdatePtr& update) {
  if (update->message) {
    auto message = update->message;

    // Firstly we check for bot_commands
    bool found_bot_command = false;
    for (const auto& entity : message->entities) {
      if (entity->type == "bot_command") {
        found_bot_command = true;
        // Trim command just to the keyword ("/start@botName" -> "start")
        std::string command =
            message->text.substr(entity->offset + 1, entity->length);
        auto find_at_symbol = command.find('@');
        if (find_at_symbol != std::string::npos) {
          command.erase(find_at_symbol);
        }

        const auto& callback_iter = callbacks_for_bot_commands_.find(command);
        if (callback_iter != callbacks_for_bot_commands_.end()) {
          callback_iter->second(bot, message);
          return;
        }
      }
    }

    // Next we check if message contained only unknown commands
    if (found_bot_command) {
      const auto& callback_for_unknown_command =
          callbacks_for_bot_commands_.find("#unknown");
      if (callback_for_unknown_command != callbacks_for_bot_commands_.end()) {
        callback_for_unknown_command->second(bot, message);
        return;
      }
    }

    // Next we check for MessageFirstWordIs
    const auto& callback_for_message_first_word_is =
        callbacks_for_message_first_word_is_.find(
            SQBot::Utils::GetFirstWord(message->text));
    if (callback_for_message_first_word_is
        != callbacks_for_message_first_word_is_.end()) {
      callback_for_message_first_word_is->second(bot, message);
      return;
    }

    // Next we check for MessageStartsWith
    auto upper_bound =
        callbacks_for_message_starts_with_.upper_bound(message->text);
    if (upper_bound != callbacks_for_message_starts_with_.begin()) {
      --upper_bound;
      if (SQBot::Utils::StartsWith(message->text, upper_bound->first)) {
        upper_bound->second(bot, message);
        return;
      }
    }

    // And if nothing called earlier we call callback to any message
    if (callback_for_message_) {
      callback_for_message_(bot, message);
    }
  } else if (update->edited_message) {
    if (callback_for_edited_message_) {
      callback_for_edited_message_(bot, update->edited_message);
    }
  } else if (update->channel_post) {
    if (callback_for_channel_post_) {
      callback_for_channel_post_(bot, update->channel_post);
    }
  } else if (update->edited_channel_post) {
    if (callback_for_edited_channel_post_) {
      callback_for_edited_channel_post_(bot, update->edited_channel_post);
    }
  } else if (update->inline_query) {
    if (callback_for_inline_query_) {
      callback_for_inline_query_(bot, update->inline_query);
    }
  } else if (update->chosen_inline_result) {
    if (callback_for_chosen_inline_result_) {
      callback_for_chosen_inline_result_(bot, update->chosen_inline_result);
    }
  } else if (update->callback_query) {
    if (callback_for_callback_query_) {
      callback_for_callback_query_(bot, update->callback_query);
    }
  } else if (update->shipping_query) {
    if (callback_for_shipping_query_) {
      callback_for_shipping_query_(bot, update->shipping_query);
    }
  } else if (update->pre_checkout_query) {
    if (callback_for_pre_checkout_query_) {
      callback_for_pre_checkout_query_(bot, update->pre_checkout_query);
    }
  } else if (update->poll) {
    if (callback_for_poll_) {
      callback_for_poll_(bot, update->poll);
    }
  } else if (update->poll_answer) {
    if (callback_for_poll_answer_) {
      callback_for_poll_answer_(bot, update->poll_answer);
    }
  } else if (update->my_chat_member) {
    if (callback_for_my_chat_member_) {
      callback_for_my_chat_member_(bot, update->my_chat_member);
    }
  } else if (update->chat_member) {
    if (callback_for_chat_member_) {
      callback_for_chat_member_(bot, update->chat_member);
    }
  }
}

void EventManager::SetCallbackForBotCommand(const std::string& command,
    std::function<void(SQBot::Bot*, const MessagePtr&)> func) {
  callbacks_for_bot_commands_[command] = std::move(func);
}

void EventManager::SetCallbackForMessageFirstWordIs(
    const std::string& first_word,
    std::function<void(SQBot::Bot*, const MessagePtr&)> func) {
  callbacks_for_message_first_word_is_[first_word] = std::move(func);
}

void EventManager::SetCallbackForMessageStartsWith(const std::string& prefix,
    std::function<void(SQBot::Bot*, const MessagePtr&)> func) {
  callbacks_for_message_starts_with_[prefix] = std::move(func);
}

void EventManager::SetCallbackForMessage(
    std::function<void(SQBot::Bot*, const MessagePtr&)> func) {
  callback_for_message_ = std::move(func);
}

void EventManager::SetCallbackForEditedMessage(
    std::function<void(SQBot::Bot*, const MessagePtr&)> func) {
  callback_for_edited_message_ = std::move(func);
}

void EventManager::SetCallbackForChannelPost(
    std::function<void(SQBot::Bot*, const MessagePtr&)> func) {
  callback_for_channel_post_ = std::move(func);
}

void EventManager::SetCallbackForEditedChannelPost(
    std::function<void(SQBot::Bot*, const MessagePtr&)> func) {
  callback_for_edited_channel_post_ = std::move(func);
}

void EventManager::SetCallbackForInlineQuery(
    std::function<void(SQBot::Bot*, const InlineQueryPtr&)> func) {
  callback_for_inline_query_ = std::move(func);
}

void EventManager::SetCallbackForChosenInlineResult(
    std::function<void(SQBot::Bot*, const ChosenInlineResultPtr&)> func) {
  callback_for_chosen_inline_result_ = std::move(func);
}

void EventManager::SetCallbackForCallbackQuery(
    std::function<void(SQBot::Bot*, const CallbackQueryPtr&)> func) {
  callback_for_callback_query_ = std::move(func);
}

void EventManager::SetCallbackForShippingQuery(
    std::function<void(SQBot::Bot*, const ShippingQueryPtr&)> func) {
  callback_for_shipping_query_ = std::move(func);
}

void EventManager::SetCallbackForPreCheckoutQuery(
    std::function<void(SQBot::Bot*, const PreCheckoutQueryPtr&)> func) {
  callback_for_pre_checkout_query_ = std::move(func);
}

void EventManager::SetCallbackForPoll(
    std::function<void(SQBot::Bot*, const PollPtr&)> func) {
  callback_for_poll_ = std::move(func);
}

void EventManager::SetCallbackForPollAnswer(
    std::function<void(SQBot::Bot*, const PollAnswerPtr&)> func) {
  callback_for_poll_answer_ = std::move(func);
}

void EventManager::SetCallbackForMyChatMember(
    std::function<void(SQBot::Bot*, const ChatMemberUpdatedPtr&)> func) {
  callback_for_my_chat_member_ = std::move(func);
}

void EventManager::SetCallbackForChatMember(
    std::function<void(SQBot::Bot*, const ChatMemberUpdatedPtr&)> func) {
  callback_for_chat_member_ = std::move(func);
}
