#include "../../include/SQBot/API/user_profile_photos.h"

UserProfilePhotos::UserProfilePhotos(const Json& user_profile_photos)
  : total_count(SQBot::Utils::GetValue<int32_t>(
        user_profile_photos, "total_count")) {
  if (user_profile_photos.contains("photos")) {
    const Json& photos_json = user_profile_photos.at("photos");
    for (const auto& row : photos_json) {
      std::vector<PhotoSizePtr> current_row;
      for (const auto& photo_size : row) {
        current_row.push_back(std::make_shared<PhotoSize>(photo_size));
      }
      photos.push_back(std::move(current_row));
    }
  }
}
