/*這是一個判斷英里的轉換器，使用者能直接輸入英里也能輸入公里*/
#include <iostream>
using namespace std;
double convertToMPH(int first_integer, int second_integer);
double convertToMPH(double kph);
int main(void) {
	int num, minute, second;
	double kph;
	cout << "1:Pace(x:xx mile)  2:Kilometers per hour(kph)"<<endl;
	cout << "Please choose which one you want=>";
	cin >> num;
	if (num == 1) {
		cout << "Enter the Pace(x:xx mile)=>";
		cin >> minute >> second;
		cout << "Your speed is " << convertToMPH(minute, second)<<" miles per hour"<<endl;
	}
	else if (num == 2) {
		
		cout << "Enter the Kilometers per hour(kph)=>";
		cin >>kph;
		cout << "Your speed is " << convertToMPH(kph) << " miles per hour" << endl;
	}
	system("pause");
	return 0;
}
double convertToMPH(int first_integer, int second_integer) {
	double mps;
	mps = ((first_integer * 60) + second_integer) / 3600.0;
	return (1/mps);
}
double convertToMPH(double kph) {
	return (kph / 1.61);
}