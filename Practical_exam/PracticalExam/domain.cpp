#include "domain.h"

#include <vector>
#include <fstream>

std::ofstream& operator<<(std::ofstream& os, Astronomer& astronomer)
{
	os << astronomer.name << "," << astronomer.constelation << ","  << "\n";

	return os;
}

std::istream& operator>>(std::istream& is, Astronomer& astronomer)
{
	std::string list_of_fields;
	std::getline(is, list_of_fields);

	std::vector<std::string> vector_of_attributes;
	std::string current_field;
	std::stringstream stream_to_be_split(list_of_fields);
	while (std::getline(stream_to_be_split, current_field, ','))
	{
		vector_of_attributes.push_back(current_field);
	}

	if (vector_of_attributes.size() != 2)
		return is;

	astronomer.name = vector_of_attributes[0];
	astronomer.constelation = vector_of_attributes[1];

	return is;
}

bool operator==(Astronomer& lhs_astr, Astronomer& rhs_astr)
{
	if (lhs_astr.name == rhs_astr.name)
		return true;
	return false;
}

std::ofstream& operator<<(std::ofstream& os, Star& star)
{
	os << star.name << "," << star.constelation_belonging<< "," << std::to_string(star.RA) << "," << std::to_string(star.Dec) << "," << std::to_string(star.diameter) <<"\n";
	return os;
}

std::istream& operator>>(std::istream& is, Star& star)
{
	std::string list_of_fields;
	std::getline(is, list_of_fields);

	std::vector<std::string> vector_of_attributes;
	std::string current_field;
	std::stringstream stream_to_be_split(list_of_fields);
	while (std::getline(stream_to_be_split, current_field, ','))
	{
		vector_of_attributes.push_back(current_field);
	}

	if (vector_of_attributes.size() != 5)
		return is;

	star.name = vector_of_attributes[0];
	star.constelation_belonging = vector_of_attributes[1];

	int RA;
	std::stringstream RA_stream(vector_of_attributes[2]);
	RA_stream >> RA;
	int Dec;
	std::stringstream Dec_stream(vector_of_attributes[3]);
	Dec_stream >> Dec;
	int diameter;
	std::stringstream diameter_stream(vector_of_attributes[4]);
	diameter_stream >> diameter;

	star.RA = RA;
	star.Dec = Dec;
	star.diameter = diameter;
	return is;
}

bool operator==(Star& lhs_star, Star& rhs_star)
{
	if (lhs_star.name == rhs_star.name)
		return true;
	return false;
}

bool operator>(Star& lhs_star, Star& rhs_star)
{
	if (lhs_star.get_constelation() > rhs_star.get_constelation())
		return true;
	return false;
}

std::string Star::to_string()
{
	return this->name+ " " + std::to_string(this->RA) + " " + std::to_string(this->Dec) + " " + std::to_string(this->diameter) ;
}
