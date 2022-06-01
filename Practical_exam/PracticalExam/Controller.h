#pragma once

#include "Repository.h"

// NOTE: tests for controller are bellow the implementation

class Controller
{
private:
	FileRepository<Star>& repository;
public:
	Controller(FileRepository<Star>& new_repo);
	~Controller();
	std::vector<Star> get_all_form_repository() { return this->repository.get_all_items(); };

	/*
	adds a star to the repository of stars
	input:
		new_name - string - the name of the star
		new_constelation - string - the constalation of the star
		new_RA - int - the right ascension of the star
		new_Dec - int - the declination of the star
		new_diameter - int - the diameter of the star
	*/
	void add(std::string new_name, std::string new_constelation, int new_RA, int new_Dec, int new_diameter);
	void remove(std::string new_name, std::string new_constelation, int new_RA, int new_Dec, int new_diameter);

	void save_to_file_at_exit();
	
	std::vector<Star> get_all_with_name(std::string given_name) ;
};

void test_add_controller();