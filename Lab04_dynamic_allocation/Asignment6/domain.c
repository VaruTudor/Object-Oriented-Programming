#include "domain.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

File* create_file(int archive_catalogue_number, char* state_of_deterioration, char* file_type, int year_of_creation)
{
	// we allocate memory for the file
	File* file = (File*)malloc(sizeof(File));
	if (file == NULL)
		return NULL;

	file->file_type = (char*)malloc(sizeof(char) * (strlen(file_type) + 1));
	strcpy(file->file_type, file_type);
	file->state_of_deterioration = (char*)malloc(sizeof(char) * (strlen(state_of_deterioration) + 1));
	strcpy(file->state_of_deterioration, state_of_deterioration);

	file->archive_catalogue_number = archive_catalogue_number;
	file->year_of_creation = year_of_creation;

	return file;
}

void destroy_file(File* file)
{
	if (file == NULL)
		return;

	//free the memory allocated for components of file 
	free(file->file_type);
	free(file->state_of_deterioration);

	//free the memory alocated to the structure file
	free(file);
}

File* copy_file(File* file)
{
	if (file == NULL)
		return NULL;

	File* new_file = create_file(get_archive_catalogue_number(file), get_file_type(file), get_state_of_deterioration(file), get_year_of_creation(file));
	return new_file;
}

int get_archive_catalogue_number(File* file) {
	if (file == NULL)
		return 0;

	return file->archive_catalogue_number;
}

char* get_file_type(File* file) {
	if (file == NULL)
		return NULL;

	return file->file_type;
}

char* get_state_of_deterioration(File* file) {
	if (file == NULL)
		return NULL;

	return file->state_of_deterioration;
}

int get_year_of_creation(File* file) {
	if (file == NULL)
		return 0;

	return file->year_of_creation;
}