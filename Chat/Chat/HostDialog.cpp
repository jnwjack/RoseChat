#include "HostDialog.h"

void HostDialog::buttonCallback(Fl_Widget *widget)
{
	ioServer = new boost::asio::io_service();
	user->setIoServer(ioServer);
	tcp::endpoint endpoint(tcp::v4(), std::atoi(port->value()));
	user->setServer(new Server(*ioServer,endpoint));
	serverThread = new std::thread(&HostDialog::startServer, this);
	clientThread = new std::thread(&HostDialog::startClient, this);
	otherWindow->activate();
	//Fl::delete_widget(this);
	this->hide();
}


void HostDialog::startClient()
{
	user->getClient()->config();
	user->setClientAlive(true);
	while (user->clientIsAlive())
	{
		ioClient->run();
		ioClient->reset();
	}
}

void HostDialog::startServer()
{
	user->getServer()->start();
	user->setServerAlive(true);
	ioServer->run();
}

HostDialog::HostDialog(int x, int y, Fl_Window *ptr, std::thread *firstThread, std::thread *secondThread, 
	std::thread *thirdThread, std::thread *fourthThread, UserData *udata) : Dialog(x,y,"Host chatroom",ptr)
{
	serverThread = firstThread;
	clientThread = secondThread;
	serverIoThread = thirdThread;
	clientIoThread = fourthThread;

	name = new Fl_Input(this->w()/2, 0, this->w() / 2, this->h() / 6,"Server name:");
	password = new Fl_Input(this->w()/2, this->h()/4, this->w() / 2, this->h() / 6, "Server password:");
	port = new Fl_Input(this->w()/2, this->h()/2, this->w() / 2, this->h() / 6, "Port:");
	submit = new Fl_Button(this->w() / 3, (this->h()/4)*3, this->w()/3, this->h() / 6, "Create");

	user = udata;

	port->value("7673");

	ioClient = new boost::asio::io_service();
	user->setIoClient(ioClient);
	tcp::resolver resolver(*ioClient);
	auto endpointIterator = resolver.resolve({ boost::asio::ip::host_name(),port->value() });
	user->setClient(new Client(*ioClient, endpointIterator));

	submit->callback((Fl_Callback*)&HostDialog::buttonCallback_s, (void*)this);

	this->end();
}


HostDialog::~HostDialog()
{
}
