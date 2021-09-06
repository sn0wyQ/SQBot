#ifndef INCLUDE_SQBOT_API_MASKPOSITION_MASK_POSITION_H_
#define INCLUDE_SQBOT_API_MASKPOSITION_MASK_POSITION_H_

#include <string>

#include "../../../nlohmann/json.h"

#include "../../Utils/utils.h"

// This object describes the position on faces
// where a mask should be placed by default
class MaskPosition {
 public:
  MaskPosition() = default;
  explicit MaskPosition(const Json& mask_position);

  // The part of the face relative to which the mask should be placed.
  // One of “forehead”, “eyes”, “mouth”, or “chin”
  std::string point;

  // Shift by X-axis measured in widths of the mask scaled to the face size,
  // from left to right. For example, choosing -1.0 will place mask just
  // to the left of the default mask position
  float x_shift{};

  // Shift by Y-axis measured in heights of the mask scaled to the face size,
  // from top to bottom. For example, 1.0 will place the mask just
  // below the default mask position
  float y_shift{};

  // Mask scaling coefficient. For example, 2.0 means double size
  float scale{};
};

#endif  // INCLUDE_SQBOT_API_MASKPOSITION_MASK_POSITION_H_
