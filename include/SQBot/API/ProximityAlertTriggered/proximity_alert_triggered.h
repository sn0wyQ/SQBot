#ifndef INCLUDE_SQBOT_API_PROXIMITYALERTTRIGGERED_PROXIMITY_ALERT_TRIGGERED_H_
#define INCLUDE_SQBOT_API_PROXIMITYALERTTRIGGERED_PROXIMITY_ALERT_TRIGGERED_H_

#include <memory>

#include "json.h"

#include "../User/user.h"

#include "../../Utils/utils.h"

// This object represents the content of a service message, sent
// whenever a user in the chat triggers a proximity alert set by another user
class ProximityAlertTriggered {
 public:
  ProximityAlertTriggered() = default;
  explicit ProximityAlertTriggered(const Json& proximity_alert_triggered);

  // User that triggered the alert
  std::shared_ptr<User> traveler;

  // User that set the alert
  std::shared_ptr<User> watcher;

  // The distance between the users
  int32_t distance{};
};

#endif  // INCLUDE_SQBOT_API_PROXIMITYALERTTRIGGERED_PROXIMITY_ALERT_TRIGGERED_H_
