#pragma once
#include "Victim.h"

typedef Victim TElement;

class Dynamic_vector
{
private:
	TElement* elements;
	int size;
	int capacity;

public:
	// default constructor
	Dynamic_vector(int capacity = 10);

	// constructor for copy
	Dynamic_vector(const Dynamic_vector& dynamic_vector);

	// destructor
	~Dynamic_vector();

	// asignment operator
	Dynamic_vector& operator = (const Dynamic_vector& dynamic_vector);

	// add method
	void add(const TElement& element);

	// add to position method
	void add_to_position(const TElement& element, int position);

	/*
		checks the validity of a position
		returns:
			1 - the item was removed
			-1 - the position was not valid
	*/
	int check_valid_position(int position);

	/*
		removes an element from the dynamic vector using the position
	*/
	void remove(int position);

	/*
		removes an element from the dynamic vector using it's name
	*/
	void remove_using_name(const std::string& name);

	// getter for size of dynamic vector
	int get_size() const;

	// getter for capacity of dynamic vector
	int get_capacity() const;

	// getter for element on specified position
	// check validity of position
	TElement get_element(int position);

private:
	// resize method for dynamic vector
	void resize(int factor = 2);
};

void test_dynamic_vector();