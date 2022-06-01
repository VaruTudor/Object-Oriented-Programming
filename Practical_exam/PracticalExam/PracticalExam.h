#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PracticalExam.h"
#include "Repository.h"
#include "Controller.h"

class PracticalExam : public QMainWindow
{
    Q_OBJECT

public:
    PracticalExam(Controller& star_controller, Astronomer astr, QWidget *parent = Q_NULLPTR);

private:
    Controller& controller;
    Astronomer astronomer;
    int clicked;
    Ui::PracticalExamClass ui;

    void connect_signals_and_slots();

    void populate_list();
    void display();

    /*
        adds a star to the list widget of stars
    */
    void add_star();
    void search();

};
