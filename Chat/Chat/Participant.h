#pragma once
#include <boost\asio.hpp>
#include <boost\bind.hpp>
#include <iostream>
#include <string>
#include "Room.h"

using boost::asio::ip::tcp;

const int MAX_BUFFER_SIZE = 1024;

class Participant : public ChatMember, public std::enable_shared_from_this<Participant>
{
	tcp::socket socket;
	Room& room;
	Message readMessage;
	std::deque<Message> writeMessages;
public:
	Participant(tcp::socket, Room&);
	~Participant();
	void deliver(const Message&);
	void start();
	void write();
	void readHeader();
	void readBody();
};

