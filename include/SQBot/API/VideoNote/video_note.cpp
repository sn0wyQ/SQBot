#include "video_note.h"

VideoNote::VideoNote(const Json& video_note)
    : file_id(Utils::GetValue<std::string>(video_note, "file_id")),
      file_unique_id(
          Utils::GetValue<std::string>(video_note, "file_unique_id")),
      length(Utils::GetValue<int32_t>(video_note, "length")),
      duration(Utils::GetValue<int32_t>(video_note, "duration")),
      thumb(Utils::GetPtr<PhotoSize>(video_note, "thumb")),
      file_size(Utils::GetValue<int32_t>(video_note, "file_size")) {}
