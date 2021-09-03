#ifndef INCLUDE_SQBOT_API_PASSPORTFILE_PASSPORT_FILE_H_
#define INCLUDE_SQBOT_API_PASSPORTFILE_PASSPORT_FILE_H_

#include <string>

#include "json.h"

#include "../../Utils/utils.h"

// This object represents a file uploaded to Telegram Passport. Currently all
// Telegram Passport files are in JPEG format when decrypted
// and don't exceed 10MB
class PassportFile {
 public:
  PassportFile() = default;
  explicit PassportFile(const Json& passport_file);

  // Identifier for this file, which can be used to download or reuse the file
  std::string file_id;

  // Unique identifier for this file, which is supposed to be
  // the same over time and for different bots.
  // Can't be used to download or reuse the file
  std::string file_unique_id;

  // File size
  int32_t file_size{};

  // Unix time when the file was uploaded
  int32_t file_date{};
};

#endif  // INCLUDE_SQBOT_API_PASSPORTFILE_PASSPORT_FILE_H_
