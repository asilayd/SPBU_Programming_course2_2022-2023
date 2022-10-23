#include <iostream>

using namespace std;

template<typename T, int size>
struct Vector
{
	T* data;
	Vector()
	{
		data = new T[size];
	}
	
	void f()
	{
		for (int i = 0; i < size; ++i)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
};

template<typename T>
struct Vector<T, 3> //partial specialization of the template
{
	T* data;
	Vector()
	{
		data = new T[3];
		for (int i = 0; i < 3; ++i)
		{
			data[i] = 1;
		}
		
	}
	void g()
	{
		for (int i = 0; i < 3; ++i)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	Vector<int, 3> v;
	Vector<double, 10> z;
	v.g();
	z.f();


	return 0;
}