#include "Room.h"

void Room::join(std::shared_ptr<ChatMember> member)
{
	members.insert(member);
	for (auto message : recentMessages)
		member->deliver(message);
}

void Room::leave(std::shared_ptr<ChatMember> member)
{
	members.erase(member);
}

void Room::deliver(const Message& message)
{
	recentMessages.push_back(message);
	while (recentMessages.size() > MAX_RECENT_MESSAGES)
		recentMessages.pop_front();

	for (auto member : members)
		member->deliver(message);
}

Room::Room()
{
}


Room::~Room()
{
}
