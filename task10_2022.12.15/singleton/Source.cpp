#include <iostream>

using namespace std;

class Player {
public:
	int str;
	Player(int s) : str(s){}

};

class Singleton_score_table
{
protected:

	static Singleton_score_table* p_instance;
	Singleton_score_table()
	{
		for (int i = 0; i < 10; ++i)	table[i] = 0;
	}
	

public:
	
	int table[10];
	static Singleton_score_table* getInstance();

	Singleton_score_table(const Singleton_score_table&) = delete;
	Singleton_score_table& operator=(Singleton_score_table&) = delete;



};

Singleton_score_table* Singleton_score_table::p_instance = nullptr;

Singleton_score_table* Singleton_score_table::getInstance()
{
	if (p_instance == nullptr)
		p_instance = new Singleton_score_table;
	return p_instance;
}

int main()
{
	Player pl_1(2);
	Player pl_2(4);
	Player pl_3(5);

	Singleton_score_table* players_table = Singleton_score_table::getInstance();
	
	if (pl_1.str > pl_2.str) { players_table->table[0] += 1; }
	else if(pl_1.str < pl_2.str) { players_table->table[1] += 1; }
	return 0;
}