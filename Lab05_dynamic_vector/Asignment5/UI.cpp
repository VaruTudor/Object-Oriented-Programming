#include "UI.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>


using namespace std;

void UI::list_all_ui()
{
	Dynamic_vector victims = this->service.get_all_victims_in_repository();
	for (int i = 0; i < victims.get_size(); i++)
	{
		Victim victim = victims.get_element(i);
		cout << victim.victim_to_string() << endl;
	}
}

void UI::run()
{
	int mode = -1;
	while (true)
	{	
		std::string command, command_key, argument_1_name_of_victim, argument_2_place_of_origin_of_victim, argument_3_age_of_victim, argument_4_photograph_of_victim;
		getline(cin, command);
		std::stringstream command_stream(command);
		std::getline(command_stream, command_key, ' ');

		if (command_key == "exit")
		{
			break;
		}
		else if (command_key == "mode")
		{
			std::getline(command_stream, argument_1_name_of_victim, ',');
			if (argument_1_name_of_victim == "A")
				mode = 1;
			if (argument_1_name_of_victim == "B")
				mode = 0;
		}
		else if (command_key == "delete")
		{
			std::getline(command_stream, argument_1_name_of_victim, ',');

			if (mode == 1)
				this->service.remove_victim_service(argument_1_name_of_victim);
			else cout << "wrong mode" << endl;
		}
		else if (command_key == "add")
		{
			
			std::getline(command_stream, argument_1_name_of_victim, ',');
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
				this->service.add_victim_service(argument_1_name_of_victim, argument_2_place_of_origin_of_victim, age, argument_4_photograph_of_victim);
			else if (age == 0)
				cout << "No!" << endl;
			else cout << "wrong mode" << endl;
		}
		else if (command_key == "update")
		{
			std::getline(command_stream, argument_1_name_of_victim, ',');
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


			if (mode == 1 && age!= 0)
				this->service.update_victim_service(argument_1_name_of_victim, argument_2_place_of_origin_of_victim, age, argument_4_photograph_of_victim);
			else if (age == 0)
				cout << "No!" << endl;
			else cout << "wrong mode" << endl;
		}
		else if (command_key == "list")
			this->list_all_ui();
		else
		{
			cout << "wrong command" << endl;
		}
	}	
	
}