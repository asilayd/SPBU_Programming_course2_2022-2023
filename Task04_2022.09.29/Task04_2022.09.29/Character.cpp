#include <iostream>
#include "Character.h"
#include <string>

using namespace std;

bool Character::CheckMana(int r)
{
	if (mana >= r)
	{
		return true;
	}
	return false;
}

int Character::GetMana()
{
	return mana;
}

int Character::GetStr()
{
	return str;
}


void Character::TakeDamage(int d)
{
	health -= d;
	if (health <= 0)
	{
		cout << "Attack was deadly!" << endl;

	}
}

void Character::HealDamage(int h)
{
	health += h;
}

void Character::SpendMana(int p)
{
	mana -= p;
}



Character::Character(string race = "Human", int health = 10, int mana = 10, int str = 2)
{
	this->race = race;
	this->health = health;
	this->mana = mana;
	this->str = str;

}
Character::Character(const Character& character) :race(character.race), health(character.health), mana(character.mana), str(character.str) {}

Character::~Character() {}


Hero::Hero(string race, int health, int mana, int str) : Character(race, health, mana, str) {}

Hero::~Hero() {}

void Hero::GetInfo()
{
	cout << "this character is Hero" << endl;
	Character::GetInfo();
}


void Character::GetInfo()
{
	cout << "race: " << this->race << endl;
	cout << "HP: " << this->health << endl;
	cout << "mana: " << this->mana << endl;
	cout << "strenght " << this->str << endl;
}

void Character::Attack(Character& target, int modifer)
{
	target.TakeDamage(str + modifer);
}

void Character::Special()
{
	cout << "this character has no special" << endl;
}

Enemy::Enemy(string race, int health, int mana, int str) :Character(race, health, mana, str) {}

Enemy::~Enemy()
{
}

Boss::Boss(string race, int health, int mana, int str) :Enemy(race, health, mana, str) {}

Boss::~Boss()
{
}

void Enemy::GetInfo()
{
	cout << "~~~~" << endl;
	cout << "THIS IS ENEMY!" << endl;
	Character::GetInfo();
	cout << "~~~~" << endl;
}

void Boss::GetInfo()
{
	cout << "~~~~" << endl;
	cout << "THIS IS BOSS!!!" << endl;
	Character::GetInfo();
	cout << "~~~~" << endl;
}

void Boss::Special()
{
	HealDamage((GetMana() / 2) * 5);
	SpendMana(GetMana() / 2);


}

Warrior::Warrior(string race, int health, int mana, int str) :Hero(race, health, mana, str) {
	extra_str = 0;
}

Warrior::~Warrior() {}

void Warrior::Smash(Character& target)
{
	cout << "Warrior attack with " << GetStr() + extra_str << " strenght!" << endl;
	Attack(target, extra_str);
}

void Warrior::Special()
{
	if (CheckMana(1)) {
		SpendMana(1);
		cout << "Special ability Battle Cry! This Warrior extra strenght is " << ++extra_str << " now" << endl;
	}
	else
	{
		cout << "not enough mana" << endl;
	}
}

Mage::Mage(string race, int health, int mana, int str) :Hero(race, health, mana, str)
{
}

Mage::~Mage()
{
}

void Mage::Special()
{
	SpendMana(-GetStr());

}



void Mage::FireBall(int val, Character& target)
{
	if (CheckMana(val))
	{
		cout << "Casting FIREBALL!" << endl;
		SpendMana(val);
		Attack(target, val - GetStr());
	}
	else
	{
		cout << "not enough mana" << endl;
	}
}

Priest::Priest(string race, int health, int mana, int str) :Hero(race, health, mana, str)
{
}

Priest::~Priest()
{
}

void Priest::Healing(Character& target)
{
	if (CheckMana(2)) {
		cout << "Healing!" << endl;
		SpendMana(2);
		target.HealDamage(5);
	}
	else
	{
		cout << "not enough mana" << endl;
	}
}

void Priest::Special(int val)
{
	if (CheckMana(val)) {
		cout << "I will not die!" << endl;
		SpendMana(val);
		HealDamage(val);
	}
	else
	{
		cout << "not enough mana" << endl;
	}
}
