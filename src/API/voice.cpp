#include "../../include/SQBot/API/voice.h"

Voice::Voice(const Json& voice)
    : file_id(SQBot::Utils::GetValue<std::string>(voice, "file_id")),
      file_unique_id(SQBot::Utils::GetValue<std::string>(
          voice, "file_unique_id")),
      duration(SQBot::Utils::GetValue<int32_t>(voice, "duration")),
      mime_type(SQBot::Utils::GetValue<std::string>(voice, "mime_type")),
      file_size(SQBot::Utils::GetValue<int32_t>(voice, "file_size")) {}
