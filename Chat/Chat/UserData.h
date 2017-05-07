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
	Fl_Text_Buffer *buffer;
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
	void setUsername(const char*);
	const char* getUsername();

	Server* getServer();
	Client* getClient();
	//ChatWindow* getWindow();
	UserData();
	~UserData();
};

