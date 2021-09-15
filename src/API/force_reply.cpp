#include "../../include/SQBot/API/force_reply.h"

ForceReply::ForceReply(const Json& force_reply)
  : input_text_placeholder(SQBot::Utils::GetValue<std::string>(
      force_reply, "input_text_placeholder")),
    selective(SQBot::Utils::GetValue<bool>(force_reply, "selective")) {}

Json ForceReply::ToJson() const {
  Json force_reply_json;

  force_reply_json["force_reply"] = force_reply;

  if (!input_text_placeholder.empty()) {
    force_reply_json["input_text_placeholder"] = input_text_placeholder;
  }

  if (selective) {
    force_reply_json["selective"] = selective;
  }

  return force_reply_json;
}
