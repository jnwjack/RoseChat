#include "Client.h"

void Client::send(const char *string)
{
	std::string message(string);

	try
	{
		boost::asio::connect(*socket, endpointIterator);
		socket->write_some(boost::asio::buffer(message));
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Client::Client(const char *port, const char *host)
{
	try
	{
		io = new boost::asio::io_service;

		tcp::resolver resolver(*io);
		tcp::resolver::query *query;

		if (host)
			query = new tcp::resolver::query(host, port);
		else
			query = new tcp::resolver::query(boost::asio::ip::host_name(), port);

		socket = new tcp::socket(*io);


		endpointIterator = resolver.resolve(*query);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}


Client::~Client()
{
}
