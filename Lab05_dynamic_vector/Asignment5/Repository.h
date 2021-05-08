#pragma once
#include "Dynamic_vector.h"

class Repository
{
private:
	Dynamic_vector victims;

public:
	//default constructor
	Repository(){};

	/*
		adds a victim to the repository
	*/
	void add_victim(const Victim& victim);

	/*
		removes a victim from the repository
	*/
	void remove_victim_repository(const std::string& name);

	/*
		updates a victio from the repository
	*/
	void update_victim_repository(const Victim& victim);
	
	/*
		gets the lenght of the repository
	*/
	int get_lenght_repository();

	/*
		gets a victim using it's position
		return:
			the victim on specified position
	*/
	Victim get_victim(int position);

	/*
		gets all victims from the repository
	*/
	Dynamic_vector get_victims() const { return victims; }
};

void test_repository();
