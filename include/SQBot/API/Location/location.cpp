#include "location.h"

Location::Location(const Json& location)
  : longitude(Utils::GetValue<float>(location, "longitude")),
    latitude(Utils::GetValue<float>(location, "latitude")),
    horizontal_accuracy(
        Utils::GetValue<float>(location, "horizontal_accuracy")),
    live_period(Utils::GetValue<int32_t>(location, "live_period")),
    heading(Utils::GetValue<int32_t>(location, "heading")),
    proximity_alert_radius(
        Utils::GetValue<int32_t>(location, "proximity_alert_radius")) {}
