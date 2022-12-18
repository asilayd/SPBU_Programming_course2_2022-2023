#include <algorithm>
#include <iostream>
#include <list>
#include <string>


class Item {
protected:
	Item* p;
public:
	virtual ~Item() {}
	void SetP(Item* p) {
		this->p = p;
	}
	virtual void Add(Item* item) {}
	virtual void Remove(Item* item) {}

	virtual int Modificator_value() const = 0;
};

class Rune : public Item {

	int size;
public:
	Rune(int s) : size(s) {}
	int Modificator_value() const override
	{
		return this->size;
	}
};

class Enchantment : public Item {
protected:
	std::list<Item*> spell;
public:

	void Add(Item* item) override {
		this->spell.push_back(item);
		item->SetP(this);

	}
	void Remove(Item* item) override {
		spell.remove(item);
		item->SetP(nullptr);
	}

	int Modificator_value() const override
	{
		int rez = 0;
		for (const Item* i : spell)  rez += i->Modificator_value();
		return rez;
	}
};


int main()
{
	Item* just_rune = new Rune(4);
	std::cout << just_rune->Modificator_value() << std::endl;

	Item* magic_sword = new Enchantment();
	Item* first_rune = new Rune(3);
	Item* second_rune = new Rune(5);
	Item* weak_enchant = new Enchantment();
	Item* weak_first_rune = new Rune(1);
	Item* weak_second_rune = new Rune(1);

	weak_enchant->Add(weak_first_rune);
	weak_enchant->Add(weak_second_rune);

	magic_sword->Add(weak_enchant);
	magic_sword->Add(first_rune);
	magic_sword->Add(second_rune);

	std::cout << magic_sword->Modificator_value();
	return 0;
}