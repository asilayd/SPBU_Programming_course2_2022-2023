#include "Array.h"
#include <iostream>

using namespace std;

Array::Array(int capacity) {
	this->capacity = capacity;
	this->data = new int[capacity];
}

Array::Array(const Array& list) {
	this->capacity = list.capacity;
	this->data = new int[list.capacity];
	for (int i = 0; i < list.capacity; ++i)
	{
		this->data[i] = list.data[i];
	}

}

Array::~Array()
{
	for (int i = 0; i < this->capacity; ++i)
	{
		this->data[i] = 0;
	}
	this->capacity = 0;
}

int Array::Get(int position) {
	if (position < this->capacity)
	{
		return this->data[position];
	}

	else
	{
		exit(EXIT_FAILURE);
	}

}

void Array::Set(int position, int value)
{
	if (position < this->capacity)
	{
		this->data[position] = value;
	}

	else
	{
		cout << "no capacity to add" << endl;
	}
}