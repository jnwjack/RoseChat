#pragma once
#include "Page.h"
#include "RegisterBox.h"
#include "LoginBox.h"
#include "ChatWindow.h"
#include <string>
#include <sstream>
class LoginPage : public Page
{
	void loginCallback(Fl_Widget*);
	static void loginCallback_s(Fl_Widget *widget, void *data)
	{
		((LoginPage*)data)->loginCallback(widget);
	}

	LoginBox *lBox;
	RegisterBox *rBox;
	const char* username;
	const char* DIRECTORY = "data\\users\\";
public:
	void reset();
	const char* getUsername();
	LoginPage(RegisterBox*,LoginBox*,int,int,UserData*);
	~LoginPage();
};

