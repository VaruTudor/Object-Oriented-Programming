#pragma once
#include "Repository.h"
#include "Victim.h"

class Service
{
private:
	FileRepository& repository;
	Repository& assistant_repository;

public:
	Service(FileRepository& repository, Repository& assistant_repository) : repository{ repository }, assistant_repository{ assistant_repository }{}

	FileRepository& get_repository() const { return repository; }

	std::vector<Victim> get_all_victims() const;
	std::vector<Victim> get_all_victims_assistant() const;

	// adds a victim
	void add_victim_service(const std::string& name, const std::string& place_of_origin, int age, const std::string& photograph);

	// adds a victim to the assistant list
	void add_victim_to_assistant_service(const std::string& name);

	// remove a victim
	void remove_victim_service(const std::string& name);

	// update a victim 
	void update_victim_service(const std::string& name, const std::string& place_of_origin, int age, const std::string& photograph);

	int get_number_of_victims();

	void set_file_path(std::string file_path);

};

void test_service();
