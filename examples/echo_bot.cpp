#include <iostream>

#include "SQBot/Bot/bot.h"
#include "SQBot/EventManager/event_manager.h"

void Echo(SQBot::Bot* bot, const MessagePtr& message) {
  bot->SendMessage(message->chat->id,
                   message->text,
                   true,
                   true,
                   message->message_id);
}

int main() {
  SQBot::Bot bot("YOUR_TOKEN_HERE");

  auto info = bot.GetMe();
  std::cout << "Bot ID: " << info->id << std::endl;

  bot.GetEventManager()->SetCallbackForMessage(Echo);
  // Or same thing using lambda:
  // bot.GetEventManager()->SetCallbackForMessage(
  //     [](SQBot::Bot* bot, const MessagePtr& message) {
  //       bot->SendMessage(message->chat->id,
  //                        message->text,
  //                        true,
  //                        true,
  //                        message->message_id);
  //     });

  bot.StartReceivingUpdates();

  return 0;
}
