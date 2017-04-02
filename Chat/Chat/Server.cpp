#include "Server.h"

Server::Server()
{
	chatBuffer = new Fl_Text_Buffer();
	participants = new std::vector<Participant>();
}

void Server::read()
{
	char buf[128];	// want to make this bigger
	strcpy_s(buf, "");

	boost::system::error_code error;
	acceptor->accept(*socket); // wait for connection
	socket->async_read_some(boost::asio::buffer(buf), boost::bind(&Server::handleRead,this,
		buf,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred));
	std::cout << buf;
}

void Server::handleWrite(const boost::system::error_code&, size_t) 
{
	socket->close();
	read();
}

void Server::handleRead(char *buf, const boost::system::error_code& e, size_t len)
{
	std::cout << "hit";
	std::string tempAddress = socket->remote_endpoint().address().to_string();
	if (participants->size() == 0)
	{
		participants->push_back(Participant(tempAddress.c_str(), std::to_string(port + 1).c_str(), io));
	}
	else
	{
		for (std::vector<Participant>::iterator it = participants->begin(); it != participants->end(); it++)
		{
			if (tempAddress.compare(it->getAddress())) // if strings are not equal
			{
				participants->push_back(Participant(tempAddress.c_str(), std::to_string(port + 1).c_str(), io));
				break;
			}
		}
	}
	for (std::vector<Participant>::iterator it = participants->begin(); it != participants->end(); it++)
	{
		try
		{
			boost::asio::connect(*socket, it->getIterator());
			socket->async_write_some(boost::asio::buffer(std::string(buf)),boost::bind(&Server::handleWrite,this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
		}
		catch (std::exception &e)
		{
			std::cerr << "Server-side error: " << e.what() << std::endl;
		}
	}
}

void Server::config(const char *name, const char* password, const char *p)
{
	port = std::atoi(p);
	if (port > 65535)
		port = 7673;
	roomName = name;
	roomPassword = password;
	alive = true;
}

Fl_Text_Buffer* Server::getBuffer()
{
	return chatBuffer;
}


void Server::start()
{
	try
	{
		io = new boost::asio::io_service;
		socket = new tcp::socket(*io);
		acceptor = std::shared_ptr<tcp::acceptor>(new tcp::acceptor(*io, tcp::endpoint(tcp::v4(), port)));
		read();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}



Server::~Server()
{
}
