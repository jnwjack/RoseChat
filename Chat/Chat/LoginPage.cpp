#include "LoginPage.h"

const char* LoginPage::getUsername()
{
	return username;
}

void LoginPage::reset()
{
	lBox->reset();
	rBox->reset();
}

void LoginPage::loginCallback(Fl_Widget *widget)
{
	const char* usernameText = lBox->getUsername();
	const char* passwordText = lBox->getPassword();

	if (usernameText[0] != '\0' && passwordText[0] != '\0')
	{
		char filename[100];
		strcpy_s(filename, 100, DIRECTORY);
		strcat_s(filename, 100, usernameText);
		strcat_s(filename, 100, ".rose");

		std::ifstream file(filename);

		if (file.is_open())
		{
			std::string text;
			std::getline(file, text);
			if (text.compare(passwordText) == 0)
			{
				username = usernameText;
				window->loginAndSwitchPage(username);
			}
		}

		else
		{
			lBox->label("Didn't work");
		}

	}
}


LoginPage::LoginPage(RegisterBox *r, LoginBox *l, int width, int height, UserData* udata) : Page(0,0,width,height,udata)
{
	rBox = r;
	lBox = l;

	this->add(rBox);
	this->add(lBox);

	lBox->setCallback((Fl_Callback*)&LoginPage::loginCallback_s, (void*)this);

	this->end();
}


LoginPage::~LoginPage()
{
}
