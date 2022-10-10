#pragma once
#include <iostream>
#include <string>

using namespace std;


class Character {

private:

	string race;
	int health;
	int mana;
	int str;
	

	

protected:
	bool CheckMana(int r);
	int GetMana();
	int GetStr();
	
	void TakeDamage(int d);
	void SpendMana(int p);
public:
	
	
	Character(string race , int health, int mana, int str);
	Character(const Character& character);
	~Character();
	 
	virtual void GetInfo();
	void Attack(Character& target, int modifer=0);
	virtual void Special();

	void HealDamage(int h);
	

};




class Hero : public Character {

public:
	Hero(string race, int health, int mana, int str);
	~Hero();
	void GetInfo() override;
};

class Warrior : public Hero {
private:
	
	int extra_str;

public:
	Warrior(string race, int health, int mana, int str);
	~Warrior();
	void Smash(Character& target);
	void Special() override;

};

class Mage : public Hero {
public:
	Mage(string race, int health, int mana, int str);
	~Mage();
	void Special() override;
	void FireBall(int val, Character& target);
	
};

class Priest : public Hero {

public:
	Priest(string race, int health, int mana, int str);
	~Priest();
	void Healing(Character& target);
	void Special(int val);
};

class Enemy : public Character {
public:
	Enemy(string race, int health, int mana, int str);
	~Enemy();
	void GetInfo() override;
};

class Boss : public Enemy {
public:
	Boss(string race, int health, int mana, int str);
	~Boss();
	void GetInfo();
	void Special() override;
};
