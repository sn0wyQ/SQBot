#include "sticker.h"

Sticker::Sticker(const Json& sticker)
    : file_id(Utils::GetValue<std::string>(sticker, "file_id")),
      file_unique_id(Utils::GetValue<std::string>(sticker, "file_unique_id")),
      width(Utils::GetValue<int32_t>(sticker, "width")),
      height(Utils::GetValue<int32_t>(sticker, "height")),
      is_animated(Utils::GetValue<bool>(sticker, "is_animated")),
      thumb(Utils::GetValue<Json>(sticker, "thumb")),
      emoji(Utils::GetValue<std::string>(sticker, "emoji")),
      set_name(Utils::GetValue<std::string>(sticker, "set_name")),
      mask_position(Utils::GetValue<Json>(sticker, "mask_position")),
      file_size(Utils::GetValue<int32_t>(sticker, "file_size")) {}
