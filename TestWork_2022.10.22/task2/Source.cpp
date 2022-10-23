#include <iostream>
#include <algorithm>

using namespace std;

struct foo {
	int* data = nullptr;
	int size = 0;
	foo(int n)
	{
		size = n;
		data = new int[2 * n];
	}
	foo( const foo &A)
	{
		size = A.size;
		data = new int[size * 2];
		for (int i = 0; i < 2 * A.size; ++i)
		{
			data[i] = A.data[i];
		}
		
	}
	~foo()
	{
		delete[] data;
	}

	foo operator=(const foo A)
	{
		foo T(A);
		Swap(T, *this);
		return T;
	}

	void print()
	{
		for (int i = 0; i < size * 2; ++i)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
	void Swap(foo& a, foo& b)
	{
		int s = a.size;
		int* tem = a.data;
		a.size = b.size;
		a.data = b.data;
		b.size = s;
		b.data = tem;
	}
};

foo F(foo A, int k)
{
	
	if (k > 0)
	{
		return F(A, k / 4);
	}
	//some action
	return A;
}

int main()
{
	foo f1(5);
	for (int i = 0; i < 5*2; ++i)
	{
		f1.data[i] = i;
	}
	foo f2(3);
	for (int i = 0; i < 6; ++i)
	{
		f2.data[i] = i+5;
	}

	f1.print();
	f2.print();

	f1 = f2;
	f1.print();
	f2.print();

	// the constructor will be called 4 times - three times when calling the 
	foo d = F(f1, 9);     //function F for k equal to 9, 2 and 0, as well as at the end of the work 
	d.print();          //during the return. That is, for this function, the constructor is called N 
	return 0;          //times, where N is k//4 + (k%4)%2 + 1
}