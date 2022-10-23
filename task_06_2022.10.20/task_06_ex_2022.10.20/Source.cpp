#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void print(int* list, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}
int devide(int a, int b)
{
	if (b == 0)
	{
		throw exception("Division by zero!");
	}
	return a / b;

}

int main()
{
	ifstream f;
	f.exceptions(ifstream::badbit | ifstream::failbit);
	string name = "";

	int n = 0;
	int index = 0;
	int multipler = 0;

	cout << "file name?" << endl;
	cin >> name;
	try
	{
		f.open(name);
	}
	catch (const ifstream::failure& e)
	{
		cout << e.what() << endl;
		cout << "Error code " << e.code() << endl;
		cin >> name;
	}

	try
	{
		f >> n;
	}

	catch (const ifstream::failure & e)
	{
		cout << e.what() << endl;
		cout <<"Error code " << e.code() << endl;
	}
	
	int* Arr = new int[n];
	

	
	for (int i = 0; i < n; ++i)
	{
		try
		{
			f >> Arr[i];
		}
		catch (const exception& e)
		{
			cout << e.what() << endl;
		}
	}
	if (n < 1)
	{
		delete[] Arr;
	}
	
	print(Arr, n);

	cout << "index?" << endl;
	cin >> index;
	cout << "multipler?" << endl;
	cin >> multipler;



	try
	{
		if ((index >= n) || (index < 0))
		{
			throw exception("index out of range!");
		}
		else if (Arr[index] > 2147483647 / multipler)
		{
			throw exception("out of memory int");
		}
		Arr[index] *= multipler;
		cout << Arr[index] << endl;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
		cin >> name;
	}
	

	try
	{
		int z = devide(Arr[index], Arr[1]);
		cout << z << endl;
	}
	catch (exception & e)
	{
		cout <<  e.what() << std::endl;
		cin >> name;
	}

	f.close();

	try
	{
		if (n > 0)
		{
			throw exception("massive deleted already");
		}
		delete[] Arr;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
		cin >> name;
	}
	
	return 0;
}