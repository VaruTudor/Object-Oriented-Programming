#include "PracticalExam.h"

PracticalExam::PracticalExam(Controller& star_controller, Astronomer astr, QWidget *parent)
    : QMainWindow(parent), controller{ star_controller}, astronomer{astr}
{
    ui.setupUi(this);
    this->clicked = 0;

    this->setWindowTitle(QString::fromStdString(astronomer.get_name()));
    this->populate_list();
    this->connect_signals_and_slots();
}

void PracticalExam::connect_signals_and_slots()
{
    QObject::connect(this->ui.DysplayCheckBox, &QCheckBox::stateChanged, this, &PracticalExam::display);
    QObject::connect(this->ui.AddPushButton, &QCheckBox::clicked, this, &PracticalExam::add_star);
    QObject::connect(this->ui.SearchPushButton, &QCheckBox::clicked, this, &PracticalExam::search);
    //QObject::connect(, &QCheckBox::clicked, this, &PracticalExam::search);
}

void PracticalExam::populate_list()
{
    this->ui.StarsListWidget->clear();

    std::vector<Star> all_stars = this->controller.get_all_form_repository();

    for (auto star : all_stars)
    {
        this->ui.StarsListWidget->addItem(QString::fromStdString(star.to_string()));
    }
}

void PracticalExam::display()
{
    if (this->clicked == 0)
    {
        this->ui.StarsListWidget->clear();

        std::vector<Star> all_stars = this->controller.get_all_form_repository();

        for (auto star : all_stars)
        {
            if (star.get_constelation() == this->astronomer.get_constelation())
                this->ui.StarsListWidget->addItem(QString::fromStdString(star.to_string()));
        }
    }
    else
    {
        this->populate_list();
    }
    this->clicked = 1 - this->clicked;
}

void PracticalExam::add_star()
{
    std::string name = this->ui.nameLineEdit->text().toStdString();
    std::string Ra_str = this->ui.RALineEdit->text().toStdString();
    int RA = atoi(Ra_str.c_str());
    std::string Dec_str = this->ui.DecLineEdit->text().toStdString();
    int Dec = atoi(Dec_str.c_str());
    std::string diameter_str = this->ui.diameterLineEdit->text().toStdString();
    int diameter = atoi(diameter_str.c_str());
    std::vector<Star> all_stars = this->controller.get_all_form_repository();
    int i = 0;
    this->controller.add(name, this->astronomer.get_constelation(), RA, Dec, diameter);

    this->populate_list();
}

void PracticalExam::search()
{
    this->ui.SearchListWidget->clear();
    std::string name = this->ui.SearchLineEdit->text().toStdString();

    std::vector<Star> all_stars = this->controller.get_all_with_name(name);

    for (auto star : all_stars)
    {
        this->ui.SearchListWidget->addItem(QString::fromStdString(star.to_string()));
    }
}
