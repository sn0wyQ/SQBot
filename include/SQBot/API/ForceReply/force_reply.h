#ifndef FORCE_REPLY_H_
#define FORCE_REPLY_H_

#include <memory>
#include <string>

#include "../../../nlohmann/json.h"

#include "../../AbstractReplyMarkup/abstract_reply_markup.h"
#include "../../Utils/utils.h"

// Upon receiving a message with this object, Telegram clients will display a
// reply interface to the user (act as if the user has selected the bot's
// message and tapped 'Reply'). This can be extremely useful if you want to
// create user-friendly step-by-step interfaces without having
// to sacrifice privacy mode
class ForceReply : public AbstractReplyMarkup {
 public:
  ForceReply() = default;
  explicit ForceReply(const Json& force_reply);

  Json ToJson() const override;

  // Shows reply interface to the user, as if they manually selected the
  // bot's message and tapped 'Reply'
  const bool force_reply{true};

  // Optional. The placeholder to be shown in the input field when
  // the reply is active; 1-64 characters
  std::string input_text_placeholder;

  // Optional. Use this parameter if you want to force reply from specific users
  // only. Targets: 1) users that are @mentioned in the text of the
  // Message object; 2) if the bot's message is a reply
  // (has reply_to_message_id), sender of the original message
  bool selective{false};
};

using ForceReplyPtr = std::shared_ptr<ForceReply>;

#endif  // FORCE_REPLY_H_
