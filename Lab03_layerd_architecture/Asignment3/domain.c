#include "domain.h"
#include <string.h>

File create_file(int archive_catalogue_number, char state_of_deterioration[], char file_type[], int year_of_creation)
{
	File file;
	file.archive_catalogue_number = archive_catalogue_number;
	strcpy(file.file_type, file_type);
	strcpy(file.state_of_deterioration, state_of_deterioration);
	file.year_of_creation = year_of_creation;

	return file;
}

int get_archive_catalogue_number(File* file) {
	return file->archive_catalogue_number;
}
char* get_file_type(File* file) {
	return file->file_type;
}
char* get_state_of_deterioration(File* file) {
	return file->state_of_deterioration;
}
int get_year_of_creation(File* file) {
	return file->year_of_creation;
}
