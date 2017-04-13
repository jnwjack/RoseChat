#include "HostDialog.h"

void HostDialog::buttonCallback(Fl_Widget *widget)
{
	ioServer = new boost::asio::io_service();
	user->setIoServer(ioServer);
	tcp::endpoint endpoint(tcp::v4(), std::atoi(port->value()));
	user->setServer(new Server(*ioServer,endpoint));
	serverThread = new std::thread(&HostDialog::startServer, this);
	//serverThread->join();
	//ioServer.run();
	//user->getServer()->start();
	//serverIoThread = new std::thread([&ioServer]() {ioServer.run(); });

	clientThread = new std::thread(&HostDialog::startClient, this);
	//clientThread->join();
	//user->getClient()->getIoService().run();
	
	//user->getClient()->config();
	//boost::asio::io_service& io_service = user->getClient()->getIoService();
	//clientIoThread = new std::thread([&io_service]() {io_service.run(); });


	otherWindow->activate();
	//Fl::delete_widget(this);
}


void HostDialog::startClient()
{
	user->getClient()->config();
	while (true)
	{
		ioClient->run();
		ioClient->reset();
	}
	//std::thread t(&boost::asio::io_service::run,ioClient);
	//t.detach();
}

void HostDialog::startServer()
{
	user->getServer()->start();
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

	if (user->getClient() == nullptr)
	{
		ioClient = new boost::asio::io_service();
		user->setIoClient(ioClient);
		tcp::resolver resolver(*ioClient);
		//auto endpointIterator = resolver.resolve({ boost::asio::ip::host_name(),port->value() });
		auto endpointIterator = resolver.resolve({ "192.168.1.17",port->value() });
		//std::cout << boost::asio::ip::host_name();
		user->setClient(new Client(*ioClient, endpointIterator));
	}

	submit->callback((Fl_Callback*)&HostDialog::buttonCallback_s, (void*)this);

	this->end();
}


HostDialog::~HostDialog()
{
}
