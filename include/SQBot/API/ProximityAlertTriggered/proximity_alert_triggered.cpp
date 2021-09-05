#include "proximity_alert_triggered.h"

ProximityAlertTriggered::ProximityAlertTriggered(
    const Json& proximity_alert_triggered)
  : traveler(Utils::GetPtr<User>(proximity_alert_triggered, "traveler")),
    watcher(Utils::GetPtr<User>(proximity_alert_triggered, "watcher")),
    distance(Utils::GetValue<int32_t>(proximity_alert_triggered, "distance")) {}
