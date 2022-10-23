#include <iostream>

using namespace std;

template <typename T>

void universal_sort(T* list, int n, int(*comparator)(T p1, T p2), void (*sort)(T* a, int n, int(*comparator)(T a, T b)) = nullptr)
{
	if (sort != nullptr)
	{
		sort(list, n, comparator);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (comparator(list[i], list[j]) > 0)
				{
					T temp = list[i];
					list[i] = list[j];
					list[j] = temp;
				}
			}
		}
	}
}

int comparator_more(int a, int b)
{
	return b-a;
}
int comparator_less(int a, int b)
{
	return a-b;
}
int comaratorSTR_more(string p1, string p2)
{
	return p1.length() - p2.length();
}

template<typename T>
void print(T* list, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}


template<typename T>
void indexsort(T* list, int n, int(*comparator)(T a, T b))
{
	int max = 0;
	int min = 2147483647-1;
	for (int i = 0; i < n; ++i)
	{
		if (list[i] > max) { max = list[i]; }
		if (list[i] < min) { min = list[i]; }
	}
	int* r = new int[max - min+1];
	for (int i = 0; i < max - min + 1; ++i)
	{
		r[i] = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		r[list[i]-min] += 1;
	}
	int d = comparator(1, 0);

	int k = 0;
	if (d > 0) {
		for (int i = 0; i < max - min + 1; ++i)
		{
			for (int j = 0; j < r[i]; ++j)
			{
				list[k] = i + min;
				++k;
			}

		}
	}
	else
	{
		for (int i = max-min; i >-1; --i)
		{
			for (int j = 0; j < r[i]; ++j)
			{
				list[k] = i + min;
				++k;
			}

		}
	}
	delete[] r;
}

int main()
{
	int a[10];
	for (int i = 0;i < 10; ++i)
	{
		a[i] = rand()%10-rand()%5;
	}

	print<int>(a, 10);
	universal_sort<int>(a, 10, comparator_less, indexsort);
	print<int>(a, 10);

	string s[8]{ "master","of", "puppets", "i" , "am",  "pulling",  "your" , "strings"};
	print<string>(s, 8);
	universal_sort(s, 8, comaratorSTR_more);
	print<string>(s, 8);

	return EXIT_SUCCESS;
}