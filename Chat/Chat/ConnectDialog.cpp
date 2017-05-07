#include "ConnectDialog.h"

void ConnectDialog::buttonCallback(Fl_Widget *widget)
{
	io = new boost::asio::io_service();
	user->setIoClient(io);
	tcp::resolver resolver(*io);
	auto endpointIterator = resolver.resolve({ address->value(),port->value() });
	user->setClient(new Client(*io, endpointIterator,user->getChatBuffer()));
	clientThread = new std::thread(&ConnectDialog::startClient, this);
	otherWindow->activate();
	//Fl::delete_widget(this);
	this->hide();
}

void ConnectDialog::startClient()
{
	user->getClient()->config();
	user->setClientAlive(true);
	while (user->clientIsAlive())
	{
		io->run();
		io->reset();
	}
}

ConnectDialog::ConnectDialog(int x, int y, Fl_Window* ptr, std::thread *thread, UserData *udata) : Dialog(x,y,"Connect to chatroom",ptr)
{
	address = new Fl_Input(this->w() / 2, 0, this->w() / 2, this->h() / 6, "Host address or name:");
	password = new Fl_Input(this->w() / 2, this->h() / 4, this->w() / 2, this->h() / 6, "Server password:");
	port = new Fl_Input(this->w() / 2, this->h() / 2, this->w() / 2, this->h() / 6, "Port:");
	submit = new Fl_Button(this->w() / 3, (this->h() / 4) * 3, this->w() / 3, this->h() / 6, "Connect");

	clientThread = thread;

	port->value("7673");

	submit->callback((Fl_Callback*)&ConnectDialog::buttonCallback_s, (void*)this);

	user = udata;

	/*io = new boost::asio::io_service();
	user->setIoClient(io);
	tcp::resolver resolver(*io);
	std::cout << port->value();
	auto endpointIterator = resolver.resolve({ "",port->value() }); // temporary object, replaced later
	user->setClient(new Client(*io, endpointIterator));*/

	this->end();
}


ConnectDialog::~ConnectDialog()
{
}
