#include <iostream>

#include "Bot/bot.h"

int main() {
  SQBot::Bot bot("YOUR_TOKEN_HERE");

  auto info = bot.GetMe();
  std::cout << "Bot ID: " << info->id << std::endl;

  bot.StartReceivingUpdates();

  return 0;
}
