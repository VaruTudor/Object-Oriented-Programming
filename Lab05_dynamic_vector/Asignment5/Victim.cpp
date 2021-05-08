#include "Victim.h"
#include <string>

Victim::Victim() : name(""), place_of_origin(""), age(0), photograph(""){}

Victim::Victim(const std::string& name, const std::string& place_of_origin, int age, const std::string& photograph)
{
	this->name = name;
	this->place_of_origin = place_of_origin;
	this->age = age;
	this->photograph = photograph;
}

std::string Victim::victim_to_string()
{
	return this->get_name() + ", " + this->get_place_of_origin() + ", " + std::to_string(this->get_age()) + ", " + this->get_photograph();
}


