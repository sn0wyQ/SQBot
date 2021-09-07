#include "chat_member_updated.h"

ChatMemberUpdated::ChatMemberUpdated(const Json& chat_member_updated)
  : chat(SQBot::Utils::GetPtr<Chat>(chat_member_updated, "chat")),
    from(SQBot::Utils::GetPtr<User>(chat_member_updated, "from")),
    date(SQBot::Utils::GetValue<int32_t>(chat_member_updated, "date")),
    old_chat_member(SQBot::Utils::GetPtr<ChatMember>(
        chat_member_updated, "old_chat_member")),
    new_chat_member(SQBot::Utils::GetPtr<ChatMember>(
        chat_member_updated, "new_chat_member")),
    invite_link(SQBot::Utils::GetPtr<ChatInviteLink>(
        chat_member_updated, "invite_link")) {}
