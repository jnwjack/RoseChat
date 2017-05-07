#pragma once
#include <string>
#include "Message.h"
class ChatMember
{
public:
	ChatMember();
	virtual ~ChatMember() {}
	virtual void deliver(const Message&) = 0;
};

