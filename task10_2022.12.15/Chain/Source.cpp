#include <iostream>
using namespace std;
void quicksort(int* data, int const n)
{
	int const lenD = n;
	int pivot = 0;
	int ind = lenD / 2;
	int i, j = 0, k = 0;
	if (lenD > 1) {
		int* L = new int[lenD];
		int* R = new int[lenD];
		pivot = data[ind];
		for (i = 0; i < lenD; i++) {
			if (i != ind) {
				if (data[i] < pivot) {
					L[j] = data[i];
					j++;
				}
				else {
					R[k] = data[i];
					k++;
				}
			}
		}
		quicksort(L, j);
		quicksort(R, k);
		for (int cnt = 0; cnt < lenD; cnt++) {
			if (cnt < j) {
				data[cnt] = L[cnt];;
			}
			else if (cnt == j) {
				data[cnt] = pivot;
			}
			else {
				data[cnt] = R[cnt - (j + 1)];
			}
		}
	}
}

void bubbleSort(int* data, int n)
{
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = (n - 1); j >= (i + 1); j--) {
			if (data[j] < data[j - 1]) {
				tmp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = tmp;
			}
		}
	}
}

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

class Handler {
public:
	virtual Handler* SetNext(Handler* handler) = 0;
	virtual void Handle(int* a, int mx, int mn, int n) = 0;
};


class AbstractHandler : public Handler {

private:
	Handler* next_handler;

public:
	AbstractHandler() : next_handler(nullptr) {
	}
	Handler* SetNext(Handler* handler) override {
		this->next_handler = handler;

		return handler;
	}
	void Handle(int* a, int mx, int mn, int n) override {
		if (this->next_handler) {
			this->next_handler->Handle(a, mx, mn, n);
		}


	}
};

class IndexsortHandler : public  AbstractHandler
{ public:
	void Handle(int* a, int mx, int mn, int n) override {
		if (mx-mn < 500)
		{
			cout << "start doing indexsort" << endl;
			indexsort(a, n);
		}
		else
		{
			AbstractHandler::Handle(a, mx, mn, n);
		}
	}

};

class BubblesortHandler : public AbstractHandler
{
public:
	void Handle(int* a, int mx, int mn, int n) override {
		if (n < 10)
		{
			cout << "start doing bubblesort" << endl;
			bubbleSort(a, n);
		}
		else
		{
			AbstractHandler::Handle(a, mx, mn, n);
		}
	}
};

class QuicksortHandler : public  AbstractHandler
{
public:
	void Handle(int* a, int mx, int mn, int n) override {

		cout << "start doing quicksort" << endl;
		quicksort(a, n);


	}
};
void print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";

	}
	cout << endl;
}
int main()
{
	int a[8];
	int k = 0;
	int mx = 0;
	int mn = 233333333;
	cin >> k;
	for (int i = 0; i < 8; ++i)
	{
		a[i] = k * (rand() % 5 - 2) * (rand() % 100) * (rand() % 10);
		if (a[i] > mx) mx = a[i];
		if (a[i] < mn) mn = a[i];
	}
	print(a, 8);

	IndexsortHandler* index = new IndexsortHandler;
	BubblesortHandler* bubble = new BubblesortHandler;
	QuicksortHandler* quick = new QuicksortHandler;
	index->SetNext(bubble)->SetNext(quick);
	index->Handle(a, mx, mn, 8);
	print(a, 8);

	return 0;
}