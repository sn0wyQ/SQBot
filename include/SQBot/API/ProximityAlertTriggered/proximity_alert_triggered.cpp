#include "proximity_alert_triggered.h"

ProximityAlertTriggered::ProximityAlertTriggered(
    const Json& proximity_alert_triggered)
  : traveler(SQBot::Utils::GetPtr<User>(proximity_alert_triggered, "traveler")),
    watcher(SQBot::Utils::GetPtr<User>(proximity_alert_triggered, "watcher")),
    distance(SQBot::Utils::GetValue<int32_t>(proximity_alert_triggered, "distance")) {}
