#pragma once
#include "Victim.h"
#include "Exceptions.h"
#include <vector>

class Repository
{
private:
	/*std::vector<Victim> victims;
	std::vector<Victim>::iterator iterator_of_victims;*/

public:
	////default constructor
	Repository() {};

	/*
		adds a victim to the repository
	*/
	virtual void add_victim(const Victim& victim) = 0;

	///*
	//	removes a victim from the repository
	//*/
	//void remove_victim_repository(const std::string& name);

	///*
	//	updates a victio from the repository
	//*/
	//void update_victim_repository(const Victim& victim);

	///*
	//	gets the lenght of the repository
	//*/
	//int get_lenght_repository();

	///*
	//	gets a victim using it's position
	//	return:
	//		the victim on specified position
	//*/
	//Victim get_victim(int position);

	/*
		gets all victims from the repository
	*/
	virtual std::vector<Victim> get_victims() const = 0;

	virtual std::string get_path() = 0;
};

class FileRepository
{
private:
	std::string file_name;
	VictimValidator victim_validator;

public:
	//default constructor
	FileRepository(const std::string& file_name = "");

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

	int find_index_of_victim_by_name(const std::string& name);

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

class CSVRepository : public Repository
{
private:
	std::string file_name;

public:
	CSVRepository(const std::string& file_name = "");

	/*
		adds a victim to the repository
	*/
	void add_victim(const Victim& victim) override;

	int find_victim_by_name(const std::string& name);

	/*
		gets all victims from the repository
	*/
	std::vector<Victim> get_victims() const override;

	/*
		removes a victim from the repository
	*/
	void remove_victim_repository(const std::string& name);
	
	/*
		updates a victio from the repository
	*/
	void update_victim_repository(const Victim& victim);

	void write_victims_to_file(std::vector<Victim> victims);

	std::string get_path() override;
};

class HTMLRepository : public Repository
{
private:
	std::string file_name;

public:
	HTMLRepository(const std::string& file_name = "");

	/*
		adds a victim to the repository
	*/
	void add_victim(const Victim& victim) override;

	/*
		gets all victims from the repository
	*/
	std::vector<Victim> get_victims() const override;

	std::string get_path() override;
};

void test_file_repository();

void test_csv_repository();