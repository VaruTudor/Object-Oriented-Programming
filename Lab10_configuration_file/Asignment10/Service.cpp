#include "Service.h"
#include <assert.h>

std::vector<Victim> Service::get_all_victims() const
{
	return this->repository->get_victims();
}

std::vector<Victim> Service::get_all_victims_assistant() const
{
	return this->assistant_repository->get_victims();
}

void Service::add_victim_service(const std::string& name, const std::string& place_of_origin, int age, const std::string& photograph)
{
	if (mode == 1)
	{
		Victim victim{ name, place_of_origin, age, photograph };

		this->repository->add_victim(victim);
	}
	
}

void Service::add_victim_to_assistant_service(const std::string& name)
{
	if (mode == 0)
	{
		std::vector<Victim> victims = this->get_all_victims();
		for (Victim victim : victims)
		{
			if (victim.get_name().compare(name) == 0)
			{
				this->assistant_repository->add_victim(victim);
			}
		}
	}
}

void Service::remove_victim_service(const std::string& name)
{
	if (mode == 1)
	{
		this->repository->remove_victim_repository(name);
	}
	
}

void Service::update_victim_service(const std::string& name, const std::string& place_of_origin, int age, const std::string& photograph)
{
	if (mode == 1)
	{
		Victim victim{ name, place_of_origin, age, photograph };

		this->repository->update_victim_repository(victim);
	}
	
}

int Service::find_victim_index_using_name(const std::string& name)
{
	return this->repository->find_index_of_victim_by_name(name);
}


int Service::get_number_of_victims()
{
	return this->get_all_victims().size();
}

void Service::set_file_path(std::string file_path)
{
	Repository* new_repository = new FileRepository{ file_path };
	this->repository = new_repository;
}

void Service::set_mylist_csv_file_path(std::string file_path)
{
	Repository* new_repository = new CSVRepository{ file_path };
	this->assistant_repository = new_repository;
}


void Service::set_mylist_html_file_path(std::string file_path)
{
	Repository* new_repository = new HTMLRepository{ file_path };
	this->assistant_repository = new_repository;
}

std::string Service::get_assistant_path()
{
	return this->assistant_repository->get_path();
}

void Service::set_mode(int what_mode)
{
	this->mode = what_mode;
}

int Service::get_mode()
{
	return this->mode;
}

std::vector<Victim> Service::filer(std::string place_of_origin, int age)
{
	std::vector<Victim> victims = this->get_all_victims();
	std::vector<Victim> filtered_victims;
	for (Victim victim : victims)
	{
		if (victim.get_place_of_origin() == place_of_origin && victim.get_age() < age)
			filtered_victims.push_back(victim);
	}

	return filtered_victims;
}


//----------------------------------TESTS----------------------------------


//void add_victim_service__Valid_input__Victim_is_added()
//{
//	FileRepository repository{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment8\\Asignment8\\tests.txt" };
//	Repository* assistant_repository = new CSVRepository { "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment8\\Asignment8\\tests.csv" };
//	Service service{ repository,assistant_repository };
//
//	service.add_victim_service("aa", "bb", 1, "cc");
//
//	assert(service.get_all_victims().size() == 1);
//
//	service.remove_victim_service("aa");
//}
//
//
//void remove_victim_service__Valid_input__Victim_is_removed()
//{
//	FileRepository repository{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment8\\Asignment8\\tests.txt" };
//	Repository* assistant_repository = new CSVRepository{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment8\\Asignment8\\tests.csv" };
//	Service service{ repository,assistant_repository };
//
//	service.add_victim_service("aa", "bb", 1, "cc");
//
//	service.remove_victim_service("aa");
//
//	assert(service.get_all_victims().size() == 0);
//}
//
////void remove_victim_service__Not_valid_input__Victim_is_not_removed()
////{
////	FileRepository repository{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment8\\Asignment8\\tests.txt" };
////	Repository* assistant_repository = new CSVRepository{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment8\\Asignment8\\tests.csv" };
////	Service service{ repository,assistant_repository };
////
////	service.add_victim_service("aa", "bb", 1, "cc");
////
////	service.remove_victim_service("bb");
////
////	assert(service.get_all_victims().size() == 1);
////
////	service.remove_victim_service("aa");
////}
//
//void update_victim_service__Valid_input__Victim_is_updated()
//{
//	FileRepository repository{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment8\\Asignment8\\tests.txt" };
//	Repository* assistant_repository = new CSVRepository{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment8\\Asignment8\\tests.csv" };
//	Service service{ repository,assistant_repository };
//
//	service.add_victim_service("aa", "bb", 1, "cc");
//
//	service.update_victim_service("aa", "cc", 2, "dd");
//	Victim victim{ "aa", "cc", 2, "dd" };
//
//	assert(service.get_all_victims().at(0).victim_to_string() == victim.victim_to_string());
//
//	service.remove_victim_service("aa");
//}
//
////void update_victim_service__Not_valid_input__Victim_is_not_updated()
////{
////	FileRepository repository{ };
////	Repository* assistant_repository = new CSVRepository{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment8\\Asignment8\\tests.csv" };
////	Service service{ repository,assistant_repository };
////
////	service.set_file_path("C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\Laboratories\\Asignment8\\Asignment8\\tests.txt");
////
////	service.add_victim_service("aa", "bb", 1, "cc");
////	Victim victim{ "aa", "bb", 1, "cc" };
////
////	service.update_victim_service("bb", "cc", 2, "dd");
////
////	assert(service.get_all_victims().at(0).victim_to_string() == victim.victim_to_string());
////
////	service.remove_victim_service("aa");
////}
//
//void test_service()
//{
//	add_victim_service__Valid_input__Victim_is_added();
//
//	remove_victim_service__Valid_input__Victim_is_removed();
//	//remove_victim_service__Not_valid_input__Victim_is_not_removed();
//
//	update_victim_service__Valid_input__Victim_is_updated();
//	//update_victim_service__Not_valid_input__Victim_is_not_updated();
//
//}
