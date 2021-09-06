#ifndef CALLBACK_GAME_H_
#define CALLBACK_GAME_H_

#include <memory>

#include "../../../nlohmann/json.h"

// A placeholder, currently holds no information.
// Use BotFather to set up your game
class CallbackGame {
 public:
  CallbackGame() = default;
  explicit CallbackGame(const Json& callback_game);
};

using CallbackGamePtr = std::shared_ptr<CallbackGame>;

#endif  // CALLBACK_GAME_H_
