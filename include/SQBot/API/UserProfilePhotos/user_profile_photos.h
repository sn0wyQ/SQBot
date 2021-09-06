#ifndef USER_PROFILE_PHOTOTS_H_
#define USER_PROFILE_PHOTOTS_H_

#include <memory>
#include <vector>

#include "../../../nlohmann/json.h"

#include "../PhotoSize/photo_size.h"

#include "../../Utils/utils.h"

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

#endif  // USER_PROFILE_PHOTOTS_H_
