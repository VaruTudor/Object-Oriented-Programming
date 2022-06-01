#include "Repository.h"

#include <assert.h>

void add__Valid_input__Stars_are_added()
{
	FileRepository<Star> new_test_repo{ "C:\\Users\\Tudor\\Desktop\\D\\faculta\\SemII\\OOP\\PracticalExam\\test_repo.txt" };

	Star star1{ "aa","bb",1,2,3 };
	Star star2{ "bb","cc",1,2,3 };
	Star star3{ "cc","dd",1,2,3 };
	new_test_repo.add(star1);
	new_test_repo.add(star2);
	new_test_repo.add(star3);

	assert(new_test_repo.get_all_items().size() == 3);

	new_test_repo.remove(star1);
	new_test_repo.remove(star2);
	new_test_repo.remove(star3);
}

void test_add_repository()
{
	add__Valid_input__Stars_are_added();
}
