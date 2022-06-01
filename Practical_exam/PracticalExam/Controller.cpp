#include "Controller.h"

#include <assert.h>

// NOTE: tests for repository are bellow the implementation

Controller::Controller(FileRepository<Star>& new_repo): repository{new_repo}
{
}

Controller::~Controller()
{
	this->save_to_file_at_exit();
}

void Controller::add(std::string new_name, std::string new_constelation, int new_RA, int new_Dec, int new_diameter)
{
	Star new_star{ new_name,  new_constelation,  new_RA, new_Dec, new_diameter };
	if (new_name == "")
		return;
	if (new_diameter <= 0)
		return;
	for (auto star : this->get_all_form_repository())
	{
		if (star.get_name() == new_name)
			return;
	}
	this->repository.add(new_star);
}

void Controller::remove(std::string new_name, std::string new_constelation, int new_RA, int new_Dec, int new_diameter)
{
	this->repository.remove(Star{ new_name, new_constelation, new_RA, new_Dec, new_diameter });
}

void Controller::save_to_file_at_exit()
{
	this->repository.write_to_file_sorted();
}

std::vector<Star> Controller::get_all_with_name(std::string given_name)
{
	std::vector<Star> all_stars = this->get_all_form_repository();
	std::vector<Star> all_stars_with_name{};
	for (auto star : this->get_all_form_repository())
	{
		if (star.get_name().find(given_name) != std::string::npos)
		//if (star.get_name() == given_name)
			all_stars_with_name.push_back(star);
	}

	return all_stars_with_name;
}

// Tests

void add__Valid_input__Star_is_added()
{
	FileRepository<Star> new_test_repo{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\PracticalExam\\test_repo.txt" };
	Controller new_test_controller{ new_test_repo };

	new_test_controller.add("aa", "bb", 1, 2, 3);
	new_test_controller.add("bb", "cc", 1, 2, 3);
	new_test_controller.add("cc", "dd", 1, 2, 3);

	assert(new_test_controller.get_all_form_repository().size() == 3);

	new_test_controller.remove("aa", "bb", 1, 2, 3);
	new_test_controller.remove("bb", "cc", 1, 2, 3);
	new_test_controller.remove("cc", "dd", 1, 2, 3);
}

void add__Invalid_name_input__Star_is_not_added()
{
	FileRepository<Star> new_test_repo{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\PracticalExam\\test_repo.txt" };
	Controller new_test_controller{ new_test_repo };

	new_test_controller.add("aa", "bb", 1, 2, 3);
	new_test_controller.add("aa", "cc", 1, 2, 3);

	assert(new_test_controller.get_all_form_repository().size() == 1);

	new_test_controller.remove("aa", "bb", 1, 2, 3);
}

void add__No_name_input__Star_is_not_added()
{
	FileRepository<Star> new_test_repo{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\PracticalExam\\test_repo.txt" };
	Controller new_test_controller{ new_test_repo };

	new_test_controller.add("aa", "bb", 1, 2, 3);
	new_test_controller.add("", "cc", 1, 2, 3);

	assert(new_test_controller.get_all_form_repository().size() == 1);

	new_test_controller.remove("aa", "bb", 1, 2, 3);
}

void add__Invalid_diameter_input__Star_is_not_added()
{
	FileRepository<Star> new_test_repo{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\PracticalExam\\test_repo.txt" };
	Controller new_test_controller{ new_test_repo };

	new_test_controller.add("aa", "bb", 1, 2, 3);
	new_test_controller.add("aa", "cc", 1, 2, -5);

	assert(new_test_controller.get_all_form_repository().size() == 1);

	new_test_controller.remove("aa", "bb", 1, 2, 3);
}

void test_add_controller()
{
	add__Valid_input__Star_is_added();
	add__Invalid_name_input__Star_is_not_added();
	add__No_name_input__Star_is_not_added();
	add__Invalid_diameter_input__Star_is_not_added();
}

