#include "sticker.h"

Sticker::Sticker(const Json& sticker)
    : file_id(SQBot::Utils::GetValue<std::string>(sticker, "file_id")),
      file_unique_id(SQBot::Utils::GetValue<std::string>(sticker, "file_unique_id")),
      width(SQBot::Utils::GetValue<int32_t>(sticker, "width")),
      height(SQBot::Utils::GetValue<int32_t>(sticker, "height")),
      is_animated(SQBot::Utils::GetValue<bool>(sticker, "is_animated")),
      thumb(SQBot::Utils::GetPtr<PhotoSize>(sticker, "thumb")),
      emoji(SQBot::Utils::GetValue<std::string>(sticker, "emoji")),
      set_name(SQBot::Utils::GetValue<std::string>(sticker, "set_name")),
      mask_position(SQBot::Utils::GetPtr<MaskPosition>(sticker, "mask_position")),
      file_size(SQBot::Utils::GetValue<int32_t>(sticker, "file_size")) {}
