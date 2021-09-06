#ifndef INCLUDE_SQBOT_API_STICKER_STICKER_H_
#define INCLUDE_SQBOT_API_STICKER_STICKER_H_

#include <memory>
#include <string>

#include "../../../nlohmann/json.h"

#include "../MaskPosition/mask_position.h"
#include "../PhotoSize/photo_size.h"

#include "../../Utils/utils.h"

// This object represents a sticker
class Sticker {
 public:
  Sticker() = default;
  explicit Sticker(const Json& sticker);

  // Identifier for this file, which can be used to download or reuse the file
  std::string file_id;

  // Unique identifier for this file, which is supposed to be
  // the same over time and for different bots.
  // Can't be used to download or reuse the file
  std::string file_unique_id;

  // Sticker width
  int32_t width{};

  // Sticker height
  int32_t height{};

  // True, if the sticker is animated
  bool is_animated{};

  // OPTIONAL. Sticker thumbnail in the .WEBP or .JPG format
  PhotoSizePtr thumb;

  // OPTIONAL. Emoji associated with the sticker
  std::string emoji;

  // OPTIONAL. Name of the sticker set to which the sticker belongs
  std::string set_name;

  // OPTIONAL. For mask stickers, the position where the mask should be placed
  MaskPositionPtr mask_position;

  // OPTIONAL. File size
  int32_t file_size{};
};

using StickerPtr = std::shared_ptr<Sticker>;

#endif  // INCLUDE_SQBOT_API_STICKER_STICKER_H_
