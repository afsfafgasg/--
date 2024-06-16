#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Dice{
public:
	Dice();
	Dice(int numSides);
	virtual int rollDice()const;
protected:
	int numSides;
};
Dice::Dice()
{
	numSides = 6;
	srand(time(NULL)); // Seeds random number generator
}
Dice::Dice(int numSides)
{
	this->numSides = numSides;
	srand(time(NULL)); // Seeds random number generator
}
int Dice::rollDice()const
{
	return (rand() % numSides) + 1;
}
// Take two dice objects, roll them, and return the sum
int rollTwoDice(const Dice& die1, const Dice& die2)
{
	return die1.rollDice() + die2.rollDice();
}
class loadedDice :public Dice{
public:
	loadedDice();
	loadedDice(int numSides);
	virtual int rollDice() const override;
};
loadedDice::loadedDice():Dice(){
}
loadedDice::loadedDice(int numSides):Dice(numSides) {
}
int loadedDice::rollDice() const {
	if (rand() % 2 == 0) {
		return numSides; //it has 50% to return maximum number
	}
	else {
		return Dice::rollDice();
	}
}
int main(void) {
	Dice dice1(6), dice2(6);
	cout << "Rolling ten times dice object:" << endl;
	for (int i = 1; i < 11; i++) {
		cout << "Roll " << i << ": " << rollTwoDice(dice1, dice2) << endl;
	}
	loadedDice dice3(6), dice4(6);
	cout << "Rolling ten times loadedDice object:" << endl;
	for (int i = 1; i < 11; i++) {
		cout << "Roll " << i << ": " << rollTwoDice(dice3, dice4) << endl;
	}
	return 0;
}