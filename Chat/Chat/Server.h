#pragma once
#include "Participant.h"
#include <boost\bind.hpp>
#include <thread>
#include <iostream>
#include <vector>
#include <memory>
#include <FL\Fl_Text_Buffer.H>

using boost::asio::ip::tcp;

class Server
{
	boost::asio::io_service *io;
	std::shared_ptr<tcp::acceptor> acceptor;
	tcp::socket *socket;

	int port;
	const char *roomName;
	const char *roomPassword;
	bool alive;
	std::vector<Participant> *participants;
	Fl_Text_Buffer *chatBuffer;
public:
	Server();
	void read();
	void handleRead(char*, const boost::system::error_code&, size_t);
	void handleWrite(const boost::system::error_code&, size_t);
	void config(const char*, const char*, const char*);
	Fl_Text_Buffer* getBuffer();
	void start();
	~Server();
};