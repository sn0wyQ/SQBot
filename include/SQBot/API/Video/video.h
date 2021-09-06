#ifndef INCLUDE_SQBOT_API_VIDEO_VIDEO_H_
#define INCLUDE_SQBOT_API_VIDEO_VIDEO_H_

#include <memory>
#include <string>

#include "../../../nlohmann/json.h"

#include "../PhotoSize/photo_size.h"

#include "../../Utils/utils.h"

// This object represents a video file
class Video {
 public:
  Video() = default;
  explicit Video(const Json& video);

  // Identifier for this file, which can be used to download or reuse the file
  std::string file_id;

  // Unique identifier for this file, which is supposed to be the
  // same over time and for different bots.
  // Can't be used to download or reuse the file
  std::string file_unique_id;

  // Video width as defined by sender
  int32_t width{};

  // Video height as defined by sender
  int32_t height{};

  // Duration of the video in seconds as defined by sender
  int32_t duration{};

  // OPTIONAL. Video thumbnail
  std::shared_ptr<PhotoSize> thumb;

  // OPTIONAL. Original filename as defined by sender
  std::string file_name;

  // OPTIONAL. MIME type of the file as defined by sender
  std::string mime_type;

  // OPTIONAL. File size
  int32_t file_size{};
};

#endif  // INCLUDE_SQBOT_API_VIDEO_VIDEO_H_
