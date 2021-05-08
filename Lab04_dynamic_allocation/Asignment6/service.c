#include "service.h"
#include <stdlib.h>
#include <string.h>

Service* create_service(Repository* repository, Repository_of_dynamic_containers* undo_stack)
{
	Service* service = (Service*)malloc(sizeof(Service));

	if (service == NULL)
		return NULL;

	service->repository = repository;
	service->undo_stack = undo_stack;

	return service;
}

void destroy_service(Service* service)
{
	// first destroy the repository inside
	//destroy_repository(service->repository);

	// then the operation stack
	destroy_stack(service->undo_stack);

	// then free the memory
	free(service);
}

int add_file_service(Service* service, int archive_catalogue_number, char* state_of_deterioration, char* file_type, int year_of_creation)
{
	File* file = create_file(archive_catalogue_number, state_of_deterioration, file_type, year_of_creation);

	int result = add_file_in_repository(service->repository, file);

	if (result == 1) // if the file was successfully added - register the operation
	{
		push(service->undo_stack, service->repository->Files);
	}

	return result;
}

int delete_file_service(Service* service, int archive_catalogue_number)
{
	//File* file = get_repository_file_with_archive_catalogue_number(s->repository, archive_catalogue_number);
	File* file = get_repository_file_using_archive_catalogue_number(service->repository, archive_catalogue_number);


	int result = delete_file_from_repository(service->repository, archive_catalogue_number);

	if (result == 1) // if the file was successfully added - register the operation
	{
		push(service->undo_stack, service->repository->Files);
	}	

	return result;
}

int update_file_service(Service* service, int archive_catalogue_number, char* state_of_deterioration, char* file_type, int year_of_creation)
{
	File* updated_file = create_file(archive_catalogue_number, state_of_deterioration, file_type, year_of_creation);

	File* file = get_repository_file_using_archive_catalogue_number(service->repository, archive_catalogue_number);

	int result = update_file_from_repository(service->repository, updated_file);

	if (result == 1) // if the file was successfully added - register the operation
	{
		push(service->undo_stack, service->repository->Files);
	}

	return result;
}

Repository* get_repository(Service* service)
{
	return service->repository;
}

int undo(Service* service)
{
	if (is_empty(service->undo_stack))
		return 0;
	service->repository->Files = pop(service->undo_stack);
	printf("pointer of current repo: %x\n",service->repository->Files);


	return 1;
}


int redo(Service* service)
{
	if (is_full(service->undo_stack))
	{
		return 0;
	}
	
	service->repository->Files = pop_next(service->undo_stack);

	return 1;
}

Repository* filter_by_year_of_creation(Service* service, int year_of_creation)
{
	Repository* list_of_files = create_repository();
	int index = 0;
	for (int i = 0; i < service->repository->Files->length; i++)
	{
		if (service->repository->Files->elements[i]->year_of_creation < year_of_creation)
		{
			list_of_files->Files->elements[index++] = service->repository->Files->elements[i];
		}
	}
	list_of_files->Files->length = index;
	int i, j;
	for (i = 0; i < list_of_files->Files->length; ++i)
	{
		for (j = i + 1; j < list_of_files->Files->length; ++j)
		{
			if (strcmp(list_of_files->Files->elements[i]->state_of_deterioration, list_of_files->Files->elements[j]->state_of_deterioration) > 0)
			{
				File* auxiliary_file = list_of_files->Files->elements[i];
				list_of_files->Files->elements[i] = list_of_files->Files->elements[j];
				list_of_files->Files->elements[j] = auxiliary_file;
			}
		}
	}

	return list_of_files;
}