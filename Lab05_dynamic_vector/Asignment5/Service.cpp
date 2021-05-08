#include "Service.h"
#include <assert.h>

Dynamic_vector Service::get_all_victims_in_repository() const
{
	return this->repository.get_victims();
}

void Service::add_victim_service(const std::string& name, const std::string& place_of_origin, int age, const std::string& photograph)
{
	Victim victim{ name, place_of_origin, age, photograph };

	this->repository.add_victim(victim);
}

void Service::remove_victim_service(const std::string& name)
{
	this->repository.remove_victim_repository(name);
}

void Service::update_victim_service(const std::string& name, const std::string& place_of_origin, int age, const std::string& photograph)
{
	Victim victim{ name, place_of_origin, age, photograph };

	this->repository.update_victim_repository(victim);
}

//----------------------------------TESTS----------------------------------

void add_victim_service__Valid_input__Victim_is_added()
{
	Repository repository{};
	Service service{ repository };

	service.add_victim_service("aa", "bb", 1, "cc");

	assert(service.get_repository().get_lenght_repository() == 1);
}

void remove_victim_service__Valid_input__Victim_is_removed()
{
	Repository repository{};
	Service service{ repository };

	service.add_victim_service("aa", "bb", 1, "cc");

	service.remove_victim_service("aa");

	assert(service.get_repository().get_lenght_repository() == 0);
}

void remove_victim_service__Not_valid_input__Victim_is_not_removed()
{
	Repository repository{};
	Service service{ repository };

	service.add_victim_service("aa", "bb", 1, "cc");

	service.remove_victim_service("bb");

	assert(service.get_repository().get_lenght_repository() == 1);
}

void update_victim_service__Valid_input__Victim_is_updated()
{
	Repository repository{};
	Service service{ repository };

	service.add_victim_service("aa", "bb", 1, "cc");

	service.update_victim_service("aa", "cc", 2, "dd");

	assert(service.get_repository().get_victim(0).get_photograph().compare("dd") == 0);
}

void update_victim_service__Not_valid_input__Victim_is_not_updated()
{
	Repository repository{};
	Service service{ repository };

	service.add_victim_service("aa", "bb", 1, "cc");

	service.update_victim_service("bb","cc",2,"dd");

	assert(service.get_repository().get_victim(0).get_photograph().compare("cc") == 0);
}

void test_service()
{
	add_victim_service__Valid_input__Victim_is_added();

	remove_victim_service__Valid_input__Victim_is_removed();
	remove_victim_service__Not_valid_input__Victim_is_not_removed();

	update_victim_service__Valid_input__Victim_is_updated();
	update_victim_service__Not_valid_input__Victim_is_not_updated();
}