#pragma once
#include "Victim.h"
#include <vector>

class Repository
{
private:
	std::vector<Victim> victims;
	std::vector<Victim>::iterator iterator_of_victims;

public:
	//default constructor
	Repository();

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
	std::vector<Victim> get_victims() const;
};

class FileRepository
{
private:
	//std::vector<Victim> victims;
	std::string file_name;

public:
	//default constructor
	FileRepository(const std::string& file_name="");

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

	int find_victim_by_name(const std::string& name);

	/*
		gets a victim using it's position
		return:
			the victim on specified position
	*/
	//Victim get_victim(int position);

	/*
		gets all victims from the repository
	*/
	std::vector<Victim> get_victims() const;

	void write_victims_to_file(std::vector<Victim> victims);
};

void test_repository();

void test_file_repository();