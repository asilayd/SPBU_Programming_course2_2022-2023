#include <iostream>
#include <thread>

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

void monkeysort(int* a, int n)
{
	bool isSorted = false;
	while (!isSorted)
	{
		for (int i = 0; i < n; i++)
		{
			int randInd1 = rand() % n;
			int randInd2 = rand() % n;
			int temp = a[randInd2];
			a[randInd2] = a[randInd1];
			a[randInd1] = temp;

		}
		for (int i = 0; i < n - 1; i++)
		{
			if ((a[i] - a[i + 1]) < 0)
			{
				isSorted = false;
				break;
			}
			isSorted = true;
		}
	}


}


void print(int* a, int n)
{
	for (size_t i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

}

int main()
{
	auto start = chrono::high_resolution_clock::now();
	int a[100000];
	int b[100000];
	int c[10];
	for (int i = 0; i < 100000; ++i)
	{
		a[i] = rand() % 10;
		b[i] = rand() % 10;

	}
	for (int i = 0; i < 10; ++i)
	{
		c[i] = rand() % 10;
	}
	
	thread flow1(monkeysort, c, 10);
	thread flow2(indexsort, b, 100000);
	indexsort(a, 100000);

	flow1.join();
	flow2.join();

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;

	cout << "Time: " << duration.count() << endl;

}