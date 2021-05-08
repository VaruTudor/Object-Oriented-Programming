#pragma once
#include <iostream>

class Victim
{
private:
	std::string name;
	std::string place_of_origin;
	int age;
	std::string photograph;

public:
	// default constructor 
	Victim();

	// parametered constructur
	Victim(const std::string& name, const std::string& place_of_origin, int age, const std::string& photograph);

	std::string get_name() const { return name; }
	std::string get_place_of_origin() const { return place_of_origin; }
	int get_age() const { return age; }
	std::string get_photograph() const { return photograph; }

	// transforms the victim into a string
	std::string victim_to_string();
};

