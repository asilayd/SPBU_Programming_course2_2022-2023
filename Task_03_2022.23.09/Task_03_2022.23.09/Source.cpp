#include<iostream>
#include"Quaternion.h"

using namespace std;

int main()
{
	Quaternion tester = Quaternion(1, -1, 1, -1);
	Quaternion fester = Quaternion(2, 2, 1, 3);

	cout << fester << endl;
	cout << tester * fester << endl;
	
	Quaternion kester = tester;
	
	kester += tester;
	cout << kester << endl;
	kester -= tester;
	cout << kester << endl;

	kester *= tester;
	cout << kester << endl;

	kester /= tester;
	cout << kester << endl;
	
	return 0;
}