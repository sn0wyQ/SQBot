#ifndef INCLUDE_SQBOT_API_VOICE_H_
#define INCLUDE_SQBOT_API_VOICE_H_

#include <memory>
#include <string>

#include "../../nlohmann/json.h"

#include "../Utils/utils.h"

// This object represents a voice note
class Voice {
 public:
  Voice() = default;
  explicit Voice(const Json& voice);

  // Identifier for this file, which can be used to download or reuse the file
  std::string file_id;

  // Unique identifier for this file, which is supposed to be the
  // same over time and for different bots.
  // Can't be used to download or reuse the file
  std::string file_unique_id;

  // Duration of the audio in seconds as defined by sender
  int32_t duration{};

  // OPTIONAL. MIME type of the file as defined by sender
  std::string mime_type;

  // OPTIONAL. File size
  int32_t file_size{};
};

using VoicePtr = std::shared_ptr<Voice>;

#endif  // INCLUDE_SQBOT_API_VOICE_H_
