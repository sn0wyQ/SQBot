#ifndef INPUT_FILE_H_
#define INPUT_FILE_H_

#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

#include "../Utils/utils.h"

namespace SQBot {

// This object represents the contents of a file to be uploaded
class InputFile {
 public:
  InputFile() = default;
  // Constructs InputFile holding data from selected file.
  // file_name is set to file name of file ("/path/to/file.jpg" -> "file.jpg")
  explicit InputFile(const std::filesystem::path& path_to_file);

  // returns data in base64 encoded string
  std::string GetData() const;

  // returns pointer to base64 encoded data
  const char* GetDataPtr() const;

  // returns size of base64 encoded data in bytes
  size_t GetSize() const;

  // return MIME type of file
  std::string GetMimeType() const;

  // returns file name
  std::string GetFileName() const;

 private:
  std::string data_;
  std::string mime_type_;
  std::string file_name_;
};

}  // namespace SQBot

#endif  // INPUT_FILE_H_
