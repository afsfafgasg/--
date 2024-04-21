/*use class that to know different hot dog standid and 
how many hot dog they sold */
#include <iostream>
using namespace std;
class HotDogStand {
public:
	HotDogStand(int number,int sold);
	HotDogStand();
	void justsold();
	void setInfo();
	int getCurrentId();
	int getNumberSold();
	void display();
	void tally();
	static void updateTotalSold();
	static int getTotalSold();

private:
	int id, numbersold;
	static int totalSold;
};
int HotDogStand::totalSold=0;
int main(void) {
	HotDogStand stand1, stand2, stand3(3,10);
	stand1.display();
	stand1.justsold();
	stand1.tally();
	stand1.display();

	stand2.display();
	stand2.justsold();
	stand2.justsold();
	stand2.tally();
	stand2.display();

	stand3.display();
	stand3.tally();

	cout << "The total Hot dog sold from all stand is " << HotDogStand::getTotalSold() << endl;
	return 0;
}
HotDogStand::HotDogStand(int number, int sold)
	:id(number), numbersold(sold){}
HotDogStand::HotDogStand() 
	:id(0),numbersold(0){
	setInfo();
}
void HotDogStand::setInfo() {
	int standid = -1, sold = -1;
	while (standid < 0) {
		cout << "Please enter the stand id(starts at 0 and beyond)";
		cin >> standid;
	}
	id = standid;
	while (sold < 0) {
		cout << "Enter number of hot dogs SOLD today by STAND) "<<standid<<":";
		cin >> sold;
	}
	numbersold = sold;
}
void HotDogStand::justsold() {
	cout << "Sold" << endl;
	numbersold += 1;
}
int HotDogStand::getCurrentId() {
	return id;
}
int HotDogStand::getNumberSold() {
	return numbersold;
}
void HotDogStand::updateTotalSold() {
	totalSold += 1;
}
int HotDogStand::getTotalSold() {
	return totalSold;
}
void HotDogStand::display() {
	cout << "STAND:" << id << endl;
	cout << "Hot dog sold:" << numbersold << endl;
}
void HotDogStand::tally() {
	for (int i = 0; i < numbersold; i++) {
		HotDogStand::updateTotalSold();
	}
}