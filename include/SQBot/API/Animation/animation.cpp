#include "animation.h"

Animation::Animation(const Json& animation)
  : file_id(SQBot::Utils::GetValue<std::string>(animation, "file_id")),
    file_unique_id(SQBot::Utils::GetValue<std::string>(animation, "file_unique_id")),
    width(SQBot::Utils::GetValue<int32_t>(animation, "width")),
    height(SQBot::Utils::GetValue<int32_t>(animation, "height")),
    duration(SQBot::Utils::GetValue<int32_t>(animation, "duration")),
    thumb(SQBot::Utils::GetPtr<PhotoSize>(animation, "thumb")),
    file_name(SQBot::Utils::GetValue<std::string>(animation, "file_name")),
    mime_type(SQBot::Utils::GetValue<std::string>(animation, "mime_type")),
    file_size(SQBot::Utils::GetValue<int32_t>(animation, "file_size")) {}
