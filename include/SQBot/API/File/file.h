#ifndef INCLUDE_SQBOT_API_FILE_FILE_H_
#define INCLUDE_SQBOT_API_FILE_FILE_H_

#include <memory>
#include <string>

#include "../../../nlohmann/json.h"

#include "../../Utils/utils.h"

// This object represents a file ready to be downloaded. The file can be
// downloaded via the link https://api.telegram.org/file/bot<token>/<file_path>.
// It is guaranteed that the link will be valid for at least 1 hour.
// When the link expires, a new one can be requested by calling getFile
class File {
 public:
  File() = default;
  explicit File(const Json& file);

  // Identifier for this file, which can be used to download or reuse the file
  std::string file_id;

  // Unique identifier for this file, which is supposed to be the same over
  // time and for different bots. Can't be used to download or reuse the file
  std::string file_unique_id;

  // OPTIONAL. File size, if known
  int32_t file_size{};

  // OPTIONAL. File path.
  // Use https://api.telegram.org/file/bot<token>/<file_path> to get the file
  std::string file_path;
};

using FilePtr = std::shared_ptr<File>;

#endif  // INCLUDE_SQBOT_API_FILE_FILE_H_
