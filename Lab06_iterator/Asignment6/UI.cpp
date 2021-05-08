#include "UI.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>


using namespace std;

void UI::list_all_ui()
{
	DynamicVector<Victim> victims = this->service.get_all_victims();
	for (int i = 0; i < victims.get_size(); i++)
	{
		Victim victim = victims.get_element(i);
		cout << victim.victim_to_string() << endl;
	}
}

void UI::list_all_form_assistant_ui()
{
	DynamicVector<Victim> victims = this->service.get_all_victims_assistant();
	for (int i = 0; i < victims.get_size(); i++)
	{
		Victim victim = victims.get_element(i);
		cout << victim.victim_to_string() << endl;
	}
}

void UI::list_by_place_of_origin(std::string place_of_origin, int age)
{
	DynamicVector<Victim> victims = this->service.get_all_victims();
	for (int i = 0; i < victims.get_size(); i++)
	{
		Victim victim = victims.get_element(i);
		if (victim.get_place_of_origin().compare(place_of_origin) == 0 && victim.get_age() < age)
			cout << victim.victim_to_string() << endl;
	}
}

void UI::list_filtered(int age)
{
	DynamicVector<Victim> victims = this->service.get_all_victims();
	for (int i = 0; i < victims.get_size(); i++)
	{
		Victim victim = victims.get_element(i);
		if (victim.get_age() < age)
			cout << victim.victim_to_string() << endl;
	}
}

void UI::run()
{
	int mode = -1;
	int current_victim_in_assistant_archive = -1;
	while (true)
	{
		std::string command, command_key, argument_1_name_of_victim_or_mode, argument_2_place_of_origin_of_victim, argument_3_age_of_victim, argument_4_photograph_of_victim;
		getline(cin, command);
		std::stringstream command_stream(command);
		std::getline(command_stream, command_key, ' ');

		if (command_key == "exit")
		{
			break;
		}
		else if (command_key == "mode")
		{
			std::getline(command_stream, argument_1_name_of_victim_or_mode, ',');
			if (argument_1_name_of_victim_or_mode == "A")
				mode = 1;
			if (argument_1_name_of_victim_or_mode == "B")
				mode = 0;
		}
		else if (command_key == "delete")
		{
			std::getline(command_stream, argument_1_name_of_victim_or_mode, ',');

			if (mode == 1)
				this->service.remove_victim_service(argument_1_name_of_victim_or_mode);
			else cout << "wrong mode" << endl;
		}
		else if (command_key == "add")
		{

			std::getline(command_stream, argument_1_name_of_victim_or_mode, ',');
			std::getline(command_stream, argument_2_place_of_origin_of_victim, ',');
			if (argument_2_place_of_origin_of_victim.at(0) == ' ')
				argument_2_place_of_origin_of_victim = argument_2_place_of_origin_of_victim.erase(0, 1);
			std::getline(command_stream, argument_3_age_of_victim, ',');
			if (argument_3_age_of_victim.at(0) == ' ')
				argument_3_age_of_victim = argument_3_age_of_victim.erase(0, 1);
			std::getline(command_stream, argument_4_photograph_of_victim, ',');
			if (argument_4_photograph_of_victim.at(0) == ' ')
				argument_4_photograph_of_victim = argument_4_photograph_of_victim.erase(0, 1);

			int age;
			stringstream age_string(argument_3_age_of_victim);
			age_string >> age;

			if (mode == 1 && age != 0)
				this->service.add_victim_service(argument_1_name_of_victim_or_mode, argument_2_place_of_origin_of_victim, age, argument_4_photograph_of_victim);
			else if (age == 0)
				cout << "No!" << endl;
			else cout << "wrong mode" << endl;
		}
		else if (command_key == "save")
		{

			std::getline(command_stream, argument_1_name_of_victim_or_mode, ',');

			if (mode == 0)
				this->service.add_victim_to_assistant_service(argument_1_name_of_victim_or_mode);
			else cout << "wrong mode" << endl;
		}
		else if (command_key == "update")
		{
			std::getline(command_stream, argument_1_name_of_victim_or_mode, ',');
			std::getline(command_stream, argument_2_place_of_origin_of_victim, ',');
			if (argument_2_place_of_origin_of_victim.at(0) == ' ')
				argument_2_place_of_origin_of_victim = argument_2_place_of_origin_of_victim.erase(0, 1);
			std::getline(command_stream, argument_3_age_of_victim, ',');
			if (argument_3_age_of_victim.at(0) == ' ')
				argument_3_age_of_victim = argument_3_age_of_victim.erase(0, 1);
			std::getline(command_stream, argument_4_photograph_of_victim, ',');
			if (argument_4_photograph_of_victim.at(0) == ' ')
				argument_4_photograph_of_victim = argument_4_photograph_of_victim.erase(0, 1);

			int age;
			stringstream age_string(argument_3_age_of_victim);
			age_string >> age;


			if (mode == 1 && age != 0)
				this->service.update_victim_service(argument_1_name_of_victim_or_mode, argument_2_place_of_origin_of_victim, age, argument_4_photograph_of_victim);
			else if (age == 0)
				cout << "No!" << endl;
			else cout << "wrong mode" << endl;
		}
		else if (command_key == "list")
		{
			if (mode == 1)
				this->list_all_ui();
			if (mode == 0)
			{

					std::getline(command_stream, argument_2_place_of_origin_of_victim, ',');
					std::getline(command_stream, argument_3_age_of_victim, ',');
				try 
				{
					if (argument_3_age_of_victim.at(0) == ' ')
						argument_3_age_of_victim = argument_3_age_of_victim.erase(0, 1);
				}
				catch (std::exception& excepObj)
				{
					argument_3_age_of_victim = argument_2_place_of_origin_of_victim;
					int age;
					stringstream age_string(argument_3_age_of_victim);
					age_string >> age;

					this->list_filtered(age);
				}

				int age;
				stringstream age_string(argument_3_age_of_victim);
				age_string >> age;

				this->list_by_place_of_origin(argument_2_place_of_origin_of_victim, age);
			}
		}
		else if (command_key == "mylist")
		{
			if (mode == 0)
				this->list_all_form_assistant_ui();
			else cout << "wrong mode" << endl;
		}
		else if (command_key == "next")
		{
			if (mode == 0)
			{
				if (current_victim_in_assistant_archive == this->service.get_number_of_victims()-1)
					current_victim_in_assistant_archive = -1;
				//cout << this->service.get_all_victims();
				//cout << this->service.get_repository().get_victim(++current_victim_in_assistant_archive).victim_to_string() << endl;
			}
			else cout << "wrong mode" << endl;
		}
		else
		{
			cout << "wrong command" << endl;
		}
	}

}