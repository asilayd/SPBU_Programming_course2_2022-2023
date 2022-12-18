#include <iostream>

using namespace std;

template<typename T>
class Vector {
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
		{

		}
		else 
		{
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
	
	Vector<int> vc(10);
	Vector<int> vc1(3);
	for (int i = 0; i < 14; ++i)
	{
		vc.Add(i);
		cout << vc[i] << endl;
		
		
	}
	vc = vc;
	vc[3] = 150;
	cout << vc << endl;
	
	
}