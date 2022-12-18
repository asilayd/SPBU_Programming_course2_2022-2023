#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include <fcntl.h> 

using namespace std;

template<typename T>
struct Vector {

private:
	int capacity;
	int count;
	T* data;

	void expand()
	{
		this->capacity *= 2;
		T* newdata = new T[capacity];
		for (int i = 0; i < count; ++i)
		{
			newdata[i] = data[i];
		}
		delete[] this->data;
		this->data = newdata;

	}

public:

	Vector(int capacity = 4)
	{
		this->capacity = capacity;
		this->count = 0;
		this->data = new T[capacity];
	}
	Vector(const Vector& vc)
	{
		this->capacity = vc.capacity;
		this->count = vc.count;
		this->data = new T[capacity];
		for (int i = 0; i < count; ++i)
		{
			this->data[i] = vc.data[i];
		}
	}
	~Vector()
	{
		this->capacity = 0;
		this->count = 0;
		delete[] this->data;
	}
	void Add(T value)
	{
		if (count < capacity)
		{

			data[count] = value;
			count += 1;
		}
		else
		{
			expand();
			data[count] = value;
			count += 1;
		}
	}
	void Print()
	{
		for (int i = 0; i < count; ++i)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}

	T& operator[](int p)
	{
		return this->data[p];
	}
	void operator=(const Vector& vc)
	{
		if (this->data == vc.data)
		{ }
		else {
			this->capacity = vc.capacity;
			this->count = vc.count;
			delete[] this->data;
			T* newdata = new T[capacity];
			for (int i = 0; i < count; ++i)
			{
				newdata[i] = vc.data[i];
			}
			this->data = newdata;
		}
	}
	friend ostream& operator<<(ostream& stream, const Vector& vc)
	{
		stream << "[" << vc.count << "/" << vc.capacity << "] {";
		if (vc.count == 0)
		{
			stream << "EMPTY }";
		}
		else {
			for (int i = 0; i < vc.count - 1; ++i)
			{
				stream << vc.data[i] << ", ";
			}
			stream << vc.data[vc.count - 1] << "}" << endl;
		}

		return stream;
	}
};

int main()
{
	
	ofstream out("test.txt", ios::binary);
	int s = 40;
	Vector<int> vc(s);
	for (int i = 0; i < s; ++i)
	{
		vc.Add(i);
	}

	cout << vc << endl;
	int value;
	for (int i = 0; i < s; ++i)
	{
		value = vc[i];
		out.write(reinterpret_cast<char*>(&value), sizeof(int));
		

	}
	
	out.close();

	ifstream in("test.txt", ios::binary);
	char x[sizeof(int)];
	Vector<int> after_read_vc;
	
	while (in.read(x, sizeof(int)))
	{
		int* n = reinterpret_cast<int*>(x);
		after_read_vc.Add(*n);
		
	}
	cout << endl;
	cout << after_read_vc << endl;
	return 0;
}