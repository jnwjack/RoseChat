#pragma once
#include "Dialog.h"
#include <iostream>
#include <functional>
#include <string>
class HostDialog : public Dialog
{
	Fl_Input *name;
	Fl_Input *password;
	Fl_Input *port;
	Fl_Button *submit;
	std::thread *serverThread;
	std::thread *clientThread;
	std::thread *serverIoThread;
	std::thread *clientIoThread;
	boost::asio::io_service *ioServer;
	boost::asio::io_service *ioClient;

	bool clientThreadAlive;
	bool serverThreadAlive;

	void buttonCallback(Fl_Widget*);

	static void buttonCallback_s(Fl_Widget *widget, void *data)
	{
		((HostDialog*)data)->buttonCallback(widget);
	}
	void startServer();

	void startClient();

public:

	HostDialog(int,int,Fl_Window*,std::thread*,std::thread*,std::thread*,std::thread*,UserData*);
	~HostDialog();
};

