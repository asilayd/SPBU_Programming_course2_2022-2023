#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void indexsort(int* list, int n)
{
	int max = 0;
	int min = 2147483647 - 1;
	for (int i = 0; i < n; ++i)
	{
		if (list[i] > max) { max = list[i]; }
		if (list[i] < min) { min = list[i]; }
	}
	int* r = new int[max - min + 1];
	for (int i = 0; i < max - min + 1; ++i)
	{
		r[i] = 0;
		r[i] = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		r[list[i] - min] += 1;
	}


	int k = 0;

	for (int i = 0; i < max - min + 1; ++i)
	{
		for (int j = 0; j < r[i]; ++j)
		{
			list[k] = i + min;
			++k;
		}

	}

	delete[] r;
}

void print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " , ";
	}
	cout << endl;
}

int main()
{
	ifstream in("test1.txt", ios::binary);
	string line;
	stringstream x;
	getline(in, line);
	x << line;
	int n;
	x >> n;
	int i = 0;
	int* a = new int[n];
	while (getline(in, line))
	{
		int t = stoi(line);
		a[i] = t;

		++i;
	}
	indexsort(a, n);

	ofstream out("result1.txt");
	out << n << endl;
	for (int i = 0; i < n; ++i)
	{
		out << a[i] << endl;
	}
	out.close();
	return 0;
}