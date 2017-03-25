#include "LoginBox.h"

void LoginBox::setCallback(Fl_Callback *cb, void *data)
{
	submit->callback(cb, data);
}

void LoginBox::reset()
{
	username->value("");
	password->value("");
}

const char* LoginBox::getUsername()
{
	return username->value();
}

const char* LoginBox::getPassword()
{
	return password->value();
}

void LoginBox::loginCallback(Fl_Widget *widget)
{
	const char* usernameText = username->value();
	const char* passwordText = password->value();

	if (usernameText[0] != '\0' && passwordText[0] != '\0')
	{
		char filename[100];
		strcpy_s(filename, 100, DIRECTORY);
		strcat_s(filename, 100, usernameText);
		strcat_s(filename, 100, ".rose");

		std::ifstream file(filename);
		
		if (file.is_open())
		{
			submit->label("Success!");
		}

		else
		{
			submit->label("Incorrect");
		}

	}
}

LoginBox::LoginBox(int x, int y, int w, int h, char *title, int bHeight) : Section(x, y, w, h, title)
{
	this->spacing(bHeight / 2);

	username = new Fl_Input(x, 0, 0, bHeight, "Username: ");
	password = new Fl_Input(x, 0, 0, bHeight, "Password: ");
	submit = new Fl_Button(x, 0, 0, bHeight, "Login");

	submit->callback((Fl_Callback*)&LoginBox::staticCallback, this);

	this->add(username);
	this->add(password);
	this->add(submit);

	this->end();
}

LoginBox::~LoginBox()
{

}