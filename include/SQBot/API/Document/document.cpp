#include "document.h"

Document::Document(const Json& document)
  : file_id(SQBot::Utils::GetValue<std::string>(document, "file_id")),
    file_unique_id(SQBot::Utils::GetValue<std::string>(
        document, "file_unique_id")),
    thumb(SQBot::Utils::GetPtr<PhotoSize>(document, "thumb")),
    file_name(SQBot::Utils::GetValue<std::string>(document, "file_name")),
    mime_type(SQBot::Utils::GetValue<std::string>(document, "mime_type")),
    file_size(SQBot::Utils::GetValue<int32_t>(document, "file_size")) {}
