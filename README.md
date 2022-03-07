[![CI Checks](https://github.com/sn0wyQ/SQBot/actions/workflows/ci.yml/badge.svg?branch=master)](https://github.com/sn0wyQ/SQBot/actions/workflows/ci.yml)
# SQBot
C++20 Library for Telegram Bot API

# Hello, World!
Bot that sends "Hello, World!" to anyone who sends him /hello command:
```cpp
#include <iostream>

#include "SQBot/Bot/bot.h"
#include "SQBot/EventManager/event_manager.h"

int main() {
  SQBot::Bot bot("YOUR_TOKEN_HERE");

  bot.GetEventManager()->SetCallbackForMessageFirstWordIs("/hello",
     [](SQBot::Bot* bot, const MessagePtr& message) {
       bot->SendMessage(message->chat->id,
                        "Hello, World!");
     });

  bot.StartReceivingUpdates();

  return 0;
}
```
You can also use your own functions instead of lambdas:
```cpp
void GreetTheWorld(SQBot::Bot* bot, const MessagePtr& message) {
  bot->SendMessage(message->chat->id, "Hello, World!");
}

// ...

bot.GetEventManager()->SetCallbackForMessageFirstWordIs("/hello", GreetTheWorld);
```

# Dependencies
You need [CURL](https://github.com/curl/curl) and [nlohmann json](https://github.com/nlohmann/json)
