#include "Repository.h"
#include <string>
#include <assert.h>

using namespace std;

void Repository::add_victim(const Victim& victim)
{
	this->victims.add_to_DynamicVector(victim);
}

void Repository::remove_victim_repository(const std::string& name)
{
	this->victims.remove_using_name(name);
}

void Repository::update_victim_repository(const Victim& victim)
{
	for (int i = 0; i < this->get_lenght_repository(); i++)
	{
		if (this->victims.get_element(i).get_name().compare(victim.get_name()) == 0)
		{
			this->victims.remove(i);
			this->victims.add_to_position(victim, i);
		}
	}
}

int Repository::get_lenght_repository()
{
	return this->victims.get_size();
}

Victim Repository::get_victim(int position)
{
	return this->victims.get_element(position);
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


void test_repository()
{
	add_victim_to_repository__Valid_input__Victim_is_added();

	remove_victim_from_repository__Valid_input__Victim_is_removed();
	remove_victim_from_repository__Not_valid_input__Victim_is_removed();

	update_victim_from_repository__Valid_input__Victim_is_updated();
	update_victim_from_repository__Not_valid_input__Victim_is_not_updated();
}