#include "dynamic_container.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

Dynamic_contaier* create_dynamic_container(int capacity)
{
	Dynamic_contaier* dynamic_containeray = (Dynamic_contaier*)malloc(sizeof(Dynamic_contaier));
	// make sure that the space was allocated
	if (dynamic_containeray == NULL)
		return NULL;

	dynamic_containeray->capacity = capacity;
	dynamic_containeray->length = 0;

	// allocate space for the elements
	dynamic_containeray->elements = (TElement*)malloc(capacity * sizeof(TElement));
	if (dynamic_containeray->elements == NULL)
		return NULL;

	return dynamic_containeray;
}

void destroy_dynamic_container(Dynamic_contaier* container)
{
	if (container == NULL)
		return;

	for (int i = 0; i < container->length; i++)
		destroy_file(container->elements[i]);

	// free the space allocated for the elements
	free(container->elements);
	container->elements = NULL;

	// free the space allocated for the dynamic containeray
	free(container);
}

// Resizes the containeray, allocating more space.
// If more space cannot be allocated, returns -1, else it returns 0.
int resize(Dynamic_contaier* container)
{
	if (container == NULL)
		return -1;

	container->capacity *= 2;

	// allocate new memory, copy everything and deallocate the old memory
	TElement* aux = (TElement*)malloc(container->capacity * sizeof(TElement));
	if (aux == NULL)
		return -1;

	for (int i = 0; i < container->length; i++)
		aux[i] = container->elements[i];

	free(container->elements);
	container->elements = aux;

	return 0;
}

void add_element_to_dynamic_container(Dynamic_contaier* container, TElement element)
{

	// resize the containeray, if necessary
	if (container->length == container->capacity)
		resize(container);
	container->elements[container->length++] = element;
}

void delete_element_from_dynamic_container(Dynamic_contaier* container, int identifier)
{
	int index = 0, element_found = 0;
	while (index < container->length)
	{
		if (get_archive_catalogue_number(container->elements[index]) == identifier)
		{
			element_found = 1;
		}
		if (element_found == 1)
		{
			container->elements[index] = container->elements[index + 1];
		}
		index += 1;
	}
	container->length -= 1;
}

int get_lenght_of_dynamic_container(Dynamic_contaier* container)
{
	if (container == NULL)
		return -1;

	return container->length;
}



TElement get_element_using_identifier(Dynamic_contaier* container, int identifier)
{
	if (container == NULL)
		return NULL;

	int index = 0;
	while (index < container->length)
	{
		if (get_archive_catalogue_number(container->elements[index]) == identifier)
		{
			return container->elements[index];
		}
		index += 1;
	}
	return NULL;
}

TElement get_element_at_position(Dynamic_contaier* container, int position)
{
	if (container == NULL)
		return NULL;
	if (position < 0 || position >= container->length)
		return NULL;

	return container->elements[position];
}

// ------------------------------------------------------------------------------------------------------------
// Tests


void test_add_element_to_dynamic_container()
{
	Dynamic_contaier* dynamic_container = create_dynamic_container(2);

	assert(dynamic_container->capacity == 2);
	assert(dynamic_container->length == 0);

	File* file1 = create_file(1, "a", "b", 2);

	add_element_to_dynamic_container(dynamic_container, file1);
	// expected: item is added
	assert(dynamic_container->length == 1);

	File* file2 = create_file(2, "b", "c", 3);

	add_element_to_dynamic_container(dynamic_container, file2);
	// expected: item is added
	assert(dynamic_container->length == 2);

	File* file3 = create_file(3, "c", "d", 4);

	add_element_to_dynamic_container(dynamic_container, file3);
	// expected: capacity doubles, item is added
	assert(dynamic_container->capacity == 4);
	assert(dynamic_container->length == 3);


	destroy_dynamic_container(dynamic_container);
}

void test_delete_element_from_dynamic_container()
{
	Dynamic_contaier* dynamic_container = create_dynamic_container(2);

	assert(dynamic_container->capacity == 2);
	assert(dynamic_container->length == 0);

	File* file1 = create_file(1, "a", "b", 2);

	add_element_to_dynamic_container(dynamic_container, file1);
	// expected: item is added
	assert(dynamic_container->length == 1);

	File* file2 = create_file(2, "b", "c", 3);

	add_element_to_dynamic_container(dynamic_container, file2);
	// expected: item is added
	assert(dynamic_container->length == 2);

	delete_element_from_dynamic_container(dynamic_container, 1);
	// expected: item is deleted
	assert(dynamic_container->length == 1);
	destroy_file(file1);

	destroy_dynamic_container(dynamic_container);
}

void tests_dynamic_container()
{
	test_add_element_to_dynamic_container();
	test_delete_element_from_dynamic_container();
}
