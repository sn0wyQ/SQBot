#include "mask_position.h"

MaskPosition::MaskPosition(const Json& mask_position)
  : point(Utils::GetValue<std::string>(mask_position, "point")),
    x_shift(Utils::GetValue<float>(mask_position, "x_shift")),
    y_shift(Utils::GetValue<float>(mask_position, "y_shift")),
    scale(Utils::GetValue<float>(mask_position, "scale")) {}
