#include <iostream>

#include "Bot/bot.h"

int main() {
  SQBot::Bot bot("1288397319:AAGFIVRIRteHLIIF8X95kPTjz8uNHVJmHA4");
  auto info = bot.GetMe();
  std::cout << info.id << std::endl;

  return 0;
}