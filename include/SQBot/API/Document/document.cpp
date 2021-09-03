#include "document.h"

Document::Document(const Json& document)
  : file_id(Utils::GetValue<std::string>(document, "file_id")),
    file_unique_id(Utils::GetValue<std::string>(document, "file_unique_id")),
    thumb(Utils::GetValue<Json>(document, "thumb")),
    file_name(Utils::GetValue<std::string>(document, "file_name")),
    mime_type(Utils::GetValue<std::string>(document, "mime_type")),
    file_size(Utils::GetValue<int32_t>(document, "file_size")) {}
