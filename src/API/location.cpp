#include "../../include/SQBot/API/location.h"

Location::Location(const Json& location)
  : longitude(SQBot::Utils::GetValue<float>(location, "longitude")),
    latitude(SQBot::Utils::GetValue<float>(location, "latitude")),
    horizontal_accuracy(SQBot::Utils::GetValue<float>(
        location, "horizontal_accuracy")),
    live_period(SQBot::Utils::GetValue<int32_t>(location, "live_period")),
    heading(SQBot::Utils::GetValue<int32_t>(location, "heading")),
    proximity_alert_radius(SQBot::Utils::GetValue<int32_t>(
        location, "proximity_alert_radius")) {}
