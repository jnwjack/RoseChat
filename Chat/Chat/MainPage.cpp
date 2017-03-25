#include "MainPage.h"

void MainPage::backCallback(Fl_Widget *widget)
{
	window->logout();
}

void MainPage::connectCallback(Fl_Widget *widget)
{
	dialogBox = new ConnectDialog(window->x() + (window->w()/3),window->y() + (window->h()/3),window);
	dialogBox->show();
}

void MainPage::hostCallback(Fl_Widget *widget)
{
	dialogBox = new HostDialog(window->x() + (window->w() / 3), window->y() + (window->h() / 3), window, serverThread,user);
	dialogBox->show();
	chatbox->setBuffer(user->getChatBuffer());
	chatbox->turnOn();
}

void MainPage::reset()
{
	chatbox->reset();
}

MainPage::MainPage(ChatBox* box, int width, int height,UserData *udata) : Page(0,0,width,height,udata)
{
	chatbox = box;
	connect = new Fl_Button(0, height - (height / 6), chatbox->x(), height / 5, "Connect");
	back = new Fl_Button(0, 0, chatbox->x(), height / 5, "@<-");
	host = new Fl_Button(chatbox->x() + chatbox->w(), height - (height / 6), chatbox->x(), height / 5, "Host");

	back->callback((Fl_Callback*)&MainPage::backCallback_s, this);
	connect->callback((Fl_Callback*)&MainPage::connectCallback_s, this);
	host->callback((Fl_Callback*)&MainPage::hostCallback_s, this);

	this->add(chatbox);
	this->add(connect);
	this->add(back);
	this->add(host);

	this->end();
}


MainPage::~MainPage()
{
	Fl::delete_widget(dialogBox);
	serverThread->join();
}
