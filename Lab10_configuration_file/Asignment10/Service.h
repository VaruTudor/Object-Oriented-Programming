#pragma once
#include "Repository.h"
#include "Victim.h"

class Service
{
private:
	Repository* repository;
	Repository* assistant_repository;
	int mode = 1;

public:
	Service(Repository* repository, Repository* assistant_repository) : repository{ repository }, assistant_repository{ assistant_repository }{}

	Repository* get_repository() const { return repository; }

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

	int find_victim_index_using_name(const std::string& name);

	int get_number_of_victims();

	void set_file_path(std::string file_path);
	
	void set_mylist_csv_file_path(std::string file_path);
	
	void set_mylist_html_file_path(std::string file_path);

	std::string get_assistant_path();

	void set_mode(int what_mode);

	int get_mode();


	std::vector<Victim> filer(std::string place_of_origin, int age);
};

//void test_service();
