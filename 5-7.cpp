/*使用者輸入十個人的成績，並利用陣列存取，再把每個區間有幾人表示出來*/
#include <iostream>
#include <string>
using namespace std;
int main(void) {
	int input_number[10] = { 0 };
	int grade[6] = { 0 };
	cout << "Please enter the grade(you need to enter 10 number)=>";
	for (int i = 0; i < 10; i++) {
		cin >> input_number[i];
	}
	for (int i = 0; i < 10; i++) {
		switch (input_number[i]) {
		case 0:
			grade[0]++;
			break;
		case 1:
			grade[1]++;
			break;
		case 2:
			grade[2]++;
			break;
		case 3:
			grade[3]++;
			break;
		case 4:
			grade[4]++;
			break;
		case 5:
			grade[5]++;
			break;
		default:
			cout << "Invalid grade entered." << endl;
			break;
		}
	}
	for (int i = 0; i < 6; i++) {
		cout << "Grade " << i << ": " << grade[i] << endl;
	}
	system("pause");
	return 0;
}
