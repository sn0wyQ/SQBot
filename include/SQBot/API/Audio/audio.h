#ifndef INCLUDE_SQBOT_API_AUDIO_AUDIO_H_
#define INCLUDE_SQBOT_API_AUDIO_AUDIO_H_

#include <memory>
#include <string>

#include "json.h"

#include "../PhotoSize/photo_size.h"

#include "../../Utils/utils.h"

// This object represents an audio file
// to be treated as music by the Telegram clients
class Audio {
 public:
  Audio() = default;
  explicit Audio(const Json& audio);

  // Identifier for this file, which can be used to download or reuse the file
  std::string file_id;

  // Unique identifier for this file, which is supposed to be
  // the same over time and for different bots.
  // Can't be used to download or reuse the file
  std::string file_unique_id;

  // Duration of the audio in seconds as defined by sender
  int32_t duration{};

  // OPTIONAL. Performer of the audio as defined by sender or by audio tags
  std::string performer;

  // OPTIONAL. Title of the audio as defined by sender or by audio tags
  std::string title;

  // OPTIONAL. Original filename as defined by sender
  std::string file_name;

  // OPTIONAL. MIME type of the file as defined by sender
  std::string mime_type;

  // OPTIONAL. File size
  int32_t file_size{};

  // OPTIONAL. Thumbnail of the album cover to which the music file belongs
  std::shared_ptr<PhotoSize> thumb;
};

#endif  // INCLUDE_SQBOT_API_AUDIO_AUDIO_H_
