#pragma once
#include "UserData.h"
#include "Section.h"
#include "Message.h"
#include <iostream>
#include <string>
#include <FL\Fl_Text_Display.H>
#include <FL\Fl_Input.H>
#include <FL\Fl_Text_Buffer.H>
class ChatBox : public Section
{
	static void sendCallback_s(Fl_Widget *widget, void *data)
	{
		((ChatBox*)data)->sendCallback(widget);
	}

	void sendCallback(Fl_Widget*);

	Fl_Text_Display *displayBox;
	Fl_Text_Buffer *chatData;
	Fl_Input *input;
	UserData *user;
public:
	void reset();
	void setBuffer(Fl_Text_Buffer*);
	void turnOn();
	Fl_Input* getInput();
	ChatBox(int, int, int, int, int, UserData*);
	~ChatBox();
};

