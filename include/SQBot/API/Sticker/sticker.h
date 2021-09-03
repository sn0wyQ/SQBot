#ifndef STICKER_H_
#define STICKER_H_

#include <string>

#include "json.h"

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
  PhotoSize thumb;

  // OPTIONAL. Emoji associated with the sticker
  std::string emoji;

  // OPTIONAL. Name of the sticker set to which the sticker belongs
  std::string set_name;

  // OPTIONAL. For mask stickers, the position where the mask should be placed
  MaskPosition mask_position;

  // OPTIONAL. File size
  int32_t file_size{};
};

#endif  // STICKER_H_