#include <iostream>
#include <memory>

using namespace std;

int main()
{
	int* p1 = new int(2);
	int* p2 = p1;
	cout << *p1 << endl;
	delete p1;  
	cout << *p2 << endl; //due to the fact that p1 was deleted here we get something incomprehensible
	//delete p2;  ...and if we want to free up p2 memory, we will get an error
	// 
	//thanks to auto_ptr, the following entry is possible
	auto_ptr<int> pointer_1(new int(1));
	auto_ptr<int> pointer_2(pointer_1); //after this pointer_1 is empty and only pointer_2 indicates the object


	unique_ptr<int> ptr1(new int(23));
//  unique_ptr<int> ptr2(ptr1);  ...   in the case of unique_ptr
	///such a record is not possible at all(and this may be useful)
	unique_ptr<int> ptr2;

	ptr2 = move(ptr1); //using move we get the result identical to auto_ptr
	//but also we can do this:
	ptr2.swap(ptr1);//and in that case ptr1 will not be empty (if move was not using before swap)

	p1 = new int(2);
	unique_ptr<int> ptr3(p1); //passed the usual pointer to unique_ptr
	ptr3.reset(); // the data on the link p1 will be cleared and ptr3 will be empty
	//ptr3.release() 
	//if you use release instead of reset, then nothing will happen to p1, but ptr3 will be empty
    
	//to conveniently work with multiple pointers to a single object, you can use shared_ptr

	shared_ptr<int> sp1(new int(7));
	shared_ptr<int> sp2(sp1);
	//the data itself will be destroyed only when the last shared_ptr pointing to this object is destroyed
	//therefore, we can set any number of pointers to the same object without worrying about whether 
	//the memory will be released correctly at the end of the program
	return 0;
}