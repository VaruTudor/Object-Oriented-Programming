#pragma once
#include "Repository.h"
#include "Victim.h"

class Service
{
private:
	Repository& repository;

public:
	Service(Repository& repository) : repository{ repository } {}

	Repository& get_repository() const { return repository; }

	Dynamic_vector get_all_victims_in_repository() const;

	// adds a victim
	void add_victim_service(const std::string& name, const std::string& place_of_origin, int age, const std::string& photograph);

	// remove a victim
	void remove_victim_service(const std::string& name);

	// update a victim 
	void update_victim_service(const std::string& name, const std::string& place_of_origin, int age, const std::string& photograph);

};

void test_service();
