#include "test_file.h"
#include "domain.h"
#include <assert.h>
#include <string.h>

void test_file_creator()
{
	File file = create_file(41, "aa", "bb", 51);
	assert(file.archive_catalogue_number == 41);
	assert(strcmp(file.state_of_deterioration, "aa") == 0);
	assert(strcmp(file.file_type, "bb") == 0);
	assert(file.year_of_creation, 51);
}

void test_file_getters()
{
	File file = create_file(41, "aa", "bb", 51);
	assert(get_archive_catalogue_number(&file) == 41);
	assert(strcmp(get_file_type(&file), "bb") == 0);
	assert(strcmp(get_state_of_deterioration(&file), "aa") == 0);
	assert(get_year_of_creation(&file), 51);
}

void test_file_complete()
{
	test_file_creator();
	test_file_getters();
}


