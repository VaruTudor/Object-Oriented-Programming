#pragma once
#include <string>
#include <exception>
#include "Victim.h"

class ValidationException: public std::exception
{
private:
	std::string message;
public:
	ValidationException(std::string message);
	const char* what() const noexcept override;
};

class AlreadyInTheRepository : public std::exception
{
	std::string message;
	int index_of_victim;
public:
	AlreadyInTheRepository(int index);
	const char* what() const noexcept override;
	int what_index() {return this->index_of_victim;}
};

class NotInTheRepository : public std::exception
{
	std::string message;
	int index_of_victim;
public:
	NotInTheRepository();
	const char* what() const noexcept override;
	int what_index() { return this->index_of_victim; }
};

class VictimValidator
{
public:
	static void validate(const Victim& victim);
};