#include <iostream>

using namespace std;

int main()
{
	/*
	                               //1. do we reduce the type of object a to an integer 
	                                    or is the operator = defined in some other way, which makes the entry a = 42 legal? 
	....                                    //2. is the < operator defined for 
	for (a = 42; a < 146; ++a)           an object of type a and does it return bool (true or false)
	{							         //3. is the increment defined for object type a and does it affect the result of 
		if (++b + a == c) return b;      the comparison operator < (that is, will we avoid an infinite loop)
		c += a;                       //4. is the increment defined for b and is it possible for the + operator to work
	}                               //  with the result of ++b and an object of type a
	....                       //5. is the comparison operator == defined for an object of type c as well as an 
	  */                       //object that is the result of the + operator for type ++b and object type a
	                           //6.in which part of the program is this code defined? can it return an object 
	                           //of type b if it is a function or method?
	                          //is the + operator defined between object types a and c
	return 0;
}