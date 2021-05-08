#include "Repository.h"
#include "Exceptions.h"

#include <string>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// MemoryRepository

MemoryRepository::MemoryRepository()
{
	this->iterator_of_victims = this->victims.begin();
}

void MemoryRepository::add_victim(const Victim& victim)
{
	this->victims.push_back(victim);
}

void MemoryRepository::remove_victim_repository(const std::string& name)
{
	int index = 0;
	for (Victim victim : victims)
	{
		if (victim.get_name() == name)
		{
			this->victims.erase(this->victims.begin() + index);
			break;
		}
		index++;
	}
}

void MemoryRepository::update_victim_repository(const Victim& victim)
{
	int index = 0;
	for (Victim current_victim : victims)
	{
		if (current_victim.get_name() == victim.get_name())
		{
			this->victims.erase(this->victims.begin() + index);
			this->victims.insert(this->victims.begin() + index, victim);
			break;
		}
		index++;
	}
}

int MemoryRepository::find_index_of_victim_by_name(const std::string& name)
{
	int index = 0;
	for (Victim current_victim : victims)
	{
		if (current_victim.get_name() == name)
		{
			return index;
		}
		index++;
	}
}

int MemoryRepository::get_lenght_repository()
{
	return this->victims.size();
}

Victim MemoryRepository::get_victim(int position)
{
	return this->victims.at(position);
}

std::vector<Victim> MemoryRepository::get_victims() const
{
	return this->victims;
}

std::string MemoryRepository::get_path()
{
	return "";
}


std::vector<Victim> Repository::get_victims() const
{
	return std::vector<Victim>();
}



// FileRepository

FileRepository::FileRepository(const std::string& file_name)
{
	this->file_name = file_name;
	VictimValidator new_victim_validator;
	this->victim_validator = new_victim_validator;
}

void FileRepository::add_victim(const Victim& victim)
{
	try
	{
		this->victim_validator.validate(victim);
	}
	catch (ValidationException& error_message)
	{
		cout << error_message.what() << endl;
		return;
	}

	std::ofstream file;
	file.open(this->file_name.c_str(), std::ios_base::app);

	try
	{
		this->find_victim_by_name(victim.get_name());
	}
	catch (AlreadyInTheRepository& error_message)
	{
		cout << error_message.what();
		return;
	}
	catch (NotInTheRepository& exception)
	{
		(void)exception;
		file << victim;
	}
	
	file.close();
}

void FileRepository::remove_victim_repository(const std::string& name)
{
	try
	{
		this->find_victim_by_name(name);
	}
	catch (AlreadyInTheRepository& exception)
	{
		std::vector<Victim> victims = this->get_victims();
		victims.erase(victims.begin() + exception.what_index());
		this->write_victims_to_file(victims);
	}
	catch (NotInTheRepository& exception)
	{
		cout << exception.what() << endl;
	}
}

void FileRepository::update_victim_repository(const Victim& victim)
{
	try
	{
		this->find_victim_by_name(victim.get_name());;
	}
	catch (AlreadyInTheRepository& exception)
	{
		std::vector<Victim> victims = this->get_victims();
		victims.erase(victims.begin() + exception.what_index());
		victims.insert(victims.begin() + exception.what_index(), victim);
		this->write_victims_to_file(victims);
	}
	catch (NotInTheRepository& exception)
	{
		cout << exception.what() << endl;
	}
	/*int index = this->find_victim_by_name(victim.get_name());
	if (index != -1)
	{
		std::vector<Victim> victims = this->get_victims();
		victims.erase(victims.begin() + index);
		victims.insert(victims.begin() + index, victim);
		this->write_victims_to_file(victims);
	}*/
}

int FileRepository::find_victim_by_name(const std::string& name)
{
	int index = 0;
	std::ifstream file(this->file_name.c_str());
	Victim read_victim;
	while (file >> read_victim)
	{
		if (read_victim.get_name() == name)
		{
			file.close();
			throw(AlreadyInTheRepository(index));
		}
		index++;
	}
	file.close();
	throw(NotInTheRepository());
	return -1;
}

int FileRepository::find_index_of_victim_by_name(const std::string& name)
{
	int index = 0;
	std::ifstream file(this->file_name.c_str());
	Victim read_victim;
	while (file >> read_victim)
	{
		if (read_victim.get_name() == name)
		{
			file.close();
			return index;
		}
		index++;
	}
	file.close();
	return 0;
}

std::vector<Victim> FileRepository::get_victims() const
{
	std::vector<Victim> victims;
	std::ifstream file(this->file_name.c_str());
	Victim read_victim;
	while (file >> read_victim)
	{
		victims.push_back(read_victim);
	}
	file.close();
	return victims;
}

void FileRepository::write_victims_to_file(std::vector<Victim> victims)
{
	std::ofstream file(this->file_name.c_str());
	for (Victim victim : victims)
		file << victim;
	file.close();
}

std::string FileRepository::get_path()
{
	return "";
}

// CSVRepository

CSVRepository::CSVRepository(const std::string& file_name)
{
	this->file_name = file_name;
}

void CSVRepository::add_victim(const Victim& victim) 
{
	std::ofstream file;
	file.open(this->file_name.c_str(), std::ios_base::app);
	std::string age = std::to_string(victim.get_age());
	file << victim.get_name() << "," << victim.get_place_of_origin() << "," << age << "," << victim.get_photograph() << endl;

	file.close();
}

int CSVRepository::find_victim_by_name(const std::string& name)
{
	int index = 0;
	std::ifstream file(this->file_name.c_str());
	while (file.good())
	{
		std::string name_of_victim;
		std::getline(file, name_of_victim, ',');
		if (name_of_victim == name)
		{
			return index;
		}
		std::getline(file, name_of_victim, ',');
		std::getline(file, name_of_victim, ',');
		std::getline(file, name_of_victim, '\n');
		index++;
	}
	file.close();
	
	return -1;
}

std::vector<Victim> CSVRepository::get_victims() const
{
	std::vector<Victim> victims_of_assistant;
	std::ifstream file(this->file_name.c_str());

	while (file.good())
	{
		Victim read_victim;
		std::string name_of_victim;
		std::getline(file, name_of_victim, ',');
		read_victim.set_name(name_of_victim);

		std::string place_of_origin_of_victim;
		std::getline(file, place_of_origin_of_victim, ',');
		read_victim.set_place_of_origin(place_of_origin_of_victim);

		std::string age_of_victim;
		std::getline(file, age_of_victim, ',');

		int age;
		stringstream age_string(age_of_victim);
		age_string >> age;
		read_victim.set_age(age);

		std::string photograph_of_victim;
		std::getline(file, photograph_of_victim, '\n');
		read_victim.set_photograph(photograph_of_victim);

		if (name_of_victim != "")
			victims_of_assistant.push_back(read_victim);
	}

	file.close();
	return victims_of_assistant;
}

void CSVRepository::remove_victim_repository(const std::string& name)
{
	int index = this->find_victim_by_name(name);
	if (index != -1)
	{
		std::vector<Victim> victims = this->get_victims();
		victims.erase(victims.begin() + index);
		this->write_victims_to_file(victims);
	}
}

void CSVRepository::update_victim_repository(const Victim& victim)
{
	int index = this->find_victim_by_name(victim.get_name());
	if (index != -1)
	{
		std::vector<Victim> victims = this->get_victims();
		victims.erase(victims.begin() + index);
		victims.insert(victims.begin() + index, victim);
		this->write_victims_to_file(victims);
	}
}

int CSVRepository::find_index_of_victim_by_name(const std::string& name)
{
	return 0;
}

void CSVRepository::write_victims_to_file(std::vector<Victim> victims)
{
	std::ofstream file(this->file_name.c_str());
	for (Victim victim : victims)
	{
		std::string age = std::to_string(victim.get_age());
		file << victim.get_name() << "," << victim.get_place_of_origin() << "," << age << "," << victim.get_photograph() << endl;
	}

	file.close();
}

std::string CSVRepository::get_path()
{
	return this->file_name;
}

// HTMLRepository

HTMLRepository::HTMLRepository(const std::string& file_name)
{
	this->file_name = file_name;
	std::ofstream file;
	file.open(this->file_name.c_str());

	file << "<!DOCTYPE html>" << endl;
	file << "<html>" << endl;
	file << "	<head>" << endl;
	file << "		<title>Victims</title>" << endl;
	file << "	<head>" << endl;
	file << "	<body>" << endl;
	file << "		<table border='1'>" << endl;
	file << "		<tr>" << endl;
	file << "			<td>Name</td>" << endl;
	file << "			<td>Place of origin</td>" << endl;
	file << "			<td>Age</td>" << endl;
	file << "			<td>Photograph</td>" << endl;
	file << "		</tr>" << endl;
	file << "		</table>" << endl;
	file << "	</body>" << endl;
	file << "</html>" << endl;

	file.close();
}

void HTMLRepository::add_victim(const Victim& victim)
{
	std::string line;
	std::vector<string> lines;
	std::ifstream file_for_reading(this->file_name.c_str());

	while (std::getline(file_for_reading, line))
	{
		lines.push_back(line);
	}
	file_for_reading.close();

	std::ofstream file_for_writing(this->file_name.c_str(), ios::out | ios::trunc);
	if (file_for_writing.is_open())
	{
		for (int i = 0; i < lines.size() - 4; i++)
		{
			file_for_writing << lines[i] << "\n";
		}

		std::string age = std::to_string(victim.get_age());
		file_for_writing << "		<tr>" << endl;
		file_for_writing << "			<td>" << victim.get_name() << "</td>" << endl;
		file_for_writing << "			<td>" << victim.get_place_of_origin() << "</td>" << endl;
		file_for_writing << "			<td>" << age << "</td>" << endl;
		file_for_writing << "			<td>" << victim.get_photograph() << "</td>" << endl;
		file_for_writing << "		</tr>" << endl;

		file_for_writing << "		</table>" << endl;
		file_for_writing << "	</body>" << endl;
		file_for_writing << "</html>" << endl;

		file_for_writing.close();
	}
	/*std::ifstream file_for_reading(this->file_name.c_str());

	std::ofstream file_for_writing;
	file_for_writing.open("temp.html");
	
	std::string line;
	while (std::getline(file_for_reading,line))
	{
		if (line != "		</table>" && line != "	</body>" && line != "</html>")
			file_for_writing << line << endl;
	}

	file_for_reading.close();

	std::string age = std::to_string(victim.get_age());
	file_for_writing << "		<tr>" << endl;
	file_for_writing << "			<td>" << victim.get_name() << "</td>"<<endl;
	file_for_writing << "			<td>" << victim.get_place_of_origin() << "</td>"<<endl;
	file_for_writing << "			<td>" << age << "</td>"<<endl;
	file_for_writing << "			<td>" << victim.get_photograph() << "</td>"<<endl;
	file_for_writing << "		</tr>" << endl;

	file_for_writing << "		</table>" << endl;
	file_for_writing << "	</body>" << endl;
	file_for_writing << "</html>" << endl;

	file_for_writing.close();

	remove(this->file_name.c_str());
	rename("temp.html", this->file_name.c_str());*/
}

void HTMLRepository::remove_victim_repository(const std::string& name)
{
}

void HTMLRepository::update_victim_repository(const Victim& victim)
{
}

int HTMLRepository::find_index_of_victim_by_name(const std::string& name)
{
	return 0;
}

std::vector<Victim> HTMLRepository::get_victims() const
{
	std::vector<Victim> victims;

	std::ifstream file_for_reading(this->file_name.c_str());

	std::string line;
	int field_number = 0;
	Victim read_victim;
	while (std::getline(file_for_reading, line))
	{
		if (line.compare(0, 7, "			<td>") == 0)
		{
			line.erase(0, 7);
			line.erase(line.length()-5,line.length());
			if (line != "Name" && line != "Place of origin" && line != "Age" && line != "Photograph")
			{
				if (field_number == 0)
				{
					read_victim.set_name(line);
				}
				if (field_number == 1)
				{
					read_victim.set_place_of_origin(line);
				}
				if (field_number == 2)
				{
					int age;
					stringstream age_string(line);
					age_string >> age;
					read_victim.set_age(age);
				}
				if (field_number == 3)
				{
					read_victim.set_photograph(line);
				}
				field_number++;
				if (field_number == 4)
				{
					field_number = 0;
					victims.push_back(read_victim);
				}
			}
		}
	}

	return victims;
}

std::string HTMLRepository::get_path()
{
	return this->file_name;
}

//------------------TESTS------------------

void add_victim__Valid_input__Victim_is_added()
{
	FileRepository repository{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment8\\Asignment8\\tests.txt" };
	Victim victim{ "aa","bb",1,"cc" };

	repository.add_victim(victim);

	try
	{
		repository.find_victim_by_name(victim.get_name());
	}
	catch (AlreadyInTheRepository& error_message)
	{
		assert(error_message.what_index() == 0);
		return;
	}
	catch (NotInTheRepository& exception)
	{
		(void)exception;
	}

	repository.remove_victim_repository("aa");
}

void remove_victim_repository__Valid_input__Victim_is_added()
{
	FileRepository repository{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment8\\Asignment8\\tests.txt" };
	Victim victim{ "aa","bb",1,"cc" };

	repository.add_victim(victim);

	repository.remove_victim_repository("aa");

	try
	{
		repository.find_victim_by_name(victim.get_name());
	}
	catch (AlreadyInTheRepository& error_message)
	{
		(void)error_message;
		return;
	}
	catch (NotInTheRepository& exception)
	{
		assert(exception.what_index() == -1);
	}
}

void update_victim_repository__Valid_input__Victim_is_added()
{
	FileRepository repository{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment8\\Asignment8\\tests.txt" };
	Victim victim{ "aa","bb",1,"cc" };
	Victim victim2{ "aa","cc",2,"dd" };

	repository.add_victim(victim);

	repository.update_victim_repository(victim2);

	assert(repository.get_victims().at(0).victim_to_string() == victim2.victim_to_string());

	repository.remove_victim_repository("aa");
}

void test_file_repository()
{
	add_victim__Valid_input__Victim_is_added();
	remove_victim_repository__Valid_input__Victim_is_added();
	update_victim_repository__Valid_input__Victim_is_added();
}

void add_victim_csv__Valid_input__Victim_is_added()
{
	CSVRepository repository{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment8\\Asignment8\\tests.csv" };
	Victim victim{ "aa","bb",1,"cc" };

	repository.add_victim(victim);

	assert(repository.find_victim_by_name("aa") == 0);

	repository.remove_victim_repository("aa");
}

void remove_victim_csv_repository__Valid_input__Victim_is_added()
{
	CSVRepository repository{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment8\\Asignment8\\tests.csv" };
	Victim victim{ "aa","bb",1,"cc" };

	repository.add_victim(victim);

	repository.remove_victim_repository("aa");

	assert(repository.find_victim_by_name("aa") == -1);
}

void update_victim_csv_repository__Valid_input__Victim_is_added()
{
	CSVRepository repository{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment8\\Asignment8\\tests.csv" };
	Victim victim{ "aa","bb",1,"cc" };
	Victim victim2{ "aa","cc",2,"dd" };


	repository.add_victim(victim);

	repository.update_victim_repository(victim2);

	assert(repository.get_victims().at(0).victim_to_string() == victim2.victim_to_string());

	repository.remove_victim_repository("aa");
}

void test_csv_repository()
{
	add_victim_csv__Valid_input__Victim_is_added();
	remove_victim_csv_repository__Valid_input__Victim_is_added();
	update_victim_csv_repository__Valid_input__Victim_is_added();
}

