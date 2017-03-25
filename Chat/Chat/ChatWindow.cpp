#include "ChatWindow.h"

int ChatWindow::handle(int e)
{
	switch (e)
	{
	case FL_DEACTIVATE:
		main->deactivate();
		login->deactivate();
		return 1;
	case FL_ACTIVATE:
		main->activate();
		login->activate();
		return 1;
	default:
		return Fl_Window::handle(e);
	}
}

void ChatWindow::logout()
{
	username = "";
	login->show();
	main->hide();
	main->reset();
}

void ChatWindow::setLoginPage(Page *page)
{
	login = page;
	login->setWindow(this);
}

void ChatWindow::setMainPage(Page *page)
{
	main = page;
	main->setWindow(this);
	main->hide();
}

void ChatWindow::loginAndSwitchPage(const char *uname)
{
	username = uname;
	main->show();
	login->hide();
	login->reset();
}

ChatWindow::ChatWindow(int x, int y, char *title, UserData *udata) : Fl_Window(x, y, title)
{
	login = nullptr;
	main = nullptr;
	user = udata;
}

ChatWindow::~ChatWindow()
{
	delete main;
	delete login;
}
