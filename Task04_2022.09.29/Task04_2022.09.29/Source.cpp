#include <iostream>
#include "Character.h"
#include <string>

using namespace std;



int main(int argc, char* argv[]) {
	
	Priest Anduin("Human", 10, 15, 2);
	Warrior Garosh("Ork", 20, 5, 5);
	Mage Jaine("Human", 7, 18, 2);
	
	
	
	Enemy spider("Insect", 10, 10, 2);
	Boss Kel_Thusad("Undead", 100, 20, 5);

	
	Kel_Thusad.Attack(Garosh);
	Garosh.Smash(Kel_Thusad);
	Anduin.Healing(Garosh);
	Jaine.FireBall(4, spider);
	spider.Attack(Jaine);

	Anduin.GetInfo();
	return EXIT_SUCCESS;
};