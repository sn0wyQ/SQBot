#include "venue.h"

Venue::Venue(const Json& venue)
  : location(Utils::GetPtr<Location>(venue, "location")),
    title(Utils::GetValue<std::string>(venue, "title")),
    address(Utils::GetValue<std::string>(venue, "address")),
    foursquare_id(Utils::GetValue<std::string>(venue, "foursquare_id")),
    foursquare_type(Utils::GetValue<std::string>(venue, "foursquare_type")),
    google_place_id(Utils::GetValue<std::string>(venue, "google_place_id")),
    google_place_type(
        Utils::GetValue<std::string>(venue, "google_place_type")) {}
