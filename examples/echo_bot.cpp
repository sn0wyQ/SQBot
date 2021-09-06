#include <iostream>
#include <memory>

#include "SQBot/Bot/bot.h"
#include "SQBot/EventManager/event_manager.h"

void Echo(SQBot::Bot* bot, const std::shared_ptr<Message>& message) {
  bot->SendMessage(message->chat->id,
                   message->text,
                   true,
                   true,
                   message->message_id);
}

int main() {
  SQBot::Bot bot("1288397319:AAGFIVRIRteHLIIF8X95kPTjz8uNHVJmHA4");

  auto info = bot.GetMe();
  std::cout << "Bot ID: " << info->id << std::endl;

  bot.GetEventManager()->SetCallbackForMessage(Echo);
  // Same thing using lambda:
  // bot.GetEventManager()->SetCallbackForMessage(
  //     [](SQBot::Bot* bot, const std::shared_ptr<Message>& message) {
  //       bot->SendMessage(message->chat->id,
  //                        message->text,
  //                        true,
  //                        true,
  //                        message->message_id);
  //     });

  bot.StartReceivingUpdates();

  return 0;
}
