#include "Server.h"

Server::Server(boost::asio::io_service& io, const tcp::endpoint& endpoint) : acceptor(io, endpoint), socket(io)
{
}

boost::asio::io_service& Server::getIoService()
{
	return socket.get_io_service();
}

void Server::start()
{
	std::cout << "fhafjef";
	acceptor.async_accept(socket,
		[this](boost::system::error_code error)
	{
		std::cout << "server: accepted connection";
		if (!error)
		{
			std::make_shared<Participant>(std::move(socket), room)->start();
		}

		start();
	});
}



Server::~Server()
{
}
