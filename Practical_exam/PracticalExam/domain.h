#pragma once

#include <sstream>
#include <string>

class Astronomer
{
private:
	std::string name, constelation;
public:
	Astronomer(std::string new_name, std::string new_constelation) { this->name = new_name; this->constelation = new_constelation; };
	Astronomer() { this->name = ""; this->constelation = ""; };

	std::string get_name() { return this->name; };
	std::string get_constelation() { return this->constelation; };

	friend std::ofstream& operator<<(std::ofstream& os, Astronomer& astronomer);
	friend std::istream& operator>>(std::istream& is, Astronomer& astronomer);
	friend bool operator== (Astronomer& lhs_astr, Astronomer& rhs_astr);
};


class Star
{
private:
	std::string name, constelation_belonging;
	int RA, Dec, diameter;
public:

	std::string get_constelation() { return this->constelation_belonging; };
	std::string get_name() { return this->name; };
	int get_diameter() { return this->diameter; };

	Star(std::string new_name, std::string new_constelation, int new_RA, int new_Dec, int new_diameter)
	{
		this->name = new_name;
		this->constelation_belonging = new_constelation;
		this->RA = new_RA;
		this->Dec = new_Dec;
		this->diameter = new_diameter;
	}
	Star()
	{
		this->name = "";
		this->constelation_belonging = "";
		this->RA = 0;
		this->Dec = 0;
		this->diameter = 0;
	}

	std::string to_string();

	friend std::ofstream& operator<<(std::ofstream& os, Star& star);
	friend std::istream& operator>>(std::istream& is, Star& star);
	friend bool operator== (Star& lhs_star, Star& rhs_star);
	friend bool operator> (Star& lhs_star, Star& rhs_star);
};

