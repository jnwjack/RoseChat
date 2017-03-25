#pragma once
#include <FL\Fl.H>
#include <FL\Fl_Window.H>
#include <FL\Fl_Input.H>
#include <FL\Fl_Button.H>
class Dialog : public Fl_Window
{
	void windowCallback(Fl_Widget*);
	static void windowCallback_s(Fl_Widget *widget, void *data)
	{
		((Dialog*)data)->windowCallback(widget);
	}

protected:
	Fl_Window *otherWindow;

public:
	Dialog(int,int,char*,Fl_Window*);
	~Dialog();
};

