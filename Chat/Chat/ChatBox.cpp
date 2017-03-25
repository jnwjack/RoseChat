#include "ChatBox.h"

void ChatBox::turnOn()
{
	input->activate();
	displayBox->activate();
}

void ChatBox::sendCallback(Fl_Widget *widget)
{
	const char *message = input->value();
	if (message != "")
	{
		user->getClient()->send(message);
		input->value("");
	}
	displayBox->redraw();
}

void ChatBox::setBuffer(Fl_Text_Buffer *buf)
{
	displayBox->buffer(buf);
}

void ChatBox::reset()
{
	input->value("");
}

ChatBox::ChatBox(int x, int y, int width, int height, int bHeight, UserData *u) : Section(x,y,width,height,"")
{
	this->spacing(bHeight / 2);

	displayBox = new Fl_Text_Display(x, 0, 0, bHeight*10, "");
	input = new Fl_Input(x, 0, 0, bHeight, "");
	user = u;

	input->deactivate();
	input->callback((Fl_Callback*)&ChatBox::sendCallback_s, this);
	input->when(FL_WHEN_ENTER_KEY);
	displayBox->deactivate();

	this->add(displayBox);
	this->add(input);

	this->end();
}

Fl_Input* ChatBox::getInput()
{
	return input;
}


ChatBox::~ChatBox()
{
}
