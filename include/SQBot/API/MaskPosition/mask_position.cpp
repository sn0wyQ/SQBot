#include "mask_position.h"

MaskPosition::MaskPosition(const Json& mask_position)
  : point(SQBot::Utils::GetValue<std::string>(mask_position, "point")),
    x_shift(SQBot::Utils::GetValue<float>(mask_position, "x_shift")),
    y_shift(SQBot::Utils::GetValue<float>(mask_position, "y_shift")),
    scale(SQBot::Utils::GetValue<float>(mask_position, "scale")) {}
