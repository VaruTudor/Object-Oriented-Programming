#include "Dynamic_vector.h"
#include <assert.h>
#include <string.h>

Dynamic_vector::Dynamic_vector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elements = new TElement[capacity];
}

Dynamic_vector::Dynamic_vector(const Dynamic_vector& dynamic_vector)
{
	this->size = dynamic_vector.size;
	this->capacity = dynamic_vector.capacity;
	this->elements = new TElement[this->capacity];
	for (int i = 0; i < dynamic_vector.capacity; i++)
		this->elements[i] = dynamic_vector.elements[i];
}

Dynamic_vector::~Dynamic_vector()
{
	delete[] this->elements;
}

Dynamic_vector& Dynamic_vector::operator=(const Dynamic_vector& dynamic_vector)
{
	if (this == &dynamic_vector)
		return *this;

	this->size = dynamic_vector.size;
	this->capacity = dynamic_vector.capacity;

	delete[] this->elements;
	this->elements = new TElement[this->capacity];

	for (int i = 0; i < this->size; i++)
		this->elements[i] = dynamic_vector.elements[i];

	return *this;
}

void Dynamic_vector::add(const TElement& element)
{
	if (this->size == this->capacity)
		this->resize();

	this->elements[this->size] = element;
	this->size++;
}

void Dynamic_vector::add_to_position(const TElement& element, int position)
{
	if (this->size == this->capacity)
		this->resize();

	for (int i = this->size; i > position; i--)
	{
		this->elements[i] = this->elements[i - 1];
	}

	this->elements[position] = element;
	this->size++;
}

int Dynamic_vector::check_valid_position(int position)
{
	if (position > this->size || position < 0)
		return -1;

	return 1;
}

void Dynamic_vector::remove(int position)
{
	if (check_valid_position(position) == 1)
	{
		for (int i = position; i < this->size; i++)
			this->elements[i] = this->elements[i + 1];
		this->size--;
	}
}

void Dynamic_vector::remove_using_name(const std::string& name)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->elements[i].get_name().compare(name) == 0)
			this->remove(i);
	}
}

void Dynamic_vector::resize(int factor)
{
	this->capacity *= factor;

	TElement* new_dynamic_vector = new TElement[this->capacity];

	for (int i = 0; i < this->size; i++)
		new_dynamic_vector[i] = this->elements[i];

	delete[] this->elements;
	this->elements = new_dynamic_vector;
}

int Dynamic_vector::get_capacity() const
{
	return this->capacity;
}

int Dynamic_vector::get_size() const
{
	return this->size;
}

TElement Dynamic_vector::get_element(int position)
{
	return this->elements[position];
}

//-------------TESTS------------

void add_to_dynamic_vector__Valid_input__Item_added_to_dynamic_vector()
{
	Dynamic_vector dynnamic_vector{};
	Victim victim1{ "aa","bb",10,"cc" };

	dynnamic_vector.add(victim1);

	assert(dynnamic_vector.get_size() == 1);
}

void add_to_dynamic_vector_to_position__Valid_input__Item_added_to_dynamic_vector()
{
	Dynamic_vector dynnamic_vector{};
	TElement victim1{ "aa","bb",10,"cc" };
	TElement victim2{ "bb","cc",20,"dd" };
	TElement victim3{ "cc","dd",23,"ee" };

	dynnamic_vector.add(victim1);
	dynnamic_vector.add(victim2);
	dynnamic_vector.add_to_position(victim3, 1);

	assert(dynnamic_vector.get_element(1).get_name().compare("cc") == 0);
}

void get_element__Valid_input__Coresponding_element_is_returned()
{
	Dynamic_vector dynnamic_vector{};
	TElement victim1{ "aa","bb",10,"cc" };

	dynnamic_vector.add(victim1);

	assert(dynnamic_vector.get_element(0).get_photograph().compare("cc") == 0);
}

void resize_Size_increases_over_capacity_Capacity_increases()
{
	Dynamic_vector dynnamic_vector{1};
	TElement victim1{ "aa","bb",10,"cc" };
	TElement victim2{ "bb","cc",20,"dd" };

	dynnamic_vector.add(victim1);
	dynnamic_vector.add(victim2);

	assert(dynnamic_vector.get_capacity() == 2);
}

void remove_element_from_dynamic_vector__Not_valid_input__Element_is_not_removed()
{
	Dynamic_vector dynnamic_vector{};
	TElement victim1{ "aa","bb",10,"cc" };

	dynnamic_vector.add(victim1);
	dynnamic_vector.remove(-1);

	assert(dynnamic_vector.get_size() == 1);
}

void remove_element_from_dynamic_vector__Valid_input__Element_is_removed()
{
	Dynamic_vector dynnamic_vector{};
	TElement victim1{ "aa","bb",10,"cc" };

	dynnamic_vector.add(victim1);
	dynnamic_vector.remove(0);

	assert(dynnamic_vector.get_size() == 0);
}

void remove_element_using_name__Valid_input_Element_is_removed()
{
	Dynamic_vector dynnamic_vector{};
	TElement victim1{ "aa","bb",10,"cc" };

	dynnamic_vector.add(victim1);
	dynnamic_vector.remove_using_name("aa");

	assert(dynnamic_vector.get_size() == 0);
}

void remove_element_from_dynamic_vector_using_name__Not_valid_input__Element_is_not_removed()
{
	Dynamic_vector dynnamic_vector{};
	TElement victim1{ "aa","bb",10,"cc" };

	dynnamic_vector.add(victim1);
	dynnamic_vector.remove_using_name("bb");

	assert(dynnamic_vector.get_size() == 1);
}

void test_dynamic_vector()
{
	add_to_dynamic_vector__Valid_input__Item_added_to_dynamic_vector();
	add_to_dynamic_vector_to_position__Valid_input__Item_added_to_dynamic_vector();
	get_element__Valid_input__Coresponding_element_is_returned();
	resize_Size_increases_over_capacity_Capacity_increases();
	remove_element_from_dynamic_vector__Not_valid_input__Element_is_not_removed();
	remove_element_from_dynamic_vector__Valid_input__Element_is_removed();
	remove_element_using_name__Valid_input_Element_is_removed();
	remove_element_from_dynamic_vector_using_name__Not_valid_input__Element_is_not_removed();
}