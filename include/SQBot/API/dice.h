#ifndef INCLUDE_SQBOT_API_DICE_H_
#define INCLUDE_SQBOT_API_DICE_H_

#include <memory>
#include <string>

#include "../../nlohmann/json.h"

#include "../Utils/utils.h"

// This object represents an animated emoji that displays a random value
class Dice {
 public:
  Dice() = default;
  explicit Dice(const Json& dice);

  // Emoji on which the dice throw animation is based
  std::string emoji;

  // Value of the dice, 1-6 for “🎲”, “🎯” and “🎳” base emoji,
  // 1-5 for “🏀” and “⚽” base emoji, 1-64 for “🎰” base emoji
  int32_t value{};
};

using DicePtr = std::shared_ptr<Dice>;

#endif  // INCLUDE_SQBOT_API_DICE_H_
