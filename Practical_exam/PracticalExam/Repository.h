#pragma once

#include "domain.h"

#include <vector>

// NOTE: tests for repository are bellow the implementation

template <typename T>
class MemoryRepository
{
private:
	std::vector<T> elements;
public:
	MemoryRepository() {};

	/*
	adds a new element in the repository
	pre:
		new_element - type T 
	post:
		new element is added tot the repository
	*/
	void add(T new_element);

	/*
	removes an element from the repository if found
	pre:
		new_element - type T
	post:
		new_element is removed if found
	*/
	void remove(T new_element);

	/*
	updates an element from the repository if found
	pre:
		new_element - type T
		old_element - type T
	post:
		old_element is updated if found with new_element
	*/
	void update(T old_element, T new_element);

	/*
	returns a vector containing all the elements from the repository
	*/
	std::vector<T> get_all_items() { return this->elements; };
};

template<typename T>
inline void MemoryRepository<T>::add(T new_element)
{
	this->elements.push_back(new_element);
}

template<typename T>
inline void MemoryRepository<T>::remove(T new_element)
{
	int i = 0;
	for (auto element : this->elements)
	{
		if (element == new_element)
		{
			this->elements.erase(this->elements.begin() + i);
			break;
		}
		i++;
	}
}

template<typename T>
inline void MemoryRepository<T>::update(T old_element, T new_element)
{
	int i = 0;
	for (auto element : this->elements)
	{
		if (element == old_element)
		{
			this->elements[i] = new_element;
			break;
		}
		i++;
	}
}

#include <string>
#include <sstream>
#include <fstream>

template <typename T>
class FileRepository
{
private:
	std::vector<T> elements;
	std::string file_path;
public:

	FileRepository(std::string new_file_name);

	/*
	adds a new element in the repository
	pre:
		new_element - type T
	post:
		new_element is added tot the repository
	*/
	void add(T new_element);

	/*
	removes an element from the repository if found
	pre:
		new_element - type T
	post:
		new_element is removed if found
	*/
	void remove(T new_element);

	/*
	updates an element from the repository if found
	pre:
		new_element - type T
		old_element - type T
	post:
		old_element is updated if found with new_element
	*/
	void update(T old_element, T new_element);

	/*
	writes all the elements from the repository to file
	*/
	void write_to_file();

	/*
	returns a vector containing all the elements from the repository
	*/
	std::vector<T> get_all_items() { return this->elements; };

	void write_to_file_sorted();
};

template<typename T>
inline FileRepository<T>::FileRepository(std::string new_file_name)
{
	this->file_path = new_file_name;
	std::ifstream file(this->file_path.c_str());
	
	T new_element;
	while (file >> new_element)
	{
		this->elements.push_back(new_element);
	}
	file.close();
}

template<typename T>
inline void FileRepository<T>::add(T new_element)
{
	this->elements.push_back(new_element);
	this->write_to_file();
}

template<typename T>
inline void FileRepository<T>::remove(T new_element)
{
	int i = 0;
	for (auto element : this->elements)
	{
		if (element == new_element)
		{
			this->elements.erase(this->elements.begin() + i);
			break;
		}
		i++;
	}
	this->write_to_file();
}

template<typename T>
inline void FileRepository<T>::update(T old_element, T new_element)
{
	int i = 0;
	for (auto element : this->elements)
	{
		if (element == old_element)
		{
			this->elements[i] = new_element;
			break;
		}
		i++;
	}
	this->write_to_file();
}

template<typename T>
inline void FileRepository<T>::write_to_file()
{
	std::ofstream file(this->file_path.c_str());
	for (auto element : this->elements)
		file << element;
	file.close();
}

template<typename T>
inline void FileRepository<T>::write_to_file_sorted()
{
	if (this->elements.size() != 0)
	{
		std::ofstream file(this->file_path.c_str());
		// sort by constelation
		bool is_sorted = false;
		while (!is_sorted)
		{
			int changes = 0;
			int i;
			for (i = 0; i < this->elements.size() - 1; i++)
			{
				if (this->elements[i] > this->elements[i + 1])
				{
					auto aux = this->elements[i];
					this->elements[i] = this->elements[i + 1];
					this->elements[i + 1] = aux;
					changes++;
				}
			}
			if (changes == 0)
				is_sorted = true;
		}
		for (auto element : this->elements)
			file << element;
		file.close();
	}
}

// TESTS

void test_add_repository();