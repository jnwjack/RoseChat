#pragma once
#include "Message.h"
#include <boost\asio.hpp>
#include <FL\Fl_Text_Buffer.H>
#include <string>
#include <deque>
#include <iostream>

using boost::asio::ip::tcp;

class Client
{
	boost::asio::io_service& ioService;
	tcp::socket socket;
	Message readMessage;
	tcp::resolver::iterator tempIterator;
	std::deque<Message> writeMessages;
	Fl_Text_Buffer *buffer;

	void connect(tcp::resolver::iterator);
	void readHeader();
	void readBody();
	void doWrite();
public:
	boost::asio::io_service& getIoService();
	void write(const Message&);
	void close();
	void config();
	void run();
	Fl_Text_Buffer* getBuffer();
	Client(boost::asio::io_service&,tcp::resolver::iterator, Fl_Text_Buffer*);
	~Client();
};

