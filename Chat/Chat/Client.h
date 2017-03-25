#pragma once
#include <boost\asio.hpp>
#include <string>
#include <iostream>

using boost::asio::ip::tcp;

class Client
{
	boost::asio::io_service *io;
	tcp::resolver::iterator endpointIterator;
	tcp::socket *socket;

	bool alive;
public:
	void send(const char*);
	Client(const char *port, const char *host=nullptr);
	~Client();
};

