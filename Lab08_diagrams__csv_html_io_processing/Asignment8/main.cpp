#include "Repository.h"
#include "Service.h"

#include <string>
#include <sstream>
#include <iostream>
#include <crtdbg.h>
#include <windows.h>

#include "Asignment9d.h"
#include <QtWidgets/qapplication.h>
#include "GUI.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);


	FileRepository repository{ "C:\\Users\\Tudor\\Desktop\\testus\\a.txt" };
	Repository* assistant_repository{};
	Service service{ repository,assistant_repository };			

	GUI gui{service};
	

	gui.show();

	return a.exec();	
}