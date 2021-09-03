#ifndef MESSAGE_ID_H_
#define MESSAGE_ID_H_

#include "json.h"

#include "../../Utils/utils.h"

// This object represents a unique message identifier
class MessageId {
 public:
  MessageId() = default;
  explicit MessageId(const Json& message_id);

  // Unique message identifier
  int32_t message_id;
};

#endif  // MESSAGE_ID_H_
