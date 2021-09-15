#include "../../include/SQBot/API/video.h"

Video::Video(const Json& video)
    : file_id(SQBot::Utils::GetValue<std::string>(video, "file_id")),
      file_unique_id(SQBot::Utils::GetValue<std::string>(
          video, "file_unique_id")),
      width(SQBot::Utils::GetValue<int32_t>(video, "width")),
      height(SQBot::Utils::GetValue<int32_t>(video, "height")),
      duration(SQBot::Utils::GetValue<int32_t>(video, "duration")),
      thumb(SQBot::Utils::GetPtr<PhotoSize>(video, "thumb")),
      file_name(SQBot::Utils::GetValue<std::string>(video, "file_name")),
      mime_type(SQBot::Utils::GetValue<std::string>(video, "mime_type")),
      file_size(SQBot::Utils::GetValue<int32_t>(video, "file_size")) {}
