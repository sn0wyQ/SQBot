#include <iostream>

#include "Bot/bot.h"

int main() {
  SQBot::Bot bot("INSERT_YOUR_TOKEN_HERE");
  auto info = bot.GetMe();
  std::cout << info.id << std::endl;

  return 0;
}
