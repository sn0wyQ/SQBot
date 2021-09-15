#ifndef INCLUDE_SQBOT_API_ANIMATION_ANIMATION_H_
#define INCLUDE_SQBOT_API_ANIMATION_ANIMATION_H_

#include <memory>
#include <string>

#include "../../nlohmann/json.h"

#include "photo_size.h"

#include "../Utils/utils.h"

// This object represents an animation file
// (GIF or H.264/MPEG-4 AVC video without sound)
class Animation {
 public:
  Animation() = default;
  explicit Animation(const Json& animation);

  // Identifier for this file, which can be used to download or reuse the file
  std::string file_id;

  // Unique identifier for this file, which is supposed to be
  // the same over time and for different bots.
  // Can't be used to download or reuse the file
  std::string file_unique_id;

  // Video width as defined by sender
  int32_t width{};

  // Video height as defined by sender
  int32_t height{};

  // Duration of the video in seconds as defined by sender
  int32_t duration{};

  // OPTIONAL. Animation thumbnail as defined by sender
  PhotoSizePtr thumb;

  // OPTIONAL. Original animation filename as defined by sender
  std::string file_name;

  // OPTIONAL. MIME type of the file as defined by sender
  std::string mime_type;

  // OPTIONAL. File size
  int32_t file_size{};
};

using AnimationPtr = std::shared_ptr<Animation>;

#endif  // INCLUDE_SQBOT_API_ANIMATION_ANIMATION_H_
