#include "Participant.h"

std::string Participant::getAddress()
{
	return (std::string)address;
}

/*void Participant::send(std::string message)
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
}*/

/*Participant::Participant(tcp::socket *s)
{
	socket = s;
	address = socket->remote_endpoint().address().to_string();
}*/

tcp::resolver::iterator Participant::getIterator()
{
	return endpointIterator;
}

Participant::Participant(const char *addr, const char *port, boost::asio::io_service *io)
{
	address = addr;
	tcp::resolver resolver(*io);
	tcp::resolver::query query(addr, port);
	endpointIterator = resolver.resolve(query);
}


Participant::~Participant()
{
}
