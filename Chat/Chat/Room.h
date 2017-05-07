#pragma once
#include "ChatMember.h"
#include <memory>
#include <deque>
#include <set>
#include <algorithm>
#include <boost\bind.hpp>

const int MAX_RECENT_MESSAGES = 100;

class Room
{
	std::set<std::shared_ptr<ChatMember>> members;	// I wanna get off bjarne stroustroup's wild ride
	std::deque<Message> recentMessages;
public:
	void join(std::shared_ptr<ChatMember>);
	void leave(std::shared_ptr<ChatMember>);
	void deliver(const Message&);
	Room();
	~Room();
};

