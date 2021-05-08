#include "Asignment10.h"

#include <sstream>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

Asignment10::Asignment10(Service& s, QWidget* parent)
	: QMainWindow(parent), service{ s }
{
	ui.setupUi(this);

	this->populate_list();
	this->connect_signals_and_slots();
}

void Asignment10::connect_signals_and_slots()
{
	QObject::connect(this->ui.AdministratorListWidget, &QListWidget::itemSelectionChanged, [this]() {
		int selected_index = this->get_selected_index();

		if (selected_index == -1)
			return;

		Victim victim = this->service.get_all_victims()[selected_index];
		this->ui.NameLineEdit->setText(QString::fromStdString(victim.get_name()));
		this->ui.PlaceLineEdit->setText(QString::fromStdString(victim.get_place_of_origin()));

		int age = victim.get_age();
		string age_string = std::to_string(age);

		this->ui.AgeLineEdit->setText(QString::fromStdString(age_string));
		this->ui.PhotographLineEdit->setText(QString::fromStdString(victim.get_photograph()));

		});

	QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &Asignment10::add_victim_administrator);
	QObject::connect(this->ui.deleteButton, &QPushButton::clicked, this, &Asignment10::delete_victim_administrator);
	QObject::connect(this->ui.updateButton, &QPushButton::clicked, this, &Asignment10::update_victim_administrator);
	QObject::connect(this->ui.saveButton, &QPushButton::clicked, this, &Asignment10::save_victim_assistant);
	QObject::connect(this->ui.nextButton, &QPushButton::clicked, this, &Asignment10::next_victim_assistant);
	QObject::connect(this->ui.filterButton, &QPushButton::clicked, this, &Asignment10::filter_victims);
	QObject::connect(this->ui.ChangeModePushButton, &QPushButton::clicked, this, &Asignment10::change_mode);
	QObject::connect(this->ui.OpenPushButton, &QPushButton::clicked, this, &Asignment10::open_external);
}

void Asignment10::populate_list()
{
	this->ui.AdministratorListWidget->clear();
	this->ui.AssistantListWidge2->clear();

	vector<Victim> all_victims = this->service.get_all_victims();
	vector<Victim> all_victims_assistant = this->service.get_all_victims_assistant();

	for (Victim& victim : all_victims)
	{
		this->ui.AdministratorListWidget->addItem(QString::fromStdString(victim.victim_to_string()));
	}
	
	for (Victim& victim : all_victims_assistant)
	{
		this->ui.AssistantListWidge2->addItem(QString::fromStdString(victim.victim_to_string()));
	}
}

int Asignment10::get_selected_index() const
{
	QModelIndexList selected_indexes = this->ui.AdministratorListWidget->selectionModel()->selectedIndexes();

	if (selected_indexes.size() == 0)
	{
		this->ui.NameLineEdit->clear();
		this->ui.PlaceLineEdit->clear();
		this->ui.AgeLineEdit->clear();
		this->ui.PhotographLineEdit->clear();

		return -1;
	}

	int selected_index = selected_indexes.at(0).row();
	return selected_index;
}

void Asignment10::add_victim_administrator()
{
	string name = this->ui.NameLineEdit->text().toStdString();
	string place_of_origin = this->ui.PlaceLineEdit->text().toStdString();
	string age_string = this->ui.AgeLineEdit->text().toStdString();

	// transforming the age string into an intiger
	int age;
	stringstream age_stream(age_string);
	age_stream >> age;

	string photograph = this->ui.PhotographLineEdit->text().toStdString();

	this->service.add_victim_service(name, place_of_origin, age, photograph);

	// syncronize the list with the memory repository
	this->populate_list();

	// set selection on the last added victim
	int last_element = this->service.get_all_victims().size() - 1;
	this->ui.AdministratorListWidget->setCurrentRow(last_element);
}

void Asignment10::delete_victim_administrator()
{
	string name = this->ui.NameLineEdit->text().toStdString();

	this->service.remove_victim_service(name);

	this->populate_list();

	// set selection on the first added victim
	this->ui.AdministratorListWidget->setCurrentRow(0);
}

void Asignment10::update_victim_administrator()
{
	string name = this->ui.NameLineEdit->text().toStdString();
	string place_of_origin = this->ui.PlaceLineEdit->text().toStdString();
	string age_string = this->ui.AgeLineEdit->text().toStdString();

	// transforming the age string into an intiger
	int age;
	stringstream age_stream(age_string);
	age_stream >> age;

	string photograph = this->ui.PhotographLineEdit->text().toStdString();

	this->service.update_victim_service(name, place_of_origin, age, photograph);

	// syncronize the list with the memory repository
	this->populate_list();

	// set selection on the last added victim
	int index = this->service.find_victim_index_using_name(name);
	this->ui.AdministratorListWidget->setCurrentRow(index);
}

void Asignment10::save_victim_assistant()
{
	string name = this->ui.NameLineEdit->text().toStdString();

	this->service.add_victim_to_assistant_service(name);

	this->populate_list();

	// set selection on the last added victim
	int index = this->service.find_victim_index_using_name(name);
	this->ui.AdministratorListWidget->setCurrentRow(index+1);
}

void Asignment10::next_victim_assistant()
{
	string name = this->ui.NameLineEdit->text().toStdString();

	this->populate_list();

	// set selection on the last added victim
	int index = this->service.find_victim_index_using_name(name);
	if (index != this->service.get_all_victims().size()-1 )
		this->ui.AdministratorListWidget->setCurrentRow(index + 1);
	else 
		this->ui.AdministratorListWidget->setCurrentRow(0);
}

void Asignment10::filter_victims()
{
	this->ui.FilterListWidget->clear();

	string place_of_origin = this->ui.FilterPlaceLineEdit->text().toStdString();
	string age_string = this->ui.FilterAgeLineEdit->text().toStdString();

	// transforming the age string into an intiger
	int age;
	stringstream age_stream(age_string);
	age_stream >> age;

	std::vector<Victim> filtered_victims = this->service.filer(place_of_origin, age);

	for (Victim& victim : filtered_victims)
	{
		this->ui.FilterListWidget->addItem(QString::fromStdString(victim.victim_to_string()));
	}
}

void Asignment10::change_mode()
{
	this->service.set_mode(abs(this->service.get_mode()-1));
}

void Asignment10::open_external()
{
	ShellExecuteA(NULL, "open", this->service.get_assistant_path().c_str(), NULL, NULL, SW_SHOWNORMAL);
}
