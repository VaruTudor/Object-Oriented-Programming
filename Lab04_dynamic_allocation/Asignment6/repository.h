#pragma once

#include "domain.h"
#include "dynamic_container.h"


typedef struct {
	Dynamic_contaier* Files;
} Repository;

Repository* create_repository();

/*
	deallocates the memory
	input:
		repository - the repository where the items are stored (type Repository)
*/
void destroy_repository(Repository* repository);


int index_of_file_in_repository(Repository* repository, File* file);

/*
	adds a file to the repository
	return:
		1 - the file has been added to the repository
		-1 - the file already exits in the repository
	input:
		repository - the repository where the items are stored (type Repository)
		file - the structure to be added in the repository (type File)
*/
int add_file_in_repository(Repository* repository, File* file);

/*
	updates a file from the repository
	input:
		repository - the repository where the items are stored (type Repository)
		file - the structure to be updated in the repository (type File)
*/
int update_file_from_repository(Repository* repository, File* file);

Repository* copy_repository(Repository* repository);

/*
	deletes a file from the repository
	return:
		1 - the file has been deleted from the repository
		-1 - the file has not been found in the repository
	input:
		repository - the repository where the items are stored (type Repository)
		file - the structure to be deleted from the repository (type File)
*/
int delete_file_from_repository(Repository* repository, int index);


/*
	returns the files from the repository for further use
	return:
		 the files found in repository(type File[])
	input:
		repository - the repository where the items are stored (type Repository)
*/
File* get_repository_file_using_archive_catalogue_number(Repository* repository, int index);

File* get_repository_file_at_position(Repository* repository, int positon);

/*
	returns the lenght of the repository for further use
	return:
		the files found in repository(type File[])
		0 - if the repository pointer is NULL
	input:
		repository - the repository where the items are stored (type Repository)
*/
int get_repository_lenght(Repository* repository);

//int reverse_delete_repository(Repository* repository, File* file, int index);


int update_file_from_repository(Repository* repository, File* file);

void tests_repository();