#ifndef INCLUDE_SQBOT_API_DOCUMENT_H_
#define INCLUDE_SQBOT_API_DOCUMENT_H_

#include <memory>
#include <string>

#include "../../nlohmann/json.h"

#include "photo_size.h"

#include "../Utils/utils.h"

// This object represents a general file
// (as opposed to photos, voice messages and audio files)
class Document {
 public:
  Document() = default;
  explicit Document(const Json& document);

  // Identifier for this file, which can be used to download or reuse the file
  std::string file_id;

  // Unique identifier for this file, which is supposed to be
  // the same over time and for different bots.
  // Can't be used to download or reuse the file
  std::string file_unique_id;

  // OPTIONAL. Document thumbnail as defined by sender
  PhotoSizePtr thumb;

  // OPTIONAL. Original filename as defined by sender
  std::string file_name;

  // OPTIONAL. MIME type of the file as defined by sender
  std::string mime_type;

  // OPTIONAL. File size
  int32_t file_size{};
};

using DocumentPtr = std::shared_ptr<Document>;

#endif  // INCLUDE_SQBOT_API_DOCUMENT_H_
