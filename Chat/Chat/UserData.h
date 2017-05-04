#pragma once

#include "Client.h"
#include "Server.h"
#include "FL\Fl_Text_Buffer.H"

class UserData
{
	Server *server;
	Client *client;
	boost::asio::io_service *ioServer;
	boost::asio::io_service *ioClient;
	bool serverAlive;
	bool clientAlive;
	//ChatWindow *window;
	const char* username;
	//TODO: store username and password and preferences
public:
	Fl_Text_Buffer* getChatBuffer();
	void setServer(Server*);
	void setClient(Client*);
	void setIoServer(boost::asio::io_service*);
	void setIoClient(boost::asio::io_service*);
	void setServerAlive(bool);
	void setClientAlive(bool);
	bool serverIsAlive();
	bool clientIsAlive();

	Server* getServer();
	Client* getClient();
	//ChatWindow* getWindow();
	UserData();
	~UserData();
};

