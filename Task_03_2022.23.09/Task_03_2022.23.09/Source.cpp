#include<iostream>
#include"Quaternion.h"

using namespace std;

void main()
{
	Quaternion tester = Quaternion(1, -1, 1, -1);
	Quaternion fester = Quaternion(2, 2, 1, 3);
	(tester*fester).print();
}