#pragma once
#include "Dialog.h"
class ConnectDialog : public Dialog
{
	Fl_Button *submit;
	Fl_Input *address;
	Fl_Input *password;
	Fl_Input *port;

	void buttonCallback(Fl_Widget*);

	static void buttonCallback_s(Fl_Widget *widget, void *data)
	{
		((ConnectDialog*)data)->buttonCallback(widget);
	}

public:
	ConnectDialog(int,int, Fl_Window*,UserData*);
	~ConnectDialog();
};

