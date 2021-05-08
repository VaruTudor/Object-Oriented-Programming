#include "Repository.h"
#include <string>
#include <assert.h>
#include <fstream>

using namespace std;

Repository::Repository()
{
	this->iterator_of_victims = this->victims.begin();
}

void Repository::add_victim(const Victim& victim)
{
	this->victims.push_back(victim);
}

void Repository::remove_victim_repository(const std::string& name)
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

void Repository::update_victim_repository(const Victim& victim)
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

int Repository::get_lenght_repository()
{
	return this->victims.size();
}

Victim Repository::get_victim(int position)
{
	return this->victims.at(position);
}

std::vector<Victim> Repository::get_victims() const
{
	return this->victims;
}


// FileRepository

FileRepository::FileRepository(const std::string& file_name)
{
	this->file_name = file_name;
}

void FileRepository::add_victim(const Victim& victim)
{
	std::ofstream file;
	file.open(this->file_name.c_str(), std::ios_base::app);
	file << victim;
	file.close();
}

void FileRepository::remove_victim_repository(const std::string& name)
{
	int index = this->find_victim_by_name(name);
	if (index != -1)
	{
		std::vector<Victim> victims = this->get_victims();
		victims.erase(victims.begin() + index);
		this->write_victims_to_file(victims);
	}
}

void FileRepository::update_victim_repository(const Victim& victim)
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
			return index;
		}
		index++;
	}
	file.close();
	return -1;
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


//------------------TESTS------------------

void add_victim_to_repository__Valid_input__Victim_is_added()
{
	Repository repository{};
	Victim victim{ "aa","bb",13,"cc" };

	repository.add_victim(victim);

	assert(repository.get_lenght_repository() == 1);
}


void remove_victim_from_repository__Valid_input__Victim_is_removed()
{
	Repository repository{};
	Victim victim{ "aa","bb",13,"cc" };

	repository.add_victim(victim);

	repository.remove_victim_repository(victim.get_name());

	assert(repository.get_lenght_repository() == 0);
}


void remove_victim_from_repository__Not_valid_input__Victim_is_removed()
{
	Repository repository{};
	Victim victim{ "aa","bb",13,"cc" };

	repository.add_victim(victim);

	repository.remove_victim_repository("vv");

	assert(repository.get_lenght_repository() == 1);
}

void update_victim_from_repository__Valid_input__Victim_is_updated()
{
	Repository repository{};
	Victim victim{ "aa","bb",13,"cc" };
	Victim victim2{ "aa","bcb",133,"cgc" };

	repository.add_victim(victim);

	repository.update_victim_repository(victim2);

	assert(repository.get_victim(0).get_age() == 133);
}

void update_victim_from_repository__Not_valid_input__Victim_is_not_updated()
{
	Repository repository{};
	Victim victim{ "aa","bb",13,"cc" };
	Victim victim2{ "ab","bcb",133,"cgc" };

	repository.add_victim(victim);

	repository.update_victim_repository(victim2);

	assert(repository.get_victim(0).get_age() == 13);
}

void get_victims__Valid_input__Victims_are_returned()
{
	Repository repository{};
	Victim victim{ "aa","bb",13,"cc" };

	repository.add_victim(victim);

	std::vector<Victim> vector;
	vector.push_back(victim);

	std::vector<Victim> vector_of_repository = repository.get_victims();
	assert(vector_of_repository.at(0).victim_to_string() == vector.at(0).victim_to_string());
}

void test_repository()
{
	add_victim_to_repository__Valid_input__Victim_is_added();

	remove_victim_from_repository__Valid_input__Victim_is_removed();
	remove_victim_from_repository__Not_valid_input__Victim_is_removed();

	update_victim_from_repository__Valid_input__Victim_is_updated();
	update_victim_from_repository__Not_valid_input__Victim_is_not_updated();

	get_victims__Valid_input__Victims_are_returned();
}

void add_victim__Valid_input__Victim_is_added()
{
	FileRepository repository{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment7c\\Asignment7c\\tests.txt" };
	Victim victim{ "aa","bb",1,"cc" };

	repository.add_victim(victim);

	assert(repository.find_victim_by_name("aa") == 0);
	
	repository.remove_victim_repository("aa");
}

void remove_victim_repository__Valid_input__Victim_is_added()
{
	FileRepository repository{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment7c\\Asignment7c\\tests.txt" };
	Victim victim{ "aa","bb",1,"cc" };

	repository.add_victim(victim);

	repository.remove_victim_repository("aa");

	assert(repository.find_victim_by_name("aa") == -1);
}

void update_victim_repository__Valid_input__Victim_is_added()
{
	FileRepository repository{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment7c\\Asignment7c\\tests.txt" };
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

