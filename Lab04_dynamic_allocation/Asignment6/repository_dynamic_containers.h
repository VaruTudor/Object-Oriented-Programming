#pragma once
#include "domain.h"
#include "dynamic_container.h"
#include "repository.h"
#include <string.h>

typedef struct
{
	Dynamic_contaier** repositories;
	int lenght_of_repositories;
	int capacity;
} Repository_of_dynamic_containers;

Repository_of_dynamic_containers* create_stack();

void destroy_stack(Repository_of_dynamic_containers* operation_stack);

void push(Repository_of_dynamic_containers* operation_stack, Dynamic_contaier* repository);
Dynamic_contaier* pop(Repository_of_dynamic_containers* operation_stack);
Dynamic_contaier* pop_next(Repository_of_dynamic_containers* operation_stack);

int is_empty(Repository_of_dynamic_containers* operation_stack);
int is_full(Repository_of_dynamic_containers* operation_stack);