#include "repository_dynamic_containers.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>



Repository_of_dynamic_containers* create_stack()
{
	Repository_of_dynamic_containers* repository_of_dynamic_containers = (Dynamic_contaier*)malloc(sizeof(Dynamic_contaier));

	Dynamic_contaier* new_dynamic_container = create_dynamic_container(20);
	repository_of_dynamic_containers->repositories[0] = new_dynamic_container;
	repository_of_dynamic_containers->lenght_of_repositories = 1;
	repository_of_dynamic_containers->capacity = 1;

	return repository_of_dynamic_containers;
}

void destroy_stack(Repository_of_dynamic_containers* repository_of_dynamic_containers)
{
	if (repository_of_dynamic_containers == NULL)
		return;

	for (int i = 0; i < repository_of_dynamic_containers->capacity-2; i++)
		free(repository_of_dynamic_containers->repositories[i]);

	// free the stack
	free(repository_of_dynamic_containers);
}

void push(Repository_of_dynamic_containers* operations_stack, Dynamic_contaier* dynamic_contaier)
{
	Dynamic_contaier* new_dynamic_container = create_dynamic_container(20);
	for (int i = 0; i < dynamic_contaier->length; i++)
	{
		add_element_to_dynamic_container(new_dynamic_container, dynamic_contaier->elements[i]);
	}

	operations_stack->repositories[operations_stack->lenght_of_repositories] = new_dynamic_container;
	operations_stack->lenght_of_repositories++;
	operations_stack->capacity++;
}

Dynamic_contaier* pop(Repository_of_dynamic_containers* repository_of_dynamic_containers)
{
	repository_of_dynamic_containers->lenght_of_repositories--;
	Dynamic_contaier* new_copy_of_dynamic_container = repository_of_dynamic_containers->repositories[repository_of_dynamic_containers->lenght_of_repositories-1];

	return new_copy_of_dynamic_container;
}


Dynamic_contaier* pop_next(Repository_of_dynamic_containers* repository_of_dynamic_containers)
{
	Dynamic_contaier* new_copy_of_dynamic_container = repository_of_dynamic_containers->repositories[repository_of_dynamic_containers->lenght_of_repositories];
	repository_of_dynamic_containers->lenght_of_repositories++;

	return new_copy_of_dynamic_container;
}




int is_empty(Repository_of_dynamic_containers* repository_of_dynamic_containers)
{
	return (repository_of_dynamic_containers->lenght_of_repositories == 0);
}

int is_full(Repository_of_dynamic_containers* repository_of_dynamic_containers)
{
	return (repository_of_dynamic_containers->lenght_of_repositories == 100);
}

// Tests
/*
void tests_repository_of_dynamic_containers()
{
	Repository_of_dynamic_containers* operations_stack = create_stack();

	File* file1 = create_file(11, "c", "srial", 13);
	File* file2 = create_file(14, "Wf 1061", "ter", 18);
	Operation* operation1 = create_operation(file1, "add");
	Operation* operation2 = create_operation(file2, "add");
	Operation* operation3 = create_operation(file1, "delete");

	// the files may be destroyed, as the operations contain copies of these files
	//destroy_file(file1);
	//destroy_file(file2);

	push(operations_stack, operation1);
	push(operations_stack, operation2);
	push(operations_stack, operation3);

	//expected: the operation stack is not full nor empty
	assert(is_full(operations_stack) == 0);
	assert(is_empty(operations_stack) == 0);

	Operation* operation = pop(operations_stack);
	//expected: the operation type is delete
	assert(strcmp(operation->operation_type, "delete") == 0);
	// after each pop, the operations must be destroyed
	destroy_operation(operation);

	operation = pop(operations_stack);
	//expected: the operation type is add
	assert(strcmp(operation->operation_type, "add") == 0);
	destroy_operation(operation);

	operation = pop(operations_stack);
	//expected: the operation type is add
	assert(strcmp(operation->operation_type, "add") == 0);
	//destroy_operation(operation3);

	//expected: the operation stack is empty
	assert(is_empty(operations_stack) == 1);

	destroy_file(file1);
	destroy_file(file2);

	//we destroy the operations
	destroy_operation(operation);
	destroy_operation(operation1);
	destroy_operation(operation2);
	destroy_operation(operation3);



	// destroy the stack
	destroy_stack(operations_stack);
}
*/