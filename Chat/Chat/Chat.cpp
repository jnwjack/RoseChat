#include "MainPage.h"
//#include "ChatWindow.h"
//#include "LoginBox.h"
//#include "RegisterBox.h"
#include "LoginPage.h"
//#include "ChatBox.h"
#include <FL\Fl.H>

#define WIDTH 600
#define HEIGHT 480

int main(int argc, char **argv)
{
	UserData *user = new UserData();
	ChatWindow *window = new ChatWindow(WIDTH, HEIGHT, "RoseChat", user);
	LoginPage *login = new LoginPage(new RegisterBox(WIDTH / 5, HEIGHT / 3, WIDTH / 4, HEIGHT*(2 / 3), "Register", 30),
		new LoginBox(WIDTH - WIDTH / 3, HEIGHT / 3, WIDTH / 4, HEIGHT*(2 / 3), "Login", 30),
		WIDTH,
		HEIGHT,
		user);
	MainPage *main = new MainPage(new ChatBox((WIDTH/2)-(WIDTH/4),HEIGHT/5,WIDTH/2,HEIGHT*(2/3),30,user),
		WIDTH,
		HEIGHT,
		user);



	window->setLoginPage(login);
	window->setMainPage(main);
	//window->addRegisterBox(new RegisterBox(WIDTH / 5, HEIGHT / 3, WIDTH / 4, HEIGHT*(2 / 3), "Register", 30));
	//window->addLoginBox(new LoginBox(WIDTH - WIDTH / 3, HEIGHT / 3, WIDTH / 4, HEIGHT*(2 / 3), "Login", 30));

	window->end();
	window->show(argc, argv);

	return Fl::run();
}
