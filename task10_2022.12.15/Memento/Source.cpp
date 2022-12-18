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

class Memento {
	
public:
	int data[10];
	virtual ~Memento(){}
	Memento(int dat[])
	{
		for (int i = 0; i < 10; ++i) data[i] = dat[i];
	}
};
class Originator {
public:
	int data[10];
	Originator()
	{
		for (int i = 0; i < 10; ++i)
		{
			data[i] = 0;
		}
	}
	~Originator() {  }
	Memento* Save()
	{
		return new Memento(this->data);
	}
	void Restore(Memento* memento) {
		for (int i = 0; i < 10; ++i)
		this->data[i] = memento->data[i];
		
	}
	void print()
	{
		for (int i = 0; i < 10; ++i)
		{
			cout << this->data[i] << " ";
		}
		cout << endl;
	}
};

class Caretaker
{
private:
	Memento* mem;
	Originator* orig;
public:
	Caretaker(Originator* orig) : orig(orig){}
	~Caretaker() { delete mem; }
	void Backup()
	{
		this->mem = this->orig->Save();
	}
	void Res()
	{
		this->orig->Restore(mem);
	}
};
int main()
{

	Originator massive;
	massive.print();
	for (int i = 0; i < 10; ++i)
	{
		massive.data[i] = (rand() % 5 - 2) * rand() % 100;
	}
	massive.print();
	Caretaker* caretaker = new Caretaker(&massive);
	caretaker->Backup();
	quicksort(massive.data, 10);
	massive.print();
	caretaker->Res();
	massive.print();
	return 0;
}