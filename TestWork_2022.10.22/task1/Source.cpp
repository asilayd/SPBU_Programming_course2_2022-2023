#include <iostream>

using namespace std;

struct weapon
{
private:
	int damage;
public:
	weapon(int n = 1)
	{
		this->damage = n;
	}

	~weapon() //this descructor will be called when robot destructor is calling 
	{
		this->damage = 0;
	}
};

struct robot
{
private:
	int size;
	weapon gun;
public:
	robot(int s = 0, weapon g = weapon())
	{
		this->size = s;
		this->gun = g;
	}
	~robot()
	{}

	robot operator+(robot b1)
	{
		return robot(this->size + b1.size, this->gun);
	}
	robot operator=(robot b1)
	{
		this->size = b1.size;
		this->gun = b1.gun;
		return *this;
	}

};

void build_bot(int n, weapon g)
{
	robot test_bot(n, g);//in the end of this function work, descructor for test_bot will be calling 
	cout << "we build robot, but it will be destroyed cause this is works like that" << endl;
}

robot global_bot; //descructor will be called in the end of the main work

int main()
{
	weapon riffle(2);
	robot B1(1, riffle);
	robot B2(2, riffle);

	robot B3 = B1 + B2; //after B3 became a result of B1+B2, destructor for temperary B1+B2 will be called

	robot* Droids = new robot[4];
	delete[] Droids; //destructor for every robot in this massive will be called
	return 0;
}