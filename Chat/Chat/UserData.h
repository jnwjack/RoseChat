#pragma once

#include "Client.h"
#include "Server.h"
#include "FL\Fl_Text_Buffer.H"

class UserData
{
	Server *server;
	Client *client;
	//ChatWindow *window;
	const char* username;
	//TODO: store username and password and preferences
public:
	Fl_Text_Buffer* getChatBuffer();
	void setServer(Server*);
	void setClient(Client*);

	Server* getServer();
	Client* getClient();
	//ChatWindow* getWindow();
	UserData();
	~UserData();
};

