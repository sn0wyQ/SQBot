#ifndef INCLUDE_SQBOT_API_VIDEONOTE_VIDEO_NOTE_H_
#define INCLUDE_SQBOT_API_VIDEONOTE_VIDEO_NOTE_H_

#include <string>

#include "json.h"

#include "../PhotoSize/photo_size.h"

#include "../../Utils/utils.h"

// This object represents a video message
// (available in Telegram apps as of v.4.0)
class VideoNote {
 public:
  VideoNote() = default;
  explicit VideoNote(const Json& video_note);

  // Identifier for this file, which can be used to download or reuse the file
  std::string file_id;

  // Unique identifier for this file, which is supposed to be the
  // same over time and for different bots.
  // Can't be used to download or reuse the file
  std::string file_unique_id;

  // Video width and height (diameter of the video message) as defined by sender
  int32_t length{};

  // Duration of the video in seconds as defined by sender
  int32_t duration{};

  // OPTIONAL. Video thumbnail
  PhotoSize thumb{};

  // OPTIONAL. File size
  int32_t file_size{};
};

#endif  // INCLUDE_SQBOT_API_VIDEONOTE_VIDEO_NOTE_H_
