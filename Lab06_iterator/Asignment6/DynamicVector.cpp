#include <assert.h>
#include "DynamicVector.h"

void create_DynamicVector__Valid_input__DynamicVector_is_created()
{
	DynamicVector<int> dynamic_vector{ 2 };
	
	assert(dynamic_vector.get_size() == 0);
}

void add_to_DynamicVector__Valid_input__Input_is_added_to_DynamicVector()
{
	DynamicVector<int> dynamic_vector{ 2 };

	dynamic_vector.add_to_DynamicVector(14);
	dynamic_vector.add_to_DynamicVector(22);

	assert(dynamic_vector.get_size() == 2);
}

void operator__Valid_input__Element_is_returned()
{
	DynamicVector<int> dynamic_vector{ 2 };

	dynamic_vector.add_to_DynamicVector(14);

	assert(dynamic_vector[0] == 14);
}

void copy_constructor__Valid_input__DynamicVector_is_copied()
{
	DynamicVector<int> dynamic_vector1{ 2 };
	dynamic_vector1.add_to_DynamicVector(5);

	DynamicVector<int> dynamic_vector2{ dynamic_vector1 };

	assert(dynamic_vector2.get_size() == 1);
}

void asignment_operator__Valid_input__DynamicVector_is_asigned()
{
	DynamicVector<int> dynamic_vector1{ 2 };
	dynamic_vector1.add_to_DynamicVector(5);

	DynamicVector<int> dynamic_vector2{};

	dynamic_vector2 = dynamic_vector1;
	assert(dynamic_vector2.get_size() == 1);
}

/*
//---ITERATOR TEST---

void iterator_test()
{
	DynamicVector<int> dynamic_vector1{ 2 };
	dynamic_vector1.add_to_DynamicVector(10);
	dynamic_vector1.add_to_DynamicVector(40);

	DynamicVector<int>::Iterator iterator = dynamic_vector1.begin();

	assert(*iterator == 10);
	*iterator = 11;

	assert(iterator != dynamic_vector1.end());
	++iterator;

	assert(*iterator == 40);
	iterator++;
}
*/

void test_DynamicVector()
{
	create_DynamicVector__Valid_input__DynamicVector_is_created();
	add_to_DynamicVector__Valid_input__Input_is_added_to_DynamicVector();
	operator__Valid_input__Element_is_returned();
	copy_constructor__Valid_input__DynamicVector_is_copied();
	asignment_operator__Valid_input__DynamicVector_is_asigned();
	//iterator_test();
}

