#include "../../include/SQBot/API/video_note.h"

VideoNote::VideoNote(const Json& video_note)
    : file_id(SQBot::Utils::GetValue<std::string>(video_note, "file_id")),
      file_unique_id(SQBot::Utils::GetValue<std::string>(
          video_note, "file_unique_id")),
      length(SQBot::Utils::GetValue<int32_t>(video_note, "length")),
      duration(SQBot::Utils::GetValue<int32_t>(video_note, "duration")),
      thumb(SQBot::Utils::GetPtr<PhotoSize>(video_note, "thumb")),
      file_size(SQBot::Utils::GetValue<int32_t>(video_note, "file_size")) {}
