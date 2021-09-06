#include "file.h"

File::File(const Json& file)
  : file_id(Utils::GetValue<std::string>(file, "file_id")),
    file_unique_id(Utils::GetValue<std::string>(file, "file_unique_id")),
    file_size(Utils::GetValue<int32_t>(file, "file_size")),
    file_path(Utils::GetValue<std::string>(file, "file_path")) {}
