#include "UserData.h"

Fl_Text_Buffer* UserData::getChatBuffer()
{
	return client->getBuffer();
}

void UserData::setServer(Server *s)
{
	server = s;
}

void UserData::setClient(Client *c)
{
	client = c;
}

void UserData::setIoServer(boost::asio::io_service *io)
{
	ioServer = io;
}

void UserData::setIoClient(boost::asio::io_service *io)
{
	ioClient = io;
}

Server* UserData::getServer()
{
	return server;
}

Client* UserData::getClient()
{
	return client;
}

/*ChatWindow* UserData::getWindow()
{
	return window;
}*/


UserData::UserData()
{
	server = nullptr;
	client = nullptr;
}


UserData::~UserData()
{
}
