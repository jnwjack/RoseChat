#include "Client.h"
Client::Client(boost::asio::io_service& io,
	tcp::resolver::iterator endpointIterator, Fl_Text_Buffer *buf)
	: ioService(io), socket(io)
{
	buffer = buf;
	tempIterator = endpointIterator;
}

void Client::config()
{
	connect(tempIterator);
	//ioService.run();
}

void Client::run()
{

}

boost::asio::io_service& Client::getIoService()
{
	return ioService;
}

Client::~Client()
{

}

void Client::write(const Message& message)
{
	ioService.post(
	[this, message]()
	{
		bool writeInProgress = !writeMessages.empty();
		writeMessages.push_back(message);
		if (!writeInProgress)
		{
			doWrite();
		}
	});
}

void Client::doWrite()
{
	boost::asio::async_write(socket,
		boost::asio::buffer(writeMessages.front().getData(),
			writeMessages.front().getLength()),
		[this](boost::system::error_code error, std::size_t len)
	{
		if (!error)
		{
			writeMessages.pop_front();
			if (!writeMessages.empty())
			{
				doWrite();
			}
		}
		else
		{
			socket.close();
		}
	});
}

void Client::connect(tcp::resolver::iterator endpointIterator)
{
	boost::asio::async_connect(socket, endpointIterator,
		[this](boost::system::error_code error, tcp::resolver::iterator)
	{
		if (!error)
		{
			buffer->append("Connected to ");
			buffer->append(socket.remote_endpoint().address().to_string().c_str());
			buffer->append("\n");
			readHeader();
		}
		else
		{
			socket.close();
		}
	});
}

void Client::close()
{
	ioService.post([this]() {socket.close(); });
}

void Client::readHeader()
{
	boost::asio::async_read(socket,
		boost::asio::buffer(readMessage.getData(), Message::HEADER_LENGTH),
		[this](boost::system::error_code error, std::size_t len)
	{
		if (!error && readMessage.decodeHeader())
		{
			readBody();
		}
		else
		{
			socket.close();
		}
	});
}

void Client::readBody()
{
	boost::asio::async_read(socket,
		boost::asio::buffer(readMessage.getBody(),readMessage.bodyLength()),
		[this](boost::system::error_code error, std::size_t len)
	{
		if (!error)
		{
			std::string str(readMessage.getBody());
			std::string sub = str.substr(0, readMessage.bodyLength());
			buffer->append(sub.c_str());
			buffer->append("\n");

			readHeader();
		}
		else
		{
			socket.close();
		}
	});
}

Fl_Text_Buffer* Client::getBuffer()
{
	return buffer;
}