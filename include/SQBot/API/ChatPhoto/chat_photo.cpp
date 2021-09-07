#include "chat_photo.h"

ChatPhoto::ChatPhoto(const Json& chat_photo)
  : small_file_id(SQBot::Utils::GetValue<std::string>(
      chat_photo, "small_file_id")),
    small_file_unique_id(SQBot::Utils::GetValue<std::string>(
        chat_photo, "small_file_unique_id")),
    big_file_id(SQBot::Utils::GetValue<std::string>(chat_photo, "big_file_id")),
    big_file_unique_id(SQBot::Utils::GetValue<std::string>(
        chat_photo, "big_file_unique_id")) {}
