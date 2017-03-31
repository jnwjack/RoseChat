#include "HostDialog.h"

void HostDialog::buttonCallback(Fl_Widget *widget)
{
	user->getServer()->config(name->value(), password->value(), port->value());
	serverThread = new std::thread(&Server::start, user->getServer());

	Client *client = new Client(port->value());
	user->setClient(client);

	otherWindow->activate();
	Fl::delete_widget(this);
}

HostDialog::HostDialog(int x, int y, Fl_Window *ptr, std::thread *threadptr, UserData *udata) : Dialog(x,y,"Host chatroom",ptr)
{
	serverThread = threadptr;
	name = new Fl_Input(this->w()/2, 0, this->w() / 2, this->h() / 6,"Server name:");
	password = new Fl_Input(this->w()/2, this->h()/4, this->w() / 2, this->h() / 6, "Server password:");
	port = new Fl_Input(this->w()/2, this->h()/2, this->w() / 2, this->h() / 6, "Port:");
	submit = new Fl_Button(this->w() / 3, (this->h()/4)*3, this->w()/3, this->h() / 6, "Create");

	user = udata;

	if (user->getServer() == nullptr)
		user->setServer(new Server());

	port->value("7673");

	submit->callback((Fl_Callback*)&HostDialog::buttonCallback_s, (void*)this);

	this->end();
}


HostDialog::~HostDialog()
{
}
