#include "animation.h"

Animation::Animation(const Json& animation)
  : file_id(Utils::GetValue<std::string>(animation, "file_id")),
    file_unique_id(Utils::GetValue<std::string>(animation, "file_unique_id")),
    width(Utils::GetValue<int32_t>(animation, "width")),
    height(Utils::GetValue<int32_t>(animation, "height")),
    duration(Utils::GetValue<int32_t>(animation, "duration")),
    thumb(Utils::GetValue<Json>(animation, "thumb")),
    file_name(Utils::GetValue<std::string>(animation, "file_name")),
    mime_type(Utils::GetValue<std::string>(animation, "mime_type")),
    file_size(Utils::GetValue<int32_t>(animation, "file_size")) {}
