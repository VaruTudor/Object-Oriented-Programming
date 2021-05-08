#include "GUI.h"

#include <qlayout.h>
#include <qformlayout.h>
#include <qgridlayout.h>

#include <vector>
#include <sstream>
#include <string>

using namespace std;

GUI::GUI(Service& s) : service{ s }
{
	this->init_gui();
	this->populate_victims_list();
	this->connect_signals_and_slots();
}

void GUI::init_gui()
{
	this->victims_list_widget = new QListWidget{};
	this->victims_list_widget->setStyleSheet("background-color:#c8c8c8;");

	this->name_line_edit = new QLineEdit{};
	this->name_line_edit->setStyleSheet("background-color:#b0b0b0;");
	this->place_line_edit = new QLineEdit{};
	this->place_line_edit->setStyleSheet("background-color:#b0b0b0;");
	this->age_line_edit = new QLineEdit{};
	this->age_line_edit->setStyleSheet("background-color:#b0b0b0;");
	this->photograph_line_edit = new QLineEdit{};
	this->photograph_line_edit->setStyleSheet("background-color:#b0b0b0;");

	this->add_button = new QPushButton{"add"};
	this->add_button->setStyleSheet("background-color:#696969;");
	this->delete_button = new QPushButton{"delete"};
	this->delete_button->setStyleSheet("background-color:#696969;");
	this->update_button = new QPushButton{"update"};
	this->update_button->setStyleSheet("background-color:#696969;");

	QVBoxLayout* main_layout = new QVBoxLayout{ this };

	main_layout->addWidget(this->victims_list_widget);

	QFormLayout* victim_details_layout = new QFormLayout{};
	victim_details_layout->addRow("Name", this->name_line_edit);
	victim_details_layout->addRow("Place of origin", this->place_line_edit);
	victim_details_layout->addRow("Age", this->age_line_edit);
	victim_details_layout->addRow("Photograph", this->photograph_line_edit);

	main_layout->addLayout(victim_details_layout);

	QGridLayout* buttons_layout = new QGridLayout{};
	buttons_layout->addWidget(this->add_button, 0, 0);
	buttons_layout->addWidget(this->delete_button, 0, 1);
	buttons_layout->addWidget(this->update_button, 0, 2);

	main_layout->addLayout(buttons_layout);
}

void GUI::populate_victims_list()
{
	this->victims_list_widget->clear();

	vector<Victim> all_victims = this->service.get_all_victims();

	for (Victim& victim : all_victims)
	{
		this->victims_list_widget->addItem(QString::fromStdString(victim.victim_to_string() ) );
	}
}

void GUI::connect_signals_and_slots()
{
	QObject::connect(this->victims_list_widget, &QListWidget::itemSelectionChanged, [this]() {
		int selected_index = this->get_selected_index();

		if (selected_index == -1)
			return;

		Victim victim = this->service.get_all_victims()[selected_index];
		this->name_line_edit->setText(QString::fromStdString(victim.get_name() ) );
		this->place_line_edit->setText(QString::fromStdString(victim.get_place_of_origin() ) );
		
		int age = victim.get_age();
		string age_string = std::to_string(age);
		
		this->age_line_edit->setText(QString::fromStdString(age_string ) );
		this->photograph_line_edit->setText(QString::fromStdString(victim.get_photograph() ) );

		});

	QObject::connect(this->add_button, &QPushButton::clicked, this, &GUI::add_victim);
	QObject::connect(this->delete_button, &QPushButton::clicked, this, &GUI::delete_victim);
	QObject::connect(this->update_button, &QPushButton::clicked, this, &GUI::update_victim);
}

int GUI::get_selected_index() const
{
	QModelIndexList selected_indexes = this->victims_list_widget->selectionModel()->selectedIndexes();

	if (selected_indexes.size() == 0)
	{
		this->name_line_edit->clear();
		this->place_line_edit->clear();
		this->age_line_edit->clear();
		this->photograph_line_edit->clear();
		
		return -1;
	}

	int selected_index = selected_indexes.at(0).row();
	return selected_index;
}

void GUI::add_victim()
{
	string name = this->name_line_edit->text().toStdString();
	string place_of_origin = this->place_line_edit->text().toStdString();
	string age_string = this->age_line_edit->text().toStdString();

	// transforming the age string into an intiger
	int age;
	stringstream age_stream(age_string);
	age_stream >> age;

	string photograph = this->photograph_line_edit->text().toStdString();

	this->service.add_victim_service(name, place_of_origin, age, photograph);

	// syncronize the list with the memory repository
	this->populate_victims_list();

	// set selection on the last added victim
	int last_element = this->service.get_all_victims().size() - 1;
	this->victims_list_widget->setCurrentRow(last_element);

}

void GUI::delete_victim()
{
	string name = this->name_line_edit->text().toStdString();

	this->service.remove_victim_service(name);

	this->populate_victims_list();

	// set selection on the first added victim
	this->victims_list_widget->setCurrentRow(0);
}

void GUI::update_victim()
{
	string name = this->name_line_edit->text().toStdString();
	string place_of_origin = this->place_line_edit->text().toStdString();
	string age_string = this->age_line_edit->text().toStdString();

	// transforming the age string into an intiger
	int age;
	stringstream age_stream(age_string);
	age_stream >> age;

	string photograph = this->photograph_line_edit->text().toStdString();

	this->service.update_victim_service(name, place_of_origin, age, photograph);

	// syncronize the list with the memory repository
	this->populate_victims_list();

	// set selection on the last added victim
	int index = this->service.find_victim_index_using_name(name);
	this->victims_list_widget->setCurrentRow(index);
}