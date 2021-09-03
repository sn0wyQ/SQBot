#include "photo_size.h"

PhotoSize::PhotoSize(const Json& photo_size)
  : file_id(Utils::GetValue<std::string>(photo_size, "file_id")),
    file_unique_id(Utils::GetValue<std::string>(photo_size, "file_unique_id")),
    width(Utils::GetValue<int32_t>(photo_size, "width")),
    height(Utils::GetValue<int32_t>(photo_size, "height")),
    file_size(Utils::GetValue<int32_t>(photo_size, "file_size")) {}
