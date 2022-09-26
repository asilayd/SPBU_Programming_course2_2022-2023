#pragma once
#include<iostream>

class Array 
{
private:
	int* data;
	int capacity;

public:
	
	Array(int capacity = 10);
	Array(const Array& list);
	~Array();

	int Get(int position);
	void Set(int position, int value);

};