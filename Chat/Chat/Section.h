#include <FL\Fl_Pack.H>
#include <string>
#include <fstream>
#pragma once
class Section : public Fl_Pack
{
protected:
	static void renameCallback(Fl_Widget* widget, char* data)
	{
		widget->label(data); 
	}
	
	const char* DIRECTORY = "data\\users\\";
public:
	Section(int, int, int, int, char*);
	~Section();
};
