#include "chat_member_updated.h"

ChatMemberUpdated::ChatMemberUpdated(const Json& chat_member_updated)
  : chat(Utils::GetPtr<Chat>(chat_member_updated, "chat")),
    from(Utils::GetPtr<User>(chat_member_updated, "from")),
    date(Utils::GetValue<int32_t>(chat_member_updated, "date")),
    old_chat_member(
        Utils::GetPtr<ChatMember>(chat_member_updated, "old_chat_member")),
    new_chat_member(
        Utils::GetPtr<ChatMember>(chat_member_updated, "new_chat_member")),
    invite_link(Utils::GetPtr<ChatInviteLink>(chat_member_updated, "invite_link")) {}
