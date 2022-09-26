#include <iostream>
#include "Array.h"

using namespace std;

int main(int argc, char* argv[])
{
	Array tester = Array(4);
	Array vester = Array(8);
	
	for (int i = 0; i < 4; ++i)
	{
		tester.Set(i, rand() % 100);
	}
	
	for (int i = 0; i < 8; ++i)
	{
		vester.Set(i, rand() % 100);
	}
	
	for (int i = 0; i < 4; ++i)
	{
		cout << tester.Get(i) << endl;
	}
	cout << endl;
	
	for (int i = 0; i < 8; ++i)
	{
		cout << vester.Get(i) << endl;
	}
	
	cout << endl;
	
	tester = vester;
	
	for (int i = 0; i < 8; ++i)
	{
		cout << tester.Get(i) << endl;
	}
	cout << endl;
	
	for (int i = 0; i < 8; ++i)
	{
		cout << vester.Get(i) << endl;
	}


	return EXIT_SUCCESS;
}