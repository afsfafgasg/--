/*隨機產生10個值，當成代表PIN的數字，並讓使用者輸入數字，看有沒有符合*/
#include <iostream>
#include <ctime>
using namespace std;
int main(void) {
	int number[10];
	int input_number[5];
	int determine=1;
	srand(time(NULL));
	cout << "PIN: 0  1  2  3  4  5  6  7  8  9  " <<endl;
	cout << "NUM: ";
	for (int i = 0; i < 10; i++) {
		number[i] = rand() % 3 + 1;
		cout << number[i]<<"  ";
	}
	cout << endl;
	cout << "Please enter five digit from(00000-99999)=>" << endl;
	for (int i = 0; i < 4; i++) {
		cin >> input_number[i];
	}
	for (int i = 0; i < 4; i++) {
		if (input_number[i] == number[i]) {
		}
		else {
			determine = 0;
			break;
		}
	}
	if (determine == 1) {
		cout << "Your input number is correctly matches the PIN number!!" << endl;
	}
	else {
		cout << "Your enter number is wrong!"<<endl;
	}
	system("pause");
	return 0;
}