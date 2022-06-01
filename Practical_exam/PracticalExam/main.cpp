#include "PracticalExam.h"
#include <QtWidgets/QApplication>
#include "Controller.h"


void test_add_controller_and_repository()
{
    test_add_controller();
    test_add_repository();
}

int main(int argc, char *argv[])
{
    test_add_controller_and_repository();

    QApplication a(argc, argv);

    FileRepository<Star> all_stars{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\PracticalExam\\stars.txt" };
    FileRepository<Astronomer> all_astronomers{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\PracticalExam\\astronomers.txt" };
    
    Controller controller{ all_stars };

    for (auto astronomer : all_astronomers.get_all_items())
    {
        std::string title = astronomer.get_name();
        PracticalExam* w = new PracticalExam{ controller, astronomer };
        w->show();
    }


    return a.exec();
}
