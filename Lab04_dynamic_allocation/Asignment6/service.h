#pragma once
#include "repository.h"
#include "repository_dynamic_containers.h"

typedef struct
{
	Repository* repository;
	Repository_of_dynamic_containers* undo_stack;
} Service;

Service* create_service(Repository* repository, Repository_of_dynamic_containers* undo_stack);
void destroy_service(Service* service);

/// <summary>
/// Adds a planet to the repository of planets.
/// </summary>
/// <param name="s">Pointer to theService.</param>
/// <param name = "name">A string, the name of the planet.</param>
/// <param name = "type">A string, the planet's type.</param>
/// <param name = "distanceFromEarth">Double, the distance from the planet to Earth, in light years.</param>
/// <returns>1 - if the planet was sucessfully added; 0 - if the planet could not be added, as another planet with the same symbol already exists.</returns>
int add_file_service(Service* service, int archive_catalogue_number, char* state_of_deterioration, char* file_type, int year_of_creation);

int delete_file_service(Service* service, int archive_catalogue_number);

Repository* get_repository(Service* service);

/// <summary>
/// Undoes the last performed operation.
/// </summary>
/// <param name="s">Pointer to theService.</param>
/// <returns>1, if the undo operation could be done, 0 otherwise.</returns>
int undo(Service* service);

int update_file_service(Service* service, int archive_catalogue_number, char* state_of_deterioration, char* file_type, int year_of_creation);

int redo(Service* service);

Repository* filter_by_year_of_creation(Service* service, int year_of_creation);