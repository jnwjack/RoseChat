#pragma once
#include "Dialog.h"
#include <thread>
#include <iostream>
class HostDialog : public Dialog
{
	Fl_Input *name;
	Fl_Input *password;
	Fl_Input *port;
	Fl_Button *submit;
	std::thread *serverThread;
	std::thread *clientThread;

	void buttonCallback(Fl_Widget*);

	static void buttonCallback_s(Fl_Widget *widget, void *data)
	{
		((HostDialog*)data)->buttonCallback(widget);
	}
public:
	HostDialog(int,int,Fl_Window*,std::thread*,std::thread*,UserData*);
	~HostDialog();
};

