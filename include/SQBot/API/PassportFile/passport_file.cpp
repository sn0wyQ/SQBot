#include "passport_file.h"

PassportFile::PassportFile(const Json& passport_file)
  : file_id(Utils::GetValue<std::string>(passport_file, "file_id")),
    file_unique_id(
        Utils::GetValue<std::string>(passport_file, "file_unique_id")),
    file_size(Utils::GetValue<int32_t>(passport_file, "file_size")),
    file_date(Utils::GetValue<int32_t>(passport_file, "file_date")) {}
