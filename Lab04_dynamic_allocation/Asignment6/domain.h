#pragma once

typedef struct {
	int archive_catalogue_number;
	char* state_of_deterioration;
	char* file_type;
	int year_of_creation;
} File;

File* create_file(int archive_catalogue_number, char* state_of_deterioration,
	char* file_type, int year_of_creation);

void destroy_file(File* file);

File* copy_file(File*);

int get_archive_catalogue_number(File* file);
char* get_state_of_deterioration(File* file);
char* get_file_type(File* file);
int get_year_of_creation(File* file);