#include <iostream>
#include <fstream>
#include <string>

using namespace std;




template<typename T, typename arg1 = int, typename arg2 = int>
class F_log
{
public:
	int t;
	F_log(int t = 0) : t(t) {}

	void log(T functor)
	{

		t += 1;
		ofstream rec;
		rec.open("log.txt", ios::app);
		rec << "T:" << t << " " << "no arg " << "result: " << functor() << endl;
		rec.close();

	}
	void log(T functor, arg1 x)
	{

		t += 1;
		ofstream rec;
		rec.open("log.txt", ios::app);
		rec << "T:" << t << " " << "no arg " << "result: " << functor(x) << endl;
		rec.close();



	}
	void log(T functor, arg1 x, arg2 y)
	{

		t += 1;
		ofstream rec;
		rec.open("log.txt", ios::app);
		rec << "T:" << t << " " << "arg1:" << x << " arg2:" << y << " result: " << functor(x, y) << endl;
		rec.close();


	}


};

template<typename arg1, typename arg2>
class F_log<void(*)(), arg1, arg2 >
{
public:
	int t;
	F_log(int t = 0) : t(t) {}

	void log(void(*functor)())
	{


		t += 1;
		functor();
		ofstream rec;
		rec.open("log.txt", ios::app);
		rec << "T:" << t << " " << "no arg " << "no result" << endl;
		rec.close();

	}


};

template<typename arg1, typename arg2>
class F_log<void(*)(arg1), arg1, arg2 >
{
public:
	int t;
	F_log(int t = 0) : t(t) {}

	void log(void(*functor)(arg1), arg1 x)
	{

		t += 1;
		functor(x);
		ofstream rec;
		rec.open("log.txt", ios::app);
		rec << "T:" << t << " " << "no arg " << "no result" << endl;
		rec.close();



	}
	void log(void(*functor)(arg1), arg1 x, arg2 y)
	{

		t += 1;
		ofstream rec;
		rec.open("log.txt", ios::app);
		rec << "T:" << t << " " << "arg1:" << x << " arg2:" << y << " no result" << endl;
		rec.close();


	}
};

template<typename arg1, typename arg2>
class F_log<void(*)(arg1, arg2), arg1, arg2 >
{
public:
	int t;
	F_log(int t = 0) : t(t) {}
	void log(void(*functor)(arg1, arg2), arg1 x, arg2 y)
	{

		t += 1;
		ofstream rec;
		rec.open("log.txt", ios::app);
		rec << "T:" << t << " " << "arg1:" << x << " arg2:" << y << " no result" << endl;
		rec.close();


	}
};


int function_summ(int a = 1, int b = 0)
{

	return a + b;

}

void function_hello()
{
	cout << "Hello" << endl;
}

void function_print_char(char a)
{
	cout << "this char is " << a << endl;
}

string function_char_line(char a)
{
	string result;
	for (int i = 0; i < 4; ++i)
	{
		result += a;
	}
	return result;
}


class functor_one
{
public:
	int value;

	functor_one(int value = 0) : value(value) {}

	int operator()(int x = 2)
	{
		cout << "I am functor_one and my value + argument is " << value + x << endl;
		return (x + value);
	}
};
int main()
{

	functor_one f(7);
	F_log<functor_one> F;
	F_log<void(*)()> V;
	F_log<string(char), char> A;
	F_log<int(int, int)> G;
	F_log<void(*)(char), char> C;

	F.log(f, 3);

	V.log(function_hello);

	A.log(function_char_line, 'r');

	G.log(function_summ, 2, 3);

	C.log(function_print_char, 'C');





	return 0;
}