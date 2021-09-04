#ifndef UPDATE_H_
#define UPDATE_H_

#include "json.h"

#include "../Message/message.h"

#include "../../Utils/utils.h"

// This object represents an incoming update.
// At most ONE of the optional parameters can be present in any given update
class Update {
 public:
  int32_t update_id;
};

#endif  // UPDATE_H_
