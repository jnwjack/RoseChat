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
		std::cerr << "Client-side error: " << e.what() << std::endl;
	}
}

void Client::accept()
{
	while (true)
	{
		char buf[128];
		strcpy_s(buf, "");

		tcp::socket acceptorSocket(*io);
		
		boost::system::error_code error;

		acceptor->accept(acceptorSocket);
		std::cout << "hit";
		size_t len = acceptorSocket.read_some(boost::asio::buffer(buf), error);

		buf[len] = '\0';

		if (error == boost::asio::error::eof)
			buffer->append("Someone left.");
		else if (error)
			throw boost::system::system_error(error);
		else
		{
			buffer->append(buf);
			buffer->append("\n");
		}
	}
}

Fl_Text_Buffer* Client::getBuffer()
{
	return buffer;
}

void Client::config(const char *port, const char *host)
{
	try
	{
		tcp::resolver resolver(*io);
		tcp::resolver::query *query;

		if (host)
			query = new tcp::resolver::query(host, port);
		else
			query = new tcp::resolver::query(boost::asio::ip::host_name(), port);

		socket = new tcp::socket(*io);

		endpointIterator = resolver.resolve(*query);

		acceptor = std::shared_ptr<tcp::acceptor>(new tcp::acceptor(*io, tcp::endpoint(tcp::v4(), ((int)port)+1)));
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Client::Client()
{
	buffer = new Fl_Text_Buffer();
	io = new boost::asio::io_service();
}

/*Client::Client(const char *port, const char *host)
{
	buffer = new Fl_Text_Buffer();
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

		acceptor = std::shared_ptr<tcp::acceptor>(new tcp::acceptor(*io, tcp::endpoint(tcp::v4(), (int)port)));
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}*/


Client::~Client()
{
}
