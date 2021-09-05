#include "video.h"

Video::Video(const Json& video)
    : file_id(Utils::GetValue<std::string>(video, "file_id")),
      file_unique_id(Utils::GetValue<std::string>(video, "file_unique_id")),
      width(Utils::GetValue<int32_t>(video, "width")),
      height(Utils::GetValue<int32_t>(video, "height")),
      duration(Utils::GetValue<int32_t>(video, "duration")),
      thumb(Utils::GetPtr<PhotoSize>(video, "thumb")),
      file_name(Utils::GetValue<std::string>(video, "file_name")),
      mime_type(Utils::GetValue<std::string>(video, "mime_type")),
      file_size(Utils::GetValue<int32_t>(video, "file_size")) {}
