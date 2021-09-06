#include "event_manager.h"

#include "../Bot/bot.h"

void EventManager::CallCallbackFor(SQBot::Bot* bot,
                                   const std::shared_ptr<Update>& update) {
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

        const auto& callback_iter = callbacks_to_bot_commands_.find(command);
        if (callback_iter != callbacks_to_bot_commands_.end()) {
          callback_iter->second(bot, message);
          return;
        }
      }
    }

    // Next we check if message contained only unknown commands
    if (found_bot_command) {
      const auto& callback_for_unknown_command =
          callbacks_to_bot_commands_.find("#unknown");
      if (callback_for_unknown_command != callbacks_to_bot_commands_.end()) {
        callback_for_unknown_command->second(bot, message);
        return;
      }
    }

    // Next we check for kMessageStartsWith
    auto upper_bound =
        callbacks_to_message_starts_with_.upper_bound(message->text);
    if (upper_bound != callbacks_to_message_starts_with_.begin()) {
      --upper_bound;
      if (Utils::StartsWith(message->text, upper_bound->first)) {
        upper_bound->second(bot, message);
        return;
      }
    }

    if (callback_to_message_) {
      callback_to_message_(bot, message);
    }
  } else if (update->edited_message) {
    if (callback_to_edited_message_) {
      callback_to_edited_message_(bot, update->edited_message);
    }
  } else if (update->channel_post) {
    if (callback_to_channel_post_) {
      callback_to_channel_post_(bot, update->channel_post);
    }
  } else if (update->edited_channel_post) {
    if (callback_to_edited_channel_post_) {
      callback_to_edited_channel_post_(bot, update->edited_channel_post);
    }
  } else if (update->inline_query) {
    if (callback_to_inline_query_) {
      callback_to_inline_query_(bot, update->inline_query);
    }
  } else if (update->chosen_inline_result) {
    if (callback_to_chosen_inline_result_) {
      callback_to_chosen_inline_result_(bot, update->chosen_inline_result);
    }
  } else if (update->callback_query) {
    if (callback_to_callback_query_) {
      callback_to_callback_query_(bot, update->callback_query);
    }
  } else if (update->shipping_query) {
    if (callback_to_shipping_query_) {
      callback_to_shipping_query_(bot, update->shipping_query);
    }
  } else if (update->pre_checkout_query) {
    if (callback_to_pre_checkout_query_) {
      callback_to_pre_checkout_query_(bot, update->pre_checkout_query);
    }
  } else if (update->poll) {
    if (callback_to_poll_) {
      callback_to_poll_(bot, update->poll);
    }
  } else if (update->poll_answer) {
    if (callback_to_poll_answer_) {
      callback_to_poll_answer_(bot, update->poll_answer);
    }
  } else if (update->my_chat_member) {
    if (callback_to_my_chat_member_) {
      callback_to_my_chat_member_(bot, update->my_chat_member);
    }
  } else if (update->chat_member) {
    if (callback_to_chat_member_) {
      callback_to_chat_member_(bot, update->chat_member);
    }
  }
}

void EventManager::SetCallbackForBotCommand(const std::string& command,
    std::function<void(SQBot::Bot*, const std::shared_ptr<Message>&)> func) {
  callbacks_to_bot_commands_[command] = std::move(func);
}

void EventManager::SetCallbackForMessageStartsWith(const std::string& prefix,
    std::function<void(SQBot::Bot*, const std::shared_ptr<Message>&)> func) {
  callbacks_to_message_starts_with_[prefix] = std::move(func);
}

void EventManager::SetCallbackForMessage(
    std::function<void(SQBot::Bot*, const std::shared_ptr<Message>&)> func) {
  callback_to_message_ = std::move(func);
}

void EventManager::SetCallbackForEditedMessage(
    std::function<void(SQBot::Bot*, const std::shared_ptr<Message>&)> func) {
  callback_to_edited_message_ = std::move(func);
}

void EventManager::SetCallbackForChannelPost(
    std::function<void(SQBot::Bot*, const std::shared_ptr<Message>&)> func) {
  callback_to_channel_post_ = std::move(func);
}

void EventManager::SetCallbackForEditedChannelPost(
    std::function<void(SQBot::Bot*, const std::shared_ptr<Message>&)> func) {
  callback_to_edited_channel_post_ = std::move(func);
}

void EventManager::SetCallbackForInlineQuery(
    std::function<void(SQBot::Bot*,
        const std::shared_ptr<InlineQuery>&)> func) {
  callback_to_inline_query_ = std::move(func);
}

void EventManager::SetCallbackForChosenInlineResult(
    std::function<void(SQBot::Bot*,
        const std::shared_ptr<ChosenInlineResult>&)> func) {
  callback_to_chosen_inline_result_ = std::move(func);
}

void EventManager::SetCallbackForCallbackQuery(
    std::function<void(SQBot::Bot*,
        const std::shared_ptr<CallbackQuery>&)> func) {
  callback_to_callback_query_ = std::move(func);
}

void EventManager::SetCallbackForShippingQuery(
    std::function<void(SQBot::Bot*,
        const std::shared_ptr<ShippingQuery>&)> func) {
  callback_to_shipping_query_ = std::move(func);
}

void EventManager::SetCallbackForPreCheckoutQuery(
    std::function<void(SQBot::Bot*,
        const std::shared_ptr<PreCheckoutQuery>&)> func) {
  callback_to_pre_checkout_query_ = std::move(func);
}

void EventManager::SetCallbackForPoll(
    std::function<void(SQBot::Bot*, const std::shared_ptr<Poll>&)> func) {
  callback_to_poll_ = std::move(func);
}

void EventManager::SetCallbackForPollAnswer(
    std::function<void(SQBot::Bot*,
                       const std::shared_ptr<PollAnswer>&)> func) {
  callback_to_poll_answer_ = std::move(func);
}

void EventManager::SetCallbackForMyChatMember(
    std::function<void(SQBot::Bot*,
                       const std::shared_ptr<ChatMemberUpdated>&)> func) {
  callback_to_my_chat_member_ = std::move(func);
}

void EventManager::SetCallbackForChatMember(
    std::function<void(SQBot::Bot*,
                       const std::shared_ptr<ChatMemberUpdated>&)> func) {
  callback_to_chat_member_ = std::move(func);
}