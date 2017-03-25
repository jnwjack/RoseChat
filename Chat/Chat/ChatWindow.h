#pragma once
#include "UserData.h"
#include <FL\Fl.H>
#include <FL\Fl_Window.H>
#include "Page.h"

class ChatWindow : public Fl_Window
{
	int handle(int);

	Page *login;
	Page *main;
	const char* username;
	UserData *user;
public:
	void logout();
	void setLoginPage(Page*);
	void setMainPage(Page*);
	void loginAndSwitchPage(const char*);
	ChatWindow(int, int, char*,UserData*);
	~ChatWindow();
};
