#ifndef LOCATION_H_
#define LOCATION_H_

#include "json.h"

#include "../../Utils/utils.h"

// This object represents a point on the map
class Location {
 public:
  Location() = default;
  explicit Location(const Json& location);

  // Longitude as defined by sender
  float longitude{};

  // Latitude as defined by sender
  float latitude{};

  // OPTIONAL. The radius of uncertainty for the location,
  // measured in meters; 0-1500
  float horizontal_accuracy{};

  // OPTIONAL. Time relative to the message sending date,
  // during which the location can be updated, in seconds.
  // For active live locations only
  int32_t live_period{};

  // OPTIONAL. The direction in which user is moving, in degrees; 1-360. For active live locations only.
  int32_t heading{};

  // OPTIONAL. Maximum distance for proximity alerts about approaching
  // another chat member, in meters.
  // For sent live locations only
  int32_t proximity_alert_radius{};
};

#endif  // LOCATION_H_
