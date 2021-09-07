#include "photo_size.h"

PhotoSize::PhotoSize(const Json& photo_size)
  : file_id(SQBot::Utils::GetValue<std::string>(photo_size, "file_id")),
    file_unique_id(SQBot::Utils::GetValue<std::string>(
        photo_size, "file_unique_id")),
    width(SQBot::Utils::GetValue<int32_t>(photo_size, "width")),
    height(SQBot::Utils::GetValue<int32_t>(photo_size, "height")),
    file_size(SQBot::Utils::GetValue<int32_t>(photo_size, "file_size")) {}
