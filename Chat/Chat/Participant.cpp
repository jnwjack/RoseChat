#include "Participant.h"

std::string Participant::getAddress()
{
	return (std::string)address;
}

void Participant::send(std::string message)
{
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

/*Participant::Participant(tcp::socket *s)
{
	socket = s;
	address = socket->remote_endpoint().address().to_string();
}*/

Participant::Participant(const char *addr, const char *port)
{
	io = new boost::asio::io_service();
	address = addr;
	std::cout << port;
	tcp::resolver resolver(*io);
	tcp::resolver::query query(addr, port);
	socket = new tcp::socket(*io);
	endpointIterator = resolver.resolve(query);
}


Participant::~Participant()
{
}
