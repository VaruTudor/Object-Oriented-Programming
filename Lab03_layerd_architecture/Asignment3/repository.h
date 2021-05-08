#pragma once

#include "domain.h"
#include <string.h>
#include <stdio.h>


typedef struct {
	int lenght_of_repository;
    File Files[30];
}Repository;

Repository create_repository();

/*
	checks if a file is already in repository
	return:
		1 - the file already exists
		0 - the file was not found in repository
	input:
		repository - the repository where the items are stored (type Repository)
		file - the structure to be searched in the repository (type File)
*/
int is_file_in_repository(Repository* repository, File file);

/*
	adds a file to the repository
	return:
		1 - the file has been added to the repository
		-1 - the file already exits in the repository
	input:
		repository - the repository where the items are stored (type Repository)
		file - the structure to be added in the repository (type File)
*/
int add_file_in_repository(Repository* repository, File file);

/*
	updates a file from the repository
	input:
		repository - the repository where the items are stored (type Repository)
		file - the structure to be updated in the repository (type File)
*/
void update_file_from_repository(Repository* repository, File file);

/*
	deletes a file from the repository
	return:
		1 - the file has been deleted from the repository
		-1 - the file has not been found in the repository
	input:
		repository - the repository where the items are stored (type Repository)
		file - the structure to be deleted from the repository (type File)
*/
int delete_file_from_repository(Repository* repository, File file);


/*
	returns the files from the repository for further use
	return:
		 the files found in repository(type File[])
	input:
		repository - the repository where the items are stored (type Repository)
*/
int get_repository_file(Repository* repository, int index);

/*
	returns the lenght of the repository for further use
	return:
		 the files found in repository(type File[])
	input:
		repository - the repository where the items are stored (type Repository)
*/
int get_repository_lenght(Repository* repository);