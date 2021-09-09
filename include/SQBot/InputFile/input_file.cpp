#include "input_file.h"

SQBot::InputFile::InputFile(const std::filesystem::path& path_to_file) {
  std::ifstream file_data(path_to_file, std::ios::binary);

  std::stringstream data_stream;
  data_stream << file_data.rdbuf();
  data_ = data_stream.str();

  mime_type_ = SQBot::Utils::GetMimeType(path_to_file.extension());

  file_name_ = path_to_file.filename();
}

std::string SQBot::InputFile::GetData() const {
  return data_;
}

const char* SQBot::InputFile::GetDataPtr() const {
  return data_.c_str();
}

size_t SQBot::InputFile::GetSize() const {
  return data_.size();
}

std::string SQBot::InputFile::GetMimeType() const {
  return mime_type_;
}

std::string SQBot::InputFile::GetFileName() const {
  return file_name_;
}
