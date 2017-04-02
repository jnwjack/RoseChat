#include "Server.h"

Server::Server()
{
	chatBuffer = new Fl_Text_Buffer();
	participants = new std::vector<Participant>();
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
		acceptor = std::shared_ptr<tcp::acceptor>(new tcp::acceptor(*io, tcp::endpoint(tcp::v4(), port)));


		while (alive)
		{
			char buf[128];	// want to make this bigger
			strcpy_s(buf, "");

			boost::system::error_code error;
			tcp::socket socket(*io);
			acceptor->accept(socket); // wait for connection
			size_t len = socket.read_some(boost::asio::buffer(buf), error);

			std::string tempAddress = socket.remote_endpoint().address().to_string();
			if (participants->size() == 0)
			{
				participants->push_back(Participant(tempAddress.c_str(), std::to_string(port+1).c_str()));
			}
			else
			{
				for (std::vector<Participant>::iterator it = participants->begin(); it != participants->end(); it++)
				{
					if (tempAddress.compare(it->getAddress())) // if strings are not equal
					{
						participants->push_back(Participant(tempAddress.c_str(), std::to_string(port+1).c_str()));
						break;
					}
				}
			}
			buf[len] = '\0';
			for (std::vector<Participant>::iterator it = participants->begin(); it != participants->end(); it++)
			{
				it->send(std::string(buf));
			}
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}



Server::~Server()
{
}
