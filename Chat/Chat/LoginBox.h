#pragma once
#include "Section.h"
#include <FL\Fl_Input.H>
#include <FL\Fl_Button.H>

class LoginBox : public Section
{
	void loginCallback(Fl_Widget *widget);
	static void staticCallback(Fl_Widget *widget, void *data)
	{
		((LoginBox*)data)->loginCallback(widget);
	}

	Fl_Input *username;
	Fl_Input *password;
	Fl_Button *submit;
public:
	void reset();
	const char* getUsername();
	const char* getPassword();
	void setCallback(Fl_Callback*, void*);
	LoginBox(int,int,int,int,char*,int);
	~LoginBox();
};

