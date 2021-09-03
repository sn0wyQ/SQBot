#include "voice.h"

Voice::Voice(const Json& voice)
    : file_id(Utils::GetValue<std::string>(voice, "file_id")),
      file_unique_id(Utils::GetValue<std::string>(voice, "file_unique_id")),
      duration(Utils::GetValue<int32_t>(voice, "duration")),
      mime_type(Utils::GetValue<std::string>(voice, "mime_type")),
      file_size(Utils::GetValue<int32_t>(voice, "file_size")) {}
