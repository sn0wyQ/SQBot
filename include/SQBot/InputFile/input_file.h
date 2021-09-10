#ifndef INCLUDE_SQBOT_INPUTFILE_INPUT_FILE_H_
#define INCLUDE_SQBOT_INPUTFILE_INPUT_FILE_H_

#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>

#include "../Utils/utils.h"

namespace SQBot {

// This object represents the contents of a file to be uploaded
class InputFile {
 public:
  InputFile() = default;
  // Constructs InputFile holding data from selected file.
  // file_name is set to file name of file ("/path/to/file.jpg" -> "file.jpg")
  explicit InputFile(const std::filesystem::path& path_to_file);
  InputFile(std::string data, std::string mime_type, std::string file_name);

  // Returns data
  std::string GetData() const;

  // Returns pointer to data
  const char* GetDataPtr() const;

  // Returns size of data in bytes
  size_t GetSize() const;

  // Return MIME type of file
  std::string GetMimeType() const;

  // Returns file name
  std::string GetFileName() const;

  // Sets data
  void SetData(std::string data);

  // Sets MIME type
  void SetMimeType(std::string mime_type);

  // Sets file name
  void SetFileName(std::string file_name);

 private:
  std::string data_;
  std::string mime_type_;
  std::string file_name_;
};

}  // namespace SQBot

#endif  // INCLUDE_SQBOT_INPUTFILE_INPUT_FILE_H_
