#pragma once
#include <string>
#include <iostream>

class Victim
{
private:
	std::string name, place_of_origin, photograph;
	int age;

public:
	// default constructor
	Victim();
	// parametered constructor
	Victim(const std::string& name, const std::string& place_of_origin, int age, const std::string& photograph);

	// getters
	std::string get_name() const { return this->name; }
	std::string get_place_of_origin() const { return this->place_of_origin; }
	int get_age() const { return age; }
	std::string get_photograph() const { return this->photograph; }

	std::string victim_to_string();

	friend std::istream& operator>>(std::istream& input_stream, Victim& victim);
	friend std::ostream& operator<<(std::ostream& output_stream, const Victim& victim);

};

void test_victim();