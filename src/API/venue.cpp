#include "../../include/SQBot/API/venue.h"

Venue::Venue(const Json& venue)
  : location(SQBot::Utils::GetPtr<Location>(venue, "location")),
    title(SQBot::Utils::GetValue<std::string>(venue, "title")),
    address(SQBot::Utils::GetValue<std::string>(venue, "address")),
    foursquare_id(SQBot::Utils::GetValue<std::string>(venue, "foursquare_id")),
    foursquare_type(SQBot::Utils::GetValue<std::string>(
        venue, "foursquare_type")),
    google_place_id(SQBot::Utils::GetValue<std::string>(
        venue, "google_place_id")),
    google_place_type(SQBot::Utils::GetValue<std::string>(
        venue, "google_place_type")) {}
