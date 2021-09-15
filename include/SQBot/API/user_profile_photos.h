#ifndef INCLUDE_SQBOT_API_USERPROFILEPHOTOS_USER_PROFILE_PHOTOS_H_
#define INCLUDE_SQBOT_API_USERPROFILEPHOTOS_USER_PROFILE_PHOTOS_H_

#include <memory>
#include <utility>
#include <vector>

#include "../../nlohmann/json.h"

#include "photo_size.h"

#include "../Utils/utils.h"

// This object represents a user's profile pictures
class UserProfilePhotos {
 public:
  UserProfilePhotos() = default;
  explicit UserProfilePhotos(const Json& user_profile_photos);

  // Total number of profile pictures the target user has
  int32_t total_count{};

  // Requested profile pictures (in up to 4 sizes each)
  std::vector<std::vector<PhotoSizePtr>> photos;
};

using UserProfilePhotosPtr = std::shared_ptr<UserProfilePhotos>;

#endif  // INCLUDE_SQBOT_API_USERPROFILEPHOTOS_USER_PROFILE_PHOTOS_H_
