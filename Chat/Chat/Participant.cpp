#include "Participant.h"

std::string Participant::getAddress()
{
	return address;
}

void Participant::send(std::string message)
{
	try
	{
		socket.write_some(message);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Participant::Participant(tcp::socket *s)
{
	socket = *s;
	address = socket.remote_endpoint().address().to_string();
}


Participant::~Participant()
{
}
