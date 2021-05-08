#pragma once
#include "domain.h"
#define CAPACITY 10

typedef void* TElement;

typedef struct
{
	TElement* elements;
	int length;			// actual length of the container
	int capacity;		// maximum capacity of the container
} Dynamic_contaier;

/*
	Creates a dynamic array of generic elements, with a given capacity.
	params:
		capacity - maximum capacity for the dynamic array (type int)
	return:
		a pointer the the created dynamic container
*/
Dynamic_contaier* create_dynamic_container(int capacity);

/*
	Destroys the dynamic container
	params:
		container - the dynamic container to be destroyed
*/
void destroy_dynamic_container(Dynamic_contaier* container);

/*
	Adds an element to the dynamic container
	params:
		container - the dynamic container to be destroyed (type Dynamic_container*)
		element - the element which weill be added (type TElement)
*/
void add_element_to_dynamic_container(Dynamic_contaier* container, TElement element);

/*
	Deletes an element from the dynamic container
	params:
		container - the dynamic container to be destroyed (type Dynamic_container*)
		identifier - the identifier of the item (type int)
*/
void delete_element_from_dynamic_container(Dynamic_contaier* container, int identifier);

/*
	Gives the lenght of the dynamic array
	params:
		container - the dynamic container to be destroyed (type Dynamic_container*)
	return:
		lenght - the lenght of the dynamic array (type int)
*/
int get_lenght_of_dynamic_container(Dynamic_contaier* container);

/*
	resizes the container if the capacity is reached
	params:
		container - the dynamic container to be resized (type Dynamic_container*)
*/
int resize(Dynamic_contaier* container);

TElement get_element_using_identifier(Dynamic_contaier* container, int identifier);

TElement get_element_at_position(Dynamic_contaier* container, int position);

// Tests
void tests_dynamic_container();