#include <iostream>

using namespace std;

class Implementation {
public:
	virtual ~Implementation() {}
	virtual void Interaction() {};
	
};

class Player_Implementation : public Implementation
{
	void Interaction() override
	{
		cout << "You have access to:" << endl;
		cout << "1. Move" << endl;
		cout << "2. Open inventory" << endl;
		cout << "3. Perform attack" << endl;
		cout << "4. Perform special" << endl;
	}
	
};

class NPC_Implementation : public Implementation
{
	void Interaction() override
	{
		cout << "You have access to:" << endl;
		cout << "1. Talk" << endl;
		cout << "2. Trade" << endl;
		cout << "3. Recruit" << endl;
		cout << "4. Rob" << endl;

	}
};

class Character {
protected:
	Implementation* imp;
public:
	Character(Implementation* imp) : imp(imp) {}
	virtual ~Character(){}

	virtual void Interactive()
	{
		cout << "For this Character ";
		this->imp->Interaction();
	}
};
void Client_Interaction(Character ch)
{
	ch.Interactive();
}
int main()
{
	Implementation* npc_imp = new NPC_Implementation();
	Character Sylvanas =  Character(npc_imp);
	Client_Interaction(Sylvanas);
	
	Implementation* pl_imp = new Player_Implementation();
	Character Anduin = Character(pl_imp);
	Client_Interaction(Anduin);

	return 0;
}