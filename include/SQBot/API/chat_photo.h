#ifndef INCLUDE_SQBOT_API_CHATPHOTO_CHAT_PHOTO_H_
#define INCLUDE_SQBOT_API_CHATPHOTO_CHAT_PHOTO_H_

#include <memory>
#include <string>

#include "../../nlohmann/json.h"

#include "../Utils/utils.h"

// This object represents a chat photo
class ChatPhoto {
 public:
  ChatPhoto() = default;
  explicit ChatPhoto(const Json& chat_photo);

  // File identifier of small (160x160) chat photo.
  // This file_id can be used only for photo download
  // and only for as long as the photo is not changed.
  std::string small_file_id;

  // Unique file identifier of small (160x160) chat photo,
  // which is supposed to be the same over time and for different bots.
  // Can't be used to download or reuse the file.
  std::string small_file_unique_id;

  // File identifier of big (640x640) chat photo.
  // This file_id can be used only for photo download
  // and only for as long as the photo is not changed.
  std::string big_file_id;

  // Unique file identifier of big (640x640) chat photo,
  // which is supposed to be the same over time and for different bots.
  // Can't be used to download or reuse the file.
  std::string big_file_unique_id;
};

using ChatPhotoPtr = std::shared_ptr<ChatPhoto>;

#endif  // INCLUDE_SQBOT_API_CHATPHOTO_CHAT_PHOTO_H_
