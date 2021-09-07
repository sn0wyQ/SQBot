#include "audio.h"

Audio::Audio(const Json& audio)
  : file_id(SQBot::Utils::GetValue<std::string>(audio, "file_id")),
    file_unique_id(SQBot::Utils::GetValue<std::string>(
        audio, "file_unique_id")),
    duration(SQBot::Utils::GetValue<int32_t>(audio, "duration")),
    performer(SQBot::Utils::GetValue<std::string>(audio, "performer")),
    title(SQBot::Utils::GetValue<std::string>(audio, "title")),
    file_name(SQBot::Utils::GetValue<std::string>(audio, "file_name")),
    mime_type(SQBot::Utils::GetValue<std::string>(audio, "mime_type")),
    file_size(SQBot::Utils::GetValue<int32_t>(audio, "file_size")),
    thumb(SQBot::Utils::GetPtr<PhotoSize>(audio, "thumb")) {}
