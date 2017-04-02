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
