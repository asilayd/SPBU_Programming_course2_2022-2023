#include <iostream>

using std::cout;
using std::string;
using std::endl;

class C {
	friend class C_friend;
private:
	int x = 0;
	void f()
	{
		cout << this->x << endl;
	}
};
class C_friend
{
public:
	void changeX(C& t, int x)
	{
		t.x = x;
	}
	void copy_f(C t)
	{
		void(C:: * copy_f)() = &C::f;
		(&t->*copy_f)();
	}
};




int main() {

	C tester;
	C_friend imposter;

	imposter.copy_f(tester);
	imposter.changeX(tester, 1);
	imposter.copy_f(tester);

	return EXIT_SUCCESS;
}





