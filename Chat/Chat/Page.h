#pragma once
#include <FL\Fl_Group.H>
#include <FL\Fl_Box.H>
class UserData;
class ChatWindow;

class Page : public Fl_Group
{
	int handle(int);
protected:
	Fl_Box *title;
	UserData *user;
	ChatWindow *window;
public:
	virtual void reset() {}
	void setWindow(ChatWindow*);
	Page(int,int,int,int,UserData*);
	~Page();
};

