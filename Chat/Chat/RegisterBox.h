#pragma once

#include "Section.h"
#include <FL\Fl_Input.H>
#include <FL\Fl_Button.H>

class RegisterBox : public Section
{
	void registerCallback(Fl_Widget*);
	static void staticCallback(Fl_Widget *widget, void *data)
	{
		((RegisterBox*)data)->registerCallback(widget);
	}

	Fl_Input *username;
	Fl_Input *password;
	Fl_Button *submit;
public:
	void reset();
	RegisterBox(int, int, int, int, char*, int);
	~RegisterBox();
};

