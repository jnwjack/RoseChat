#pragma once
#include "HostDialog.h"
#include "Page.h"
#include "ChatBox.h"
#include "ConnectDialog.h"
#include "ChatWindow.h"
#include <FL\Fl_Button.H>
#include <thread>
class MainPage : public Page
{
	void backCallback(Fl_Widget*);
	void connectCallback(Fl_Widget*);
	void hostCallback(Fl_Widget*);

	static void backCallback_s(Fl_Widget *widget, void *data)
	{
		((MainPage*)data)->backCallback(widget);
	}
	static void connectCallback_s(Fl_Widget *widget, void *data)
	{
		((MainPage*)data)->connectCallback(widget);
	}
	static void hostCallback_s(Fl_Widget *widget, void *data)
	{
		((MainPage*)data)->hostCallback(widget);
	}

	ChatBox *chatbox;
	Fl_Button *connect;
	Fl_Button *back;
	Fl_Button *host;
	Dialog *dialogBox;

	std::thread *serverThread;
	std::thread *clientThread;
	std::thread *serverIoThread;
	std::thread *clientIoThread;
public:
	void reset();
	MainPage(ChatBox*,int,int,UserData*);
	~MainPage();
};

