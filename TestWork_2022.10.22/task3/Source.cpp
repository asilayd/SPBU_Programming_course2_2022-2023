#include <iostream>

using namespace std;

class A
{
public:
	int capacity;
	
	A(int n = 1)
	{
		capacity = n;
	}


};


class B : public A
{
public:
	int** matrix;
	
	
	B(int c) 
	{
		capacity = c;
		matrix = new int* [capacity];
		for (int i = 0; i < capacity; ++i)
		{
			matrix[i] = new int[capacity];
		}
	}
	~B()
	{
		for (int i = 0; i < capacity; ++i) // if the destructor A was called first, and not B, then it 
		{                                 //would not be possible to correctly clear 
			delete[] matrix[i];          //the memory from the arrays lying in B
		}
	}

};


int main()
{
	B m(4);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			m.matrix[i][j] = 1 - j % 2;
		}

	}
	
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << m.matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	
}