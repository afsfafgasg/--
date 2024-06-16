#include <iostream>
#include <string>
#include <ctime>
using namespace std;
class Creature
{
private:
	int type; // 0 human, 1 cyberdemon, 2 balrog, 3 elf
	int strength; // How much damage we can inflict
	int hitpoints; // How much damage we can sustain
public:
	Creature() :type(0), strength(10), hitpoints(10) {}
	// Initialize to human, 10 strength, 10 hit points
	Creature(int newType, int newStrength, int newHit) :type(newType), strength(newStrength), hitpoints(newHit) {}
	virtual string getSpecies() const; // Returns type of species
	virtual int getDamage() const;
	int getType() const { return type; }
	int getStrength() const { return strength; }
	int getHitpoints() const { return hitpoints; }
	void setType(int t) { type = t; }
	void setStrength(int str) { strength = str; }
	void setHitpoints(int hp) { hitpoints = hp; }
};

string Creature::getSpecies()const
{
	switch (type)
	{
	case 0: return "Human";
	case 1: return "Cyberdemon";
	case 2: return "Balrog";
	case 3: return "Elf";
	}
	return "Unknown";
}
int Creature::getDamage()const
{
	int damage;
	// All creatures inflict damage, which is a
	// random number up to their strength
	damage = (rand() % strength) + 1;
	cout << getSpecies() << " attacks for " <<
		damage << " points!" << endl;
	// Demons can inflict damage of 50 with a 5% chance
	if ((type == 2) || (type == 1))
		if ((rand() % 100) < 5)
		{
			damage += 50;
			cout << "Demonic attack inflicts 50 "
				<< " additional damage points!" << endl;
		}
	// Elves inflict double magical damage with a 10% chance
	if (type == 3)
	{
		if ((rand() % 10) == 0)
		{
			cout << "Magical attack inflicts " << damage <<
				" additional damage points!" << endl;
			damage *= 2;
		}
	}
	// Balrogs are so fast they get to attack twice
	if (type == 2)
	{
		int damage2 = (rand() % strength) + 1;
		cout << "Balrog speed attack inflicts " << damage2 <<
			" additional damage points!" << endl;
		damage = damage + damage2;
	}
	return damage;
}
class Demo :public Creature {
public:
	Demo(int str = 10, int hp = 10) :Creature(1, str, hp) {}
	string getSpecies() const override { return "Demon"; }
	int getDamage()const override;
};
int Demo::getDamage()const {
	int damage = Creature::getDamage();
	if ((rand() % 100) < 5) {
		damage += 50;
		cout << "Demonic attack inflicts 50 additional damage points!" << endl;
	}
	return damage;
}
class EIF :public Creature {
public:
	EIF(int str, int hp) :Creature(3, str, hp) {}
	string getSpecies()const override { return "EIF"; }
	int getDamage()const override;
};
int EIF::getDamage()const {
	int damage = Creature::getDamage();
	if ((rand() % 10) == 0) {
		cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
		damage *= 2;
	}
	return damage;
}
class Human :public Creature {
public:
	Human(int str, int hp) :Creature(0, str, hp) {}
	string getSpecies()const override { return "Human"; }
};
class Cyberdemon :public Demo {
public:
	Cyberdemon(int str = 10, int hp = 10) :Demo(str, hp) {
		setType(1);
	}
	string getSpecies()const override { return "Cyberdemon"; }
};
class Balrog :public Demo {
public:
	Balrog(int str = 10, int hp = 10) :Demo(str, hp) {
		setType(2);
	}
	string getSpecies()const override { return "Balrog"; }
	int getDamage()const override;
};
int Balrog::getDamage()const {
	int damage = Demo::getDamage();
	int damage2 = (rand() % getStrength()) + 1;
	cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
	damage += damage2;
	return damage;
}
void battleArena(Creature& creature1, Creature& creature2) {
	cout << "Battle begin between" << creature1.getSpecies() << " and " << creature2.getSpecies() << "!" << endl;
	while (creature1.getHitpoints()>0&&creature2.getHitpoints()>0) {
		int damage1 = creature1.getDamage();
		creature2.setHitpoints(creature2.getHitpoints() - damage1);
		cout << creature2.getSpecies() << " has " << creature2.getHitpoints()<<" hitpoints remaining." << endl;
		if (creature2.getHitpoints() >= 0) {
			cout << creature2.getSpecies() << " has been defeated!" << endl;
			break;
		}
		int damage2 = creature2.getDamage();
		creature1.setHitpoints(creature1.getHitpoints()-damage2);
		cout << creature1.getSpecies() << " has " << creature1.getHitpoints() << " hitpoints remaining." << endl;
		if (creature1.getHitpoints() >= 0) {
			cout << creature1.getSpecies() << " has been defeated!" << endl;
			break;
		}
	}
	if (creature1.getHitpoints() <= 0 || creature2.getHitpoints() <= 0) {
		cout << "The battle between" << creature1.getSpecies() << " and " << creature2.getSpecies() << " is finish!" << endl;
	}
}

int main(void) {
	srand(time(NULL));
	Human h(10, 40);
	Cyberdemon c(15, 40);
	Balrog b(20, 50);
	EIF e(25, 60);
	battleArena(h, c);
	cout << endl;
	battleArena(b, e);
	cout << endl;
	battleArena(h, b);
	cout << endl;
	battleArena(c, e);
	return 0;
}
