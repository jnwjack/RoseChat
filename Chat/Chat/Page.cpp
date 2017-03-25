#include "Page.h"

int Page::handle(int e)
{
	Fl_Widget *const* members;
	int numMembers;
	switch (e)
	{
	case FL_DEACTIVATE:
		members = this->array();
		numMembers = this->children();
		for (int i = 0; i <= numMembers - 1; i++)
		{
			members[i]->deactivate();
		}
		return 1;
	case FL_ACTIVATE:
		members = this->array();
		numMembers = this->children();
		for (int i = 0; i <= numMembers - 1; i++)
			members[i]->activate();
		return 1;
	default:
		return Fl_Group::handle(e);
	}
}

void Page::setWindow(ChatWindow *w)
{
	window = w;
}

Page::Page(int x, int y, int width, int height, UserData *udata) : Fl_Group(x,y,width,height,"")
{
	title = new Fl_Box(x+(width/4), 0, width/2, height/6,"RoseChat");
	user = udata;

	title->box(FL_NO_BOX);
	title->labelcolor(FL_RED);
	title->labeltype(FL_EMBOSSED_LABEL);
	title->labelsize(36);
	this->add(title);
}


Page::~Page()
{
}
