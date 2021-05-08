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
	
	void set_name(std::string new_name) { this->name = new_name; }
	void set_place_of_origin(std::string new_place_of_origin) { this->place_of_origin = new_place_of_origin; }
	void set_age(int new_age)  { this->age = new_age; }
	void set_photograph(std::string new_photograph)  { this->photograph = new_photograph; }

	std::string victim_to_string();

	friend std::istream& operator>>(std::istream& input_stream, Victim& victim);
	friend std::ostream& operator<<(std::ostream& output_stream, const Victim& victim);

};

void test_victim();