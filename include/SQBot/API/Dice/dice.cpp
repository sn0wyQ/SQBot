#include "dice.h"

Dice::Dice(const Json& dice)
  : emoji(Utils::GetValue<std::string>(dice, "emoji")),
    value(Utils::GetValue<int32_t>(dice, "value")) {}
