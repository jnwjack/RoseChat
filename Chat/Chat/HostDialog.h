#pragma once
#include "UserData.h"
#include "Dialog.h"
#include <thread>
#include <iostream>
class HostDialog : public Dialog
{
	Fl_Input *name;
	Fl_Input *password;
	Fl_Input *port;
	Fl_Button *submit;
	UserData *user;
	std::thread *serverThread;

	void buttonCallback(Fl_Widget*);

	static void buttonCallback_s(Fl_Widget *widget, void *data)
	{
		((HostDialog*)data)->buttonCallback(widget);
	}
public:
	HostDialog(int,int,Fl_Window*,std::thread*,UserData*);
	~HostDialog();
};

