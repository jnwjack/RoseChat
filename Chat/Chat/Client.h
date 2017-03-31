#pragma once
#include <boost\asio.hpp>
#include <FL\Fl_Text_Buffer.H>
#include <string>
#include <iostream>

using boost::asio::ip::tcp;

class Client
{
	boost::asio::io_service *io;
	tcp::resolver::iterator endpointIterator;
	tcp::socket *socket;
	Fl_Text_Buffer *buffer;
public:
	void send(const char*);
	Client(const char *port, const char *host=nullptr);
	~Client();
};

