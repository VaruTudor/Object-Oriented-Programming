#include "Exceptions.h"

ValidationException::ValidationException(std::string message) : message { message }
{
}

const char* ValidationException::what() const noexcept
{
	return this->message.c_str();
}

void VictimValidator::validate(const Victim& victim)
{
	std::string errors_in_current_victim;
	if (victim.get_name().size() <= 1)
		errors_in_current_victim += std::string("The victim name is too short\n");
	if (victim.get_photograph().size() <= 1)
		errors_in_current_victim += std::string("The victim photograph is too short\n");
	if (victim.get_place_of_origin().size() <= 1)
		errors_in_current_victim += std::string("The victim place of origin is too short\n");
	if (victim.get_age() < 1)
		errors_in_current_victim += std::string("The victim age cannot be lower than 1\n");

	if (errors_in_current_victim.size() > 0)
		//in case of errors we throw
		throw ValidationException(errors_in_current_victim);
}

AlreadyInTheRepository::AlreadyInTheRepository(int index)
{
	this->message = "The victim already exists in the Repository\n"; 
	this->index_of_victim = index;
}

const char* AlreadyInTheRepository::what() const noexcept
{
	return this->message.c_str();
}

NotInTheRepository::NotInTheRepository()
{
	this->message = "The victim was not found in the repository\n";
	this->index_of_victim = -1;
}

const char* NotInTheRepository::what() const noexcept
{
	return this->message.c_str();
}
