#include "Victim.h"
#include <vector>
#include <sstream>
#include <assert.h>

Victim::Victim() : name(""), place_of_origin(""), age(0), photograph("") {}

Victim::Victim(const std::string& name, const std::string& place_of_origin, int age, const std::string& photograph)
{
	this->name = name;
	this->place_of_origin = place_of_origin;
	this->age = age;
	this->photograph = photograph;
}

std::string Victim::victim_to_string()
{
	return this->name + ", " + this->place_of_origin + ", " + std::to_string(this->age) + ", " + this->photograph;
}

std::vector<std::string> split_list_of_attributes(std::string unsplitted_fields_of_victim, char delimiter)
{
	std::vector<std::string> fields_of_victim;
	std::string argument_of_command;
	std::stringstream stream_to_be_split(unsplitted_fields_of_victim);
	while (std::getline(stream_to_be_split, argument_of_command, delimiter))
	{
		int index_in_argument = 0;

		while (index_in_argument < fields_of_victim.size() && argument_of_command.at(index_in_argument) == ' ')
			index_in_argument++;
		argument_of_command.erase(0, index_in_argument);

		fields_of_victim.push_back(argument_of_command);
	}
	return fields_of_victim;
}

std::istream& operator>>(std::istream& input_stream, Victim& victim)
{
	std::string fields_of_victim;
	std::getline(input_stream, fields_of_victim);

	std::vector<std::string> vector_of_attributes = split_list_of_attributes(fields_of_victim, ',');
	if (vector_of_attributes.size() != 4)
		return input_stream;
	victim.name = vector_of_attributes[0];
	victim.place_of_origin = vector_of_attributes[1];

	// we transform the age to an intiger
	int age;
	std::stringstream age_string(vector_of_attributes[2]);
	age_string >> age;
	victim.age = age;

	victim.photograph = vector_of_attributes[3];

	return input_stream;
}

std::ostream& operator<<(std::ostream& output_stream, const Victim& victim)
{
	std::string age = std::to_string(victim.age);
	output_stream << victim.name << ", " << victim.place_of_origin << ", " << age << ", " << victim.photograph << "\n";
	return output_stream;
}

void get_name__Valid_input__name_is_returned()
{
	Victim victim_1{ "aa","bb",1,"cc" };
	assert(victim_1.get_name() == "aa");
}

void get_place_of_origin__Valid_input__name_is_returned()
{
	Victim victim_1{ "aa","bb",1,"cc" };
	assert(victim_1.get_place_of_origin() == "bb");
}

void get_age__Valid_input__name_is_returned()
{
	Victim victim_1{ "aa","bb",1,"cc" };
	assert(victim_1.get_age() == 1);
}

void get_photograph__Valid_input__name_is_returned()
{
	Victim victim_1{ "aa","bb",1,"cc" };
	assert(victim_1.get_photograph() == "cc");
}

void victim_to_string__Valid_input__Correct_string_is_returned()
{
	Victim victim_1{ "aa","bb",1,"cc" };
	assert(victim_1.victim_to_string() == "aa, bb, 1, cc");
}

void split_list_of_attributes__Valid_input__Vector_with_splitted_arguments_is_returned()
{
	std::string string_containing_input{ "aa, bb , 1, cc" };
	std::vector<std::string> vector_containing_fields;
	vector_containing_fields = split_list_of_attributes(string_containing_input, ',');
	assert(vector_containing_fields[3] == "cc");
}

void operator_extraction__Valid_input__String_is_extracted()
{
	Victim victim_1{ "aa","bb",1,"cc" };
	std::ostringstream output;
	output << victim_1;
	assert(output.str() == "aa, bb, 1, cc\n");
}

void operator_insertion__Victim_as_input__String_is_inserted()
{
	Victim victim_1{};
	std::istringstream output{"aa, bb, 1, dd"};
	output >> victim_1;
	assert(victim_1.victim_to_string() == "aa, bb, 1, dd");
}

void test_victim()
{
	get_name__Valid_input__name_is_returned();
	get_place_of_origin__Valid_input__name_is_returned();
	get_age__Valid_input__name_is_returned();
	get_photograph__Valid_input__name_is_returned();

	victim_to_string__Valid_input__Correct_string_is_returned();

	split_list_of_attributes__Valid_input__Vector_with_splitted_arguments_is_returned();
	operator_extraction__Valid_input__String_is_extracted();
	operator_insertion__Victim_as_input__String_is_inserted();
}
