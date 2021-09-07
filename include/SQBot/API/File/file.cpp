#include "file.h"

File::File(const Json& file)
  : file_id(SQBot::Utils::GetValue<std::string>(file, "file_id")),
    file_unique_id(SQBot::Utils::GetValue<std::string>(file, "file_unique_id")),
    file_size(SQBot::Utils::GetValue<int32_t>(file, "file_size")),
    file_path(SQBot::Utils::GetValue<std::string>(file, "file_path")) {}
