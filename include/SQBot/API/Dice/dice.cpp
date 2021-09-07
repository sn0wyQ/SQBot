#include "dice.h"

Dice::Dice(const Json& dice)
  : emoji(SQBot::Utils::GetValue<std::string>(dice, "emoji")),
    value(SQBot::Utils::GetValue<int32_t>(dice, "value")) {}
