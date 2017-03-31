#include "ConnectDialog.h"

void ConnectDialog::buttonCallback(Fl_Widget *widget)
{

}

ConnectDialog::ConnectDialog(int x, int y, Fl_Window* ptr, UserData *udata) : Dialog(x,y,"Connect to chatroom",ptr)
{
	address = new Fl_Input(this->w() / 2, 0, this->w() / 2, this->h() / 6, "Server address or name:");
	password = new Fl_Input(this->w() / 2, this->h() / 4, this->w() / 2, this->h() / 6, "Server password:");
	port = new Fl_Input(this->w() / 2, this->h() / 2, this->w() / 2, this->h() / 6, "Port:");
	submit = new Fl_Button(this->w() / 3, (this->h() / 4) * 3, this->w() / 3, this->h() / 6, "Connect");

	user = udata;


}


ConnectDialog::~ConnectDialog()
{
}
