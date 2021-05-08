#include "repository.h"
#include <stdio.h>
#include <string.h>

Repository create_repository()
{
	Repository repository ;
	repository.lenght_of_repository= 0;
	return repository;
}

int is_file_in_repository(Repository* repository, File file)
{
	int index;
	for (int index = 0; index < repository->lenght_of_repository; index++)
		if (get_archive_catalogue_number(&repository->Files[index]) == file.archive_catalogue_number) return 1;
	return 0;
}

int add_file_in_repository(Repository* repository, File file)
{
	if (is_file_in_repository(repository, file) == 1)
	{
		printf("No!\n");
		return -1;
	}

	repository->Files[repository->lenght_of_repository] = file;
	repository->lenght_of_repository += 1;

	return 1;
}

void update_file_from_repository(Repository* repository, File file)
{
	
	if (is_file_in_repository(repository, file) == 0)
	{
		return -1;
	}
	
	repository->Files[file.archive_catalogue_number] = file;

	int index = 0;
	while (index < repository->lenght_of_repository)
	{
		if (get_archive_catalogue_number(&repository->Files[index]) == file.archive_catalogue_number)
		{
			repository->Files[index] = file;
		}
		index += 1;
	}
}

int delete_file_from_repository(Repository* repository, File file)
{
	if (is_file_in_repository(repository, file) == 0)
	{
		printf("No!\n");
		return -1;
	}

	int index = 0, file_found_in_repository = 0;
	while (index < repository->lenght_of_repository)
	{
		if (get_archive_catalogue_number(&repository->Files[index]) == file.archive_catalogue_number)
		{
			file_found_in_repository = 1;
		}
		if (file_found_in_repository == 1)
		{
			repository->Files[index] = repository->Files[index + 1];
		}
		index += 1;
	}
	repository->lenght_of_repository -= 1;
		
	return 1;
}

int get_repository_file(Repository* repository, int index)
{
	return &repository->Files[index];	
}

int get_repository_lenght(Repository* repository)
{
	return repository->lenght_of_repository;
}