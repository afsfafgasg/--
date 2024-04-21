/*計算出買不同大小的披薩需要多少錢*/
#include <iostream>
#include <cstdlib>
using namespace std;
class pizza {
public:
	void outputDescription();
	double computerPrice();
	int gettype();
	int getsize();
	int gettopping();
	int gettoppingnumber();
	void set(int t,int s,int p,int n);
private:
	int type;
	int size;
	int topping;
	int toppingnumber;
};
int main(void) {
	pizza customer;
	cout << "Your pizza!" << endl;
	customer.outputDescription();
	cout << "The total price is " << customer.computerPrice() << " dollar" << endl;
	return 0;
}
void pizza::outputDescription() {
	cout << "Please enter the type=>";
	cout << "(1.deep dish 2.hand tossed 3.pan)" << endl;
	cout << "please enter the size=>";
	cout << "(1.small 2.medium 3.large)" << endl;
	cout << "Please enter the topping";
	cout << "(1.pepperoni 2.cheese)"<< endl;
	cout << "--------------------------------------\n";
}
double pizza::computerPrice() {
	int price=0;
	cout << "Choose the type of your pizza>";
	cin >> type;
	cout << "Choose the size of your pizza>";
	cin >> size;
	if (size == 1) {
		price = 10;
	}
	else if (size == 2) {
		price = 14;
	}
	else if (size == 3) {
		price = 17;
	}
	cout << "Choose the one topping=>" << endl;
	cin >> topping;
	cout << "How many the toppingnumber you want=>" << endl;
	cin >> toppingnumber;
	return (price += 2 * toppingnumber);
	if (type > 3 || type < 1 || size>3 || size < 1 || topping>2 || topping < 1 || toppingnumber < 1) {
		cout << "Your input is wrong!";
		exit(1);
	}
}
int pizza::gettype() {
	return type;
}
int pizza::getsize() {
	return size;
}
int pizza::gettopping() {
	return topping;
}
int pizza::gettoppingnumber() {
	return toppingnumber;
}
void pizza::set(int t, int s, int p, int n) {
	if (t <= 3 && t > 1) {
		type = t;
	}
	else {
		cout << "your input is wrong!"<<endl;
		exit(1);
	}
	if (s <= 3 && t > 1) {
		size = s;
	}
	else {
		cout << "your input is wrong!" << endl;
		exit(1);
	}
	if (p < 2 && p >= 1) {
		topping = p;
	}
	else {
		cout << "your input is wrong!" << endl;
		exit(1);
	}
	if (n > 0) {
		toppingnumber = n;
	}
	else {
		cout << "your input is wrong!" << endl;
		exit(1);
	}
}