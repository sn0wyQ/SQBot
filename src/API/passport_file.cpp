#include "../../include/SQBot/API/passport_file.h"

PassportFile::PassportFile(const Json& passport_file)
  : file_id(SQBot::Utils::GetValue<std::string>(passport_file, "file_id")),
    file_unique_id(SQBot::Utils::GetValue<std::string>(
        passport_file, "file_unique_id")),
    file_size(SQBot::Utils::GetValue<int32_t>(passport_file, "file_size")),
    file_date(SQBot::Utils::GetValue<int32_t>(passport_file, "file_date")) {}
