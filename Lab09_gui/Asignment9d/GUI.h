#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>

#include "Service.h"

class GUI : public QWidget
{
private:
	Service& service;

	//graphical elems
	QListWidget* victims_list_widget;

	QLineEdit* name_line_edit;
	QLineEdit* place_line_edit;
	QLineEdit* age_line_edit;
	QLineEdit* photograph_line_edit;

	QPushButton* add_button, * delete_button, *update_button;

public:
	GUI(Service& s);

private:
	void init_gui();
	void populate_victims_list();
	void connect_signals_and_slots();

	int get_selected_index() const;
	void add_victim();
	void delete_victim();
	void update_victim();
};

