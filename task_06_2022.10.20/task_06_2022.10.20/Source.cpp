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
	f.open(name);

	f >> n;

	int* Arr = new int[n];

	for (int i = 0; i < n; ++i)
	{
		f >> Arr[i];
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

	cout << Arr[index] << endl;
	Arr[index] *= multipler;
	cout << Arr[index] << endl;

	int z = devide(Arr[index], Arr[1]);
	cout << z << endl;

	f.close();
	
	delete[] Arr;
	

	return 0;
}