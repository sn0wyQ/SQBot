#include "audio.h"

Audio::Audio(const Json& audio)
  : file_id(Utils::GetValue<std::string>(audio, "file_id")),
    file_unique_id(Utils::GetValue<std::string>(audio, "file_unique_id")),
    duration(Utils::GetValue<int32_t>(audio, "duration")),
    performer(Utils::GetValue<std::string>(audio, "performer")),
    title(Utils::GetValue<std::string>(audio, "title")),
    file_name(Utils::GetValue<std::string>(audio, "file_name")),
    mime_type(Utils::GetValue<std::string>(audio, "mime_type")),
    file_size(Utils::GetValue<int32_t>(audio, "file_size")),
    thumb(Utils::GetPtr<PhotoSize>(audio, "thumb")) {}
