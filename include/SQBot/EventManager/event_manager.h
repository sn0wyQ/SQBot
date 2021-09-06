#ifndef EVENT_LISTENER_H_
#define EVENT_LISTENER_H_

#include <functional>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

#include "../API/CallbackQuery/callback_query.h"
#include "../API/ChatMemberUpdated/chat_member_updated.h"
#include "../API/ChosenInlineResult/chosen_inline_result.h"
#include "../API/InlineQuery/inline_query.h"
#include "../API/Message/message.h"
#include "../API/PollAnswer/poll_answer.h"
#include "../API/Poll/poll.h"
#include "../API/PreCheckoutQuery/pre_checkout_query.h"
#include "../API/ShippingQuery/shipping_query.h"
#include "../API/Update/update.h"

#include "../Utils/utils.h"

namespace SQBot {
class Bot;
}  // namespace SQBot

class EventManager {
 public:
  EventManager() = default;

  // Finds and calls callback function for given Update
  void CallCallbackFor(SQBot::Bot* bot, const std::shared_ptr<Update>& update);

  // Sets |func| a callback for |command| bot command
  void SetCallbackForBotCommand(const std::string& command,
      std::function<void(SQBot::Bot*, const std::shared_ptr<Message>&)> func);

  // Sets |func| a callback for messages starting with |prefix|.
  // NOTE! Priority of this callback is lower than priority of callback for
  // kBotCommand event that has a callback
  void SetCallbackForMessageStartsWith(const std::string& prefix,
      std::function<void(SQBot::Bot*, const std::shared_ptr<Message>&)> func);

  // Sets |func| a callback for update with message.
  // NOTE! Priority of this callback is lower than priority of callbacks for
  // kBotCommand and kMessageStartsWith events
  void SetCallbackForMessage(
      std::function<void(SQBot::Bot*, const std::shared_ptr<Message>&)> func);

  // Sets |func| a callback for update with edited_message
  void SetCallbackForEditedMessage(
      std::function<void(SQBot::Bot*, const std::shared_ptr<Message>&)> func);

  // Sets |func| a callback for update with channel_post
  void SetCallbackForChannelPost(
      std::function<void(SQBot::Bot*, const std::shared_ptr<Message>&)> func);

  // Sets |func| a callback for update with edited_channel_post
  void SetCallbackForEditedChannelPost(
      std::function<void(SQBot::Bot*, const std::shared_ptr<Message>&)> func);

  // Sets |func| a callback for update with inline_query
  void SetCallbackForInlineQuery(
      std::function<void(SQBot::Bot*,
          const std::shared_ptr<InlineQuery>&)> func);

  // Sets |func| a callback for update with chosen_inline_result
  void SetCallbackForChosenInlineResult(
      std::function<void(SQBot::Bot*,
                         const std::shared_ptr<ChosenInlineResult>&)> func);

  // Sets |func| a callback for update with callback_query
  void SetCallbackForCallbackQuery(
      std::function<void(SQBot::Bot*,
                         const std::shared_ptr<CallbackQuery>&)> func);

  // Sets |func| a callback for update with shipping_query
  void SetCallbackForShippingQuery(
      std::function<void(SQBot::Bot*,
                         const std::shared_ptr<ShippingQuery>&)> func);

  // Sets |func| a callback for update with shipping_query
  void SetCallbackForPreCheckoutQuery(
      std::function<void(SQBot::Bot*,
                         const std::shared_ptr<PreCheckoutQuery>&)> func);

  // Sets |func| a callback for update with poll
  void SetCallbackForPoll(
      std::function<void(SQBot::Bot*, const std::shared_ptr<Poll>&)> func);

  // Sets |func| a callback for update with poll_answer
  void SetCallbackForPollAnswer(
      std::function<void(SQBot::Bot*,
          const std::shared_ptr<PollAnswer>&)> func);

  // Sets |func| a callback for update with my_chat_member
  void SetCallbackForMyChatMember(
      std::function<void(SQBot::Bot*,
                         const std::shared_ptr<ChatMemberUpdated>&)> func);

  // Sets |func| a callback for update with chat_member
  void SetCallbackForChatMember(
      std::function<void(SQBot::Bot*,
                         const std::shared_ptr<ChatMemberUpdated>&)> func);

 private:
  std::unordered_map<std::string,
                     std::function<void(SQBot::Bot*,
                                        const std::shared_ptr<Message>&)>>
      callbacks_to_bot_commands_;

  std::map<std::string,
           std::function<void(SQBot::Bot*, const std::shared_ptr<Message>&)>>
      callbacks_to_message_starts_with_;

  std::function<void(SQBot::Bot*, const std::shared_ptr<Message>&)>
      callback_to_message_;
  std::function<void(SQBot::Bot*, const std::shared_ptr<Message>&)>
      callback_to_edited_message_;
  std::function<void(SQBot::Bot*, const std::shared_ptr<Message>&)>
      callback_to_channel_post_;
  std::function<void(SQBot::Bot*, const std::shared_ptr<Message>&)>
      callback_to_edited_channel_post_;
  std::function<void(SQBot::Bot*, const std::shared_ptr<InlineQuery>&)>
      callback_to_inline_query_;
  std::function<void(SQBot::Bot*, const std::shared_ptr<ChosenInlineResult>&)>
      callback_to_chosen_inline_result_;
  std::function<void(SQBot::Bot*, const std::shared_ptr<CallbackQuery>&)>
      callback_to_callback_query_;
  std::function<void(SQBot::Bot*, const std::shared_ptr<ShippingQuery>&)>
      callback_to_shipping_query_;
  std::function<void(SQBot::Bot*, const std::shared_ptr<PreCheckoutQuery>&)>
      callback_to_pre_checkout_query_;
  std::function<void(SQBot::Bot*, const std::shared_ptr<Poll>&)>
      callback_to_poll_;
  std::function<void(SQBot::Bot*, const std::shared_ptr<PollAnswer>&)>
      callback_to_poll_answer_;
  std::function<void(SQBot::Bot*, const std::shared_ptr<ChatMemberUpdated>&)>
      callback_to_my_chat_member_;
  std::function<void(SQBot::Bot*, const std::shared_ptr<ChatMemberUpdated>&)>
      callback_to_chat_member_;
};

#endif  // EVENT_LISTENER_H_
