#pragma once
#include <string>


template <typename T>

class DynamicVector
{
private:
	int capacity, size;
	T* elements;


public:
	//!!the rule of 3
	//(dynamically allocated memory -> destructor, copy constructor
	//, asignmnent operator

	//constructor for DynamicVector
	DynamicVector(int capacity = 10);

	//destructor
	~DynamicVector();

	//getter for the size
	int get_size() const;

	//getter for the capacity
	int get_capacity() const;

	//add an element to the DynamicVector
	void add_to_DynamicVector(T element);

	//adds an element to a position
	void add_to_position(T element, int position);

	/*
		checks the validity of a position
		return:
			-1 - invalid
			1 - valid
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

	T& operator[](int position);

	//copy constructor
	DynamicVector(const DynamicVector& vector);

	//asignment operator
	DynamicVector& operator = (const DynamicVector& vector);

	//returns an element on position
	T get_element(int position);

private:
	//resize in case capacity is reached
	void resize();

};

template<typename T>
inline DynamicVector<T>::DynamicVector(int capacity): capacity{capacity}, size{0}
{
	this->elements = new T[this->capacity];
}

template<typename T>
inline DynamicVector<T>::~DynamicVector()
{
	delete[] this->elements;
}

template<typename T>
inline int DynamicVector<T>::get_size() const
{
	return this->size;
}

template<typename T>
inline int DynamicVector<T>::get_capacity() const
{
	return this->capacity;
}

template<typename T>
inline void DynamicVector<T>::add_to_DynamicVector(T element)
{
	if (this->capacity == this->size)
		this->resize();

	this->elements[this->size++] = element;
}

template<typename T>
inline void DynamicVector<T>::add_to_position(T element, int position)
{
	if (this->capacity == this->size)
		this->resize();

	for (int i = this->size; i > position; i--)
	{
		this->elements[i] = this->elements[i - 1];
	}

	this->elements[position] = element;
	this->size++;
}

template<typename T>
inline int DynamicVector<T>::check_valid_position(int position)
{
	if (position > this->size || position < 0)
		return -1;

	return 1;
}

template<typename T>
inline void DynamicVector<T>::remove(int position)
{
	if (check_valid_position(position) == 1)
	{
		for (int i = position; i < this->size; i++)
			this->elements[i] = this->elements[i + 1];
		this->size--;
	}
}

template<typename T>
inline void DynamicVector<T>::remove_using_name(const std::string& name)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->elements[i].get_name().compare(name) == 0)
			this->remove(i);
	}
}

template<typename T>
inline T& DynamicVector<T>::operator[](int position)
{
	return this->elements[position]; 
}

template<typename T>
inline DynamicVector<T>::DynamicVector(const DynamicVector& vector)
{
	this->capacity = vector.capacity;
	this->size = vector.size;

	this->elements = new T[this->capacity];

	for (int i = 0; i < this->size; i++)
	{
		this->elements[i] = vector.elements[i];
	}
}

template<typename T>
inline DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector& vector)
{ 
	if (this == &vector)
		return *this; 

	this->capacity = vector.capacity;
	this->size = vector.size;

	delete[] this->elements;

	//reallocate new memory with the new capacity
	this->elements = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->elements[i] = vector.elements[i];
	}

	//we dereference because it receives an address
	return *this;
}

template<typename T>
inline T DynamicVector<T>::get_element(int position)
{
	return this->elements[position];
}


template<typename T>
inline void DynamicVector<T>::resize()
{
	this->capacity *= 2;
	T* auxiliary_vector_of_elements = new T[this->capacity];

	for (int i = 0; i < this->size; i++)
	{
		auxiliary_vector_of_elements[i] = this->elements[i];
	}

	delete[] this->elements;

	this->elements = auxiliary_vector_of_elements;
}

void test_DynamicVector();
