#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Asignment10.h"
#include "Service.h"

class Asignment10 : public QMainWindow
{
	Q_OBJECT

public:
	Asignment10(Service& s, QWidget *parent = Q_NULLPTR);

private:
	Service& service;

	Ui::Asignment10Class ui;

	void connect_signals_and_slots();

	void populate_list();
	int get_selected_index() const;
	
	void add_victim_administrator();
	void delete_victim_administrator();
	void update_victim_administrator();

	void save_victim_assistant();
	void next_victim_assistant();

	void filter_victims();

	void change_mode();
	void open_external();
};
