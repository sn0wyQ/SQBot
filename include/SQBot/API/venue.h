#ifndef INCLUDE_SQBOT_API_VENUE_VENUE_H_
#define INCLUDE_SQBOT_API_VENUE_VENUE_H_

#include <memory>
#include <string>

#include "../../nlohmann/json.h"

#include "location.h"

#include "../Utils/utils.h"

// This object represents a venue
class Venue {
 public:
  Venue() = default;
  explicit Venue(const Json& venue);

  // Venue location. Can't be a live location
  LocationPtr location;

  // Name of the venue
  std::string title;

  // Address of the venue
  std::string address;

  // OPTIONAL. Foursquare identifier of the venue
  std::string foursquare_id;

  // OPTIONAL. Foursquare type of the venue.
  // (For example, “arts_entertainment/default”,
  // “arts_entertainment/aquarium” or “food/ice_cream”.)
  std::string foursquare_type;

  // OPTIONAL. Google Places identifier of the venue
  std::string google_place_id;

  // OPTIONAL. Google Places type of the venue. See supported types:
  // https://developers.google.com/maps/documentation/places/web-service/supported_types
  std::string google_place_type;
};

using VenuePtr = std::shared_ptr<Venue>;

#endif  // INCLUDE_SQBOT_API_VENUE_VENUE_H_
