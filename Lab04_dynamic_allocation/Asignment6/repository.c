#include "repository.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

Repository* create_repository()
{
	Repository* repository = (Repository*)malloc(sizeof(Repository));

	if (repository == NULL)
		return NULL;

	repository->Files = create_dynamic_container(CAPACITY);

	return repository;
}


void destroy_repository(Repository* repository)
{
	if (repository == NULL)
		return NULL;

	destroy_dynamic_container(repository->Files);
	free(repository);
}


int index_of_file_in_repository(Repository* repository, File* file)
{

	for (int index = 0; index < repository->Files->length; index++) {
		if (get_archive_catalogue_number(repository->Files->elements[index]) == get_archive_catalogue_number(file)) {
			return index;
		}
	}
	return -1;
}

int add_file_in_repository(Repository* repository, File* file)
{
	if (repository == NULL || file == NULL)
		return 0;

	//if (index_of_file_in_repository(repository, file) != -1)
		//return -4;

	add_element_to_dynamic_container(repository->Files, file);

	return 1;
}

int update_file_from_repository(Repository* repository, File* file)
{
	if (repository == NULL || file == NULL)
		return 0;

	if (index_of_file_in_repository(repository, file) == -1)
		return -4;

	for (int index = 0; index < repository->Files->length; index++) {
		if (get_archive_catalogue_number(repository->Files->elements[index]) == file->archive_catalogue_number) {
			repository->Files->elements[index] = file;
		}
	}

	return 1;
}

int delete_file_from_repository(Repository* repository, int index)
{
	if (repository == NULL)
		return NULL;

	for (int index = 0; index < repository->Files->length; index++)
		if (get_archive_catalogue_number(repository->Files->elements[index]) == index)
			return -4;

	delete_element_from_dynamic_container(repository->Files, index);

	return 1;
}

File* get_repository_file_at_position(Repository* repository, int positon)
{
	return get_element_at_position(repository->Files, positon);
}

File* get_repository_file_using_archive_catalogue_number(Repository* repository, int index)
{
	return get_element_using_identifier(repository->Files, index);
}

int get_repository_lenght(Repository* repository)
{
	if (repository == NULL)
		return 0;

	return get_lenght_of_dynamic_container(repository->Files);
}

Repository* copy_repository(Repository* repository)
{
	Repository* new_repository = create_repository();
	new_repository->Files->length = repository->Files->length;
	for (int i = 0; i < repository->Files->length; i++)
	{
		File* file = create_file(0,"","",0);
		file = copy_file(repository->Files->elements[i]);
		if (new_repository->Files->length == new_repository->Files->capacity)
			resize(new_repository->Files);
		new_repository->Files->elements[i] = file;
	}
	return new_repository;
}

//-------------------------------------------------------------------------------------------------
//Tests

/*
void test_add_file_in_repository()
{
	Repository* repository = create_repository();

	assert(get_repository_lenght(repository) == 0);

	File* file1 = create_file(1, "a", "b", 2);

	add_file_in_repository(repository, file1);
	// expected: file is added
	assert(get_repository_lenght(repository) == 1);

	File* file1_copy = get_repository_file_at_position(repository, 0);
	assert(file1_copy->archive_catalogue_number == 1);
	assert(strcmp(file1_copy->file_type, "b") == 0);
	assert(strcmp(file1_copy->state_of_deterioration, "a") == 0);
	assert(file1_copy->year_of_creation == 2);

	destroy_repository(repository);
}


void test_delete_file_from_repository()
{
	Repository* repository = create_repository();

	assert(get_repository_lenght(repository) == 0);

	File* file1 = create_file(1, "a", "b", 2);

	add_file_in_repository(repository, file1);
	// expected: file is added
	assert(get_repository_lenght(repository) == 1);

	delete_file_from_repository(repository, 1);
	// expected: file is deleted
	assert(get_repository_lenght(repository) == 0);

	destroy_file(file1);
	destroy_repository(repository);
}

void test_update_file_from_repository()
{
	Repository* repository = create_repository();

	assert(get_repository_lenght(repository) == 0);

	File* file1 = create_file(1, "a", "b", 2);

	add_file_in_repository(repository, file1);
	// expected: file is added
	assert(get_repository_lenght(repository) == 1);

	File* updated_file1 = create_file(1, "b", "c", 3);
	update_file_from_repository(repository, updated_file1);

	File* file1_copy = get_repository_file_at_position(repository, 0);
	// expected: file is updated
	assert(file1_copy->archive_catalogue_number == 1);
	assert(strcmp(file1_copy->file_type, "c") == 0);
	assert(strcmp(file1_copy->state_of_deterioration, "b") == 0);
	assert(file1_copy->year_of_creation == 3);

	destroy_file(file1);
	destroy_repository(repository);
}

void tests_repository()
{
	test_add_file_in_repository();
	test_delete_file_from_repository();
	test_update_file_from_repository();
}
*/