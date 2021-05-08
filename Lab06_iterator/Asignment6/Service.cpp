#include "Service.h"
#include <assert.h>

DynamicVector<Victim> Service::get_all_victims() const
{
	return this->repository.get_victims();
}

DynamicVector<Victim> Service::get_all_victims_assistant() const
{
	return this->assistant_repository.get_victims();
}

void Service::add_victim_service(const std::string& name, const std::string& place_of_origin, int age, const std::string& photograph)
{
	Victim victim{ name, place_of_origin, age, photograph };

	this->repository.add_victim(victim);
}

void Service::add_victim_to_assistant_service(const std::string& name)
{
	for (int i = 0; i < this->repository.get_lenght_repository(); i++)
	{
		if (this->repository.get_victim(i).get_name().compare(name) == 0)
		{
			Victim victim = this->repository.get_victim(i);
			this->assistant_repository.add_victim(victim);
		}
	}
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

int Service::get_number_of_victims()
{
	return this->get_repository().get_lenght_repository();
}

//----------------------------------TESTS----------------------------------

void add_victim_service__Valid_input__Victim_is_added()
{
	Repository repository{};
	Repository assistant_repository{};
	Service service{ repository,assistant_repository };

	service.add_victim_service("aa", "bb", 1, "cc");

	assert(service.get_repository().get_lenght_repository() == 1);
}

void remove_victim_service__Valid_input__Victim_is_removed()
{
	Repository repository{};
	Repository assistant_repository{};
	Service service{ repository,assistant_repository };

	service.add_victim_service("aa", "bb", 1, "cc");

	service.remove_victim_service("aa");

	assert(service.get_repository().get_lenght_repository() == 0);
}

void remove_victim_service__Not_valid_input__Victim_is_not_removed()
{
	Repository repository{};
	Repository assistant_repository{};
	Service service{ repository,assistant_repository };

	service.add_victim_service("aa", "bb", 1, "cc");

	service.remove_victim_service("bb");

	assert(service.get_repository().get_lenght_repository() == 1);
}

void update_victim_service__Valid_input__Victim_is_updated()
{
	Repository repository{};
	Repository assistant_repository{};
	Service service{ repository,assistant_repository };

	service.add_victim_service("aa", "bb", 1, "cc");

	service.update_victim_service("aa", "cc", 2, "dd");

	assert(service.get_repository().get_victim(0).get_photograph().compare("dd") == 0);
}

void update_victim_service__Not_valid_input__Victim_is_not_updated()
{
	Repository repository{};
	Repository assistant_repository{};
	Service service{ repository,assistant_repository };

	service.add_victim_service("aa", "bb", 1, "cc");

	service.update_victim_service("bb", "cc", 2, "dd");

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