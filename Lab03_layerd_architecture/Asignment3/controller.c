#include "controller.h"

Controller create_controller(Repository repository)
{
	Controller controller;
	controller.repository = repository;
	return controller;
}

int add_file_controller(Controller* controller, int archive_catalogue_number, char state_of_deterioration[], char file_type[], int year_of_creation)
{
	File file = create_file(archive_catalogue_number, state_of_deterioration, file_type, year_of_creation);
	add_file_in_repository(&controller->repository, file);
	return 0;
}

int delete_file_controller(Controller* controller, int file_archive_catalogue_number)
{
	File file = create_file(file_archive_catalogue_number, "aa", "bb", 1);
	delete_file_from_repository(&controller->repository, file);
	return 0;
}

void update_file_controller(Controller* controller, int archive_catalogue_number, char state_of_deterioration[], char file_type[], int year_of_creation)
{
	File file = create_file(archive_catalogue_number, state_of_deterioration, file_type, year_of_creation);
	update_file_from_repository(&controller->repository, file);
}

int get_file_from_data(Controller* controller, int index)
{
	return get_repository_file(&controller->repository, index);
}

int get_files_lenght(Controller* controller)
{
	return get_repository_lenght(&controller->repository);
}

/*
void list_all_files(Controller* controller)
{
	return repository_data(&controller->repository);
	
	int index;
	for (index = 0; index < controller->repository.lenght_of_repository; index++)
	{

		printf("%d, %s, %s, %d\n", get_archive_catalogue_number(&controller->repository.Files[index]), get_state_of_deterioration(&controller->repository.Files[index]),
			get_file_type(&controller->repository.Files[index]), get_year_of_creation(&controller->repository.Files[index]));
	}
	
}

void list_files_with_file_type(Controller* controller, char file_type[])
{
	int index;
	for (index = 0; index < controller->repository.lenght_of_repository; index++)
	{
		if (strcmp(get_file_type(&controller->repository.Files[index]), file_type) == 0)
			printf("%d, %s, %s, %d\n", get_archive_catalogue_number(&controller->repository.Files[index]), get_state_of_deterioration(&controller->repository.Files[index]),
			get_file_type(&controller->repository.Files[index]), get_year_of_creation(&controller->repository.Files[index]));
	}
}
*/
