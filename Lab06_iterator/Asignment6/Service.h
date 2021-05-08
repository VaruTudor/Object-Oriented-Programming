#pragma once
#include "Repository.h"
#include "Victim.h"

class Service
{
private:
	Repository& repository;
	Repository& assistant_repository;

public:
	Service(Repository& repository, Repository& assistant_repository) : repository{ repository }, assistant_repository {assistant_repository}{}

	Repository& get_repository() const { return repository; }

	DynamicVector<Victim> get_all_victims() const;
	DynamicVector<Victim> get_all_victims_assistant() const;

	// adds a victim
	void add_victim_service(const std::string& name, const std::string& place_of_origin, int age, const std::string& photograph);

	// adds a victim to the assistant list
	void add_victim_to_assistant_service(const std::string& name);

	// remove a victim
	void remove_victim_service(const std::string& name);

	// update a victim 
	void update_victim_service(const std::string& name, const std::string& place_of_origin, int age, const std::string& photograph);

	int get_number_of_victims();

};

void test_service();
