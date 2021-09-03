#ifndef PHOTO_SIZE_H_
#define PHOTO_SIZE_H_

#include <string>

#include "json.h"

#include "../../Utils/utils.h"

// This object represents one size of a photo or a file/sticker thumbnail
class PhotoSize {
 public:
  PhotoSize() = default;
  explicit PhotoSize(const Json& photo_size);

  // Identifier for this file, which can be used to download or reuse the file
  std::string file_id;

  // Unique identifier for this file, which is supposed to be
  // the same over time and for different bots.
  // Can't be used to download or reuse the file
  std::string file_unique_id;

  // Photo width
  int32_t width{};

  // Photo height
  int32_t height{};

  // OPTIONAL. File size
  int32_t file_size{};
};

#endif  // PHOTO_SIZE_H_
