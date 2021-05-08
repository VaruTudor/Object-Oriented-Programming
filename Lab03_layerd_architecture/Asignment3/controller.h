#pragma once

#include "repository.h"
#include <string.h>
#include <stdio.h>

typedef struct {
	Repository repository ;
}Controller;

Controller create_controller(Repository repository);

/*
	creates a file and adds it to the repository
	input:
		controller - the controller object (type Controller)
		archive_catalogue_number - the identifier from the catalogue (type int)
		state_of_deterioration - the state of deterioration of the file (type char[])
		file_type - the type of the file (type char[])
		year_of_creation - the year in which the file has been created (type int)
*/
int add_file_controller(Controller* controller, int archive_catalogue_number, char state_of_deterioration[],
	char file_type[], int year_of_creation);

/*
	deletes a file from the repository by it's archive catalogue number
	input:
		controller - the controller object (type Controller)
		file_archive_catalogue_number - the identifier from the catalogue (type int)
*/
int delete_file_controller(Controller* controller, int file_archive_catalogue_number);

/*
	updates a file from the repository
	input:
		controller - the controller object (type Controller)
		archive_catalogue_number - the identifier from the catalogue (type int)
		state_of_deterioration - the state of deterioration of the file (type char[])
		file_type - the type of the file (type char[])
		year_of_creation - the year in which the file has been created (type int)
*/
void update_file_controller(Controller* controller, int archive_catalogue_number, char state_of_deterioration[],
	char file_type[], int year_of_creation);

/*
	gives acces to the data from the repository
*/
int get_file_from_data(Controller* controller, int index);

/*
	gives acces to the lenght of the repository
*/
int get_files_lenght(Controller* controller);

/*
	prints all files from the repository
	input:
		controller - the controller object (type Controller)
*/
//void list_all_files(Controller* controller);

/*
	prints all files from the repository having a specific file type
	input:
		controller - the controller object (type Controller)
		file_type - the type of the file (type char[])
*/
//void list_files_with_file_type(Controller* controller, char file_type[]);