#include<iostream>
#include<string>



using std::cout;
using std::string;
using std::endl;

class X {
	bool t;      //
	double c;    //
	char b;      //
	long long u; //the most effective arrangement of bool and char since they occupy 8 each in this way  --- 32 total
	int a;       //
	char d[10];  //alternating further variables will not allow you to go further than 56 
	long f;      //(their sum is 20 and when rounded to the  nearest multiple of 8, 24 will come out, 
	short k;     //which means the result 32+24 = 56 is the maximum)
};
class Y {
	short k;    //the rationale for the minimum is simpler
	char b;     //the sum of all variables is 38, 
	char d[10]; //rounding will occur to a multiple of 8, that is, it is impossible to get a size below 40
	bool t;
	int a;
	long f;
	double c;
	long long u;
};

int main()
{
	int sizes[8];
	sizes[0] = sizeof(int);
	sizes[1] = sizeof(char);
	sizes[2] = sizeof(char[10]);
	sizes[3] = sizeof(double);
	sizes[4] = sizeof(long);
	sizes[5] = sizeof(long long);
	sizes[6] = sizeof(short);
	sizes[7] = sizeof(bool);
	for (int i = 0; i < 8; ++i) {
		cout << (sizes[i]) << endl;

	}

	cout << endl;
	
	X first;
	Y second;

	cout << sizeof(first) << endl;
	cout << sizeof(second) << endl;

	return EXIT_SUCCESS;
	
}