#include <iostream>

#include "Bot/bot.h"

int main() {
  SQBot::Bot bot("1288397319:AAGFIVRIRteHLIIF8X95kPTjz8uNHVJmHA4");
  auto info = bot.GetMe();
  std::cout << info->id << std::endl;

  int64_t chat_id = 439486206;
  bot.SendMessage(chat_id, "Hello, World!", true);

  return 0;
}
