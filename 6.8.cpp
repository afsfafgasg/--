/* test program that creates and output a description and price of
various pizza object*/
#include <iostream>
using namespace std;
class money {
public:
	void inputdata();
	int getdollar();
	int getcent();
	void set(int dollars, int cents);
private:
	int dollar;
	int cent;
};
int main(void) {
	money amount;
	amount.inputdata();
	cout << "Money 1"<<endl;
	cout << "You have the " << amount.getdollar() << " dollar and " << amount.getcent() << " cent" << endl;
	amount.set(200, 20);
	cout << "Money 2"<<endl;
	cout << "You have the " << amount.getdollar() << " dollar and " << amount.getcent() << " cent" << endl;
	return 0;
}
void money::inputdata() {
	cout << "Please enter the total dollar you have=>" << endl;
	cin >> dollar;
	cout << "Please enter the total cent you have=>" << endl;
	cin >> cent;
}
int money::getdollar() {
	return dollar;
}
int money::getcent() {
	return cent;
}
void money::set(int dollars, int cents) {
	if (dollars > 0) {
		dollar = dollars;
	}
	else{
		cout << "your input is wrong!" <<endl ;
		exit(1);
	}
	if (cents > 0) {
		cent = cents;
	}
	else {
		cout << "your input is wrong!" << endl;
		exit(1);
	}
}