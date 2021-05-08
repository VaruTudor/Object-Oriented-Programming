#include "test_repositorry.h"
#include "repository.h"
#include "domain.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void test_repository_create()
{
	Repository repository = create_repository();
	assert(repository.lenght_of_repository == 0);
}

void test_repository_add()
{
	Repository repository = create_repository();
	assert(repository.lenght_of_repository == 0);

	File file = create_file(41, "aa", "bb", 51);
	assert(add_file_in_repository(&repository, file) == 1);
	assert(add_file_in_repository(&repository, file) == -1);

	assert(repository.lenght_of_repository == 1);
}


void test_repository_delete()
{
	Repository repository = create_repository();
	assert(repository.lenght_of_repository == 0);

	File file = create_file(41, "aa", "bb", 51);
	File file_2 = create_file(42, "bb", "cc", 54);
	File file_3 = create_file(43, "cc", "dd", 55);
	add_file_in_repository(&repository, file);
	add_file_in_repository(&repository, file_2);
	add_file_in_repository(&repository, file_3);
	assert(repository.lenght_of_repository == 3);
	assert(delete_file_from_repository(&repository, file_2) == 1);
	assert(delete_file_from_repository(&repository, file_2) == -1);

	assert(repository.lenght_of_repository == 2);
}

void test_repository_update()
{
	Repository repository = create_repository();
	assert(repository.lenght_of_repository == 0);

	File file = create_file(41, "aa", "bb", 51);
	File file_2 = create_file(41, "bb", "cc", 54);
	assert(add_file_in_repository(&repository, file) == 1);

	update_file_from_repository(&repository, file_2);
	assert(repository.Files[file_2.archive_catalogue_number].year_of_creation == 54);
	assert(strcmp(repository.Files[file_2.archive_catalogue_number].state_of_deterioration, "bb") == 0);
	assert(strcmp(repository.Files[file_2.archive_catalogue_number].file_type, "cc") == 0);
}

void test_repository_complete()
{
	test_repository_create();
	test_repository_add();
	test_repository_delete();
	test_repository_update();
}
