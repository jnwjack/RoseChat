#pragma once
#include "Participant.h"
#include <thread>
#include <iostream>
#include <vector>
#include <memory>
#include <FL\Fl_Text_Buffer.H>

using boost::asio::ip::tcp;

class Server
{
	tcp::socket socket;
	tcp::acceptor acceptor;
	Room room;
public:
	Server(boost::asio::io_service& io, const tcp::endpoint& endpoint);
	void start();
	boost::asio::io_service& getIoService();
	~Server();
};