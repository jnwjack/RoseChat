#include "RegisterBox.h"

void RegisterBox::reset()
{
	username->value("");
	password->value("");
}

void RegisterBox::registerCallback(Fl_Widget *widget)
{
	const char* usernameText = username->value();
	const char* passwordText = password->value();

	if (usernameText[0] != '\0' && passwordText[0] != '\0')
	{
		submit->label("Registered!");
		username->value("");
		password->value("");

		char filename[100];
		strcpy_s(filename, 100, DIRECTORY);
		strcat_s(filename, 100, usernameText);
		strcat_s(filename, 100, ".rose");

		std::ofstream file(filename);
		file << passwordText << "\n";
		file.close();
	}
}

RegisterBox::RegisterBox(int x, int y, int w, int h, char *title, int bHeight) : Section(x, y, w, h, title)
{
	this->spacing(bHeight / 2);

	username = new Fl_Input(x, 0, 0, bHeight, "Username: ");
	password = new Fl_Input(x, 0, 0, bHeight, "Password: ");
	submit = new Fl_Button(x, 0, 0, bHeight, "Submit");

	submit->callback((Fl_Callback*)&RegisterBox::staticCallback, this);

	this->add(username);
	this->add(password);
	this->add(submit);

	this->end();
}


RegisterBox::~RegisterBox()
{
}