#include "Participant.h"

/*void Participant::handleWrite(const boost::system::error_code& error)
{
	if (!error)
	{
		writeMessages.pop_front();
		if (!writeMessages.empty())
		{
			boost::asio::async_write(socket,
				boost::asio::buffer(writeMessages.front(),
					writeMessages.front().length()),
				boost::bind(&Participant::handleWrite, shared_from_this(),
					boost::asio::placeholders::error));
		}
	}
	else
	{
		room.leave(shared_from_this());
	}
}

void Participant::handleRead(const boost::system::error_code& error)
{
	if (!error)
	{
		room.deliver(readMessage);
		boost::asio::async_read
	}
}*/

void Participant::deliver(const Message& message)
{
	bool writeInProgress = !writeMessages.empty();
	writeMessages.push_back(message);
	if (!writeInProgress)
	{
		write();
	}
}

void Participant::write()
{
	auto self(shared_from_this());
	boost::asio::async_write(socket,
		boost::asio::buffer(writeMessages.front().getData(),
			writeMessages.front().getLength()),
		[this, self](boost::system::error_code error, std::size_t len)
	{
		if (!error)
		{
			writeMessages.pop_front();
			if (!writeMessages.empty())
			{
				write();
			}
		}
		else
		{
			room.leave(shared_from_this());
		}
	});
}


void Participant::start()
{
	room.join(shared_from_this());
	readHeader();
}

void Participant::readHeader()
{
	auto self(shared_from_this());
	boost::asio::async_read(socket,
		boost::asio::buffer(readMessage.getData(),Message::HEADER_LENGTH),
		[this, self](boost::system::error_code error, std::size_t len)
	{
		if (!error && readMessage.decodeHeader())
		{
			readBody();
		}
		else
		{
			room.leave(shared_from_this());
		}
	});
}

void Participant::readBody()
{
	auto self(shared_from_this());
	boost::asio::async_read(socket,
		boost::asio::buffer(readMessage.getBody(),readMessage.bodyLength()),
		[this, self](boost::system::error_code error, std::size_t len)
	{
		if (!error)
		{
			room.deliver(readMessage);
			readHeader();
		}
		else
		{
			room.leave(shared_from_this());
		}
	});
}

Participant::Participant(tcp::socket s, Room& r) : socket(std::move(s)),room(r)
{
}

Participant::~Participant()
{
}
