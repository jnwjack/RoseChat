#include "Dialog.h"

void Dialog::windowCallback(Fl_Widget *widget)
{
	otherWindow->activate();
	Fl::delete_widget(this);
}

Dialog::Dialog(int x, int y, char *title, Fl_Window *ptr) : Fl_Window(x,y,300,200,title)
{
	otherWindow = ptr;
	otherWindow->deactivate();
	this->callback((Fl_Callback*)&Dialog::windowCallback_s, this);
}


Dialog::~Dialog()
{
}
