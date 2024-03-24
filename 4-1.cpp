/*這是一個判斷時間是AM還是PM的程式*/
#include <iostream>
using namespace std;
void input_number(int* hour, int* minute);
int conversion(int* hour, int* minute, int* after_convert_time, char* word);
void output_number(int* hour, int* minute, int after_convert_time, char* word);
int main(void) {
	int hour = 0, minute = 0;
	int conver_time = 0;
	char word;
	input_number(&hour, &minute);
	conver_time = conversion(&hour, &minute, &conver_time, &word);
	output_number(&hour, &minute, conver_time, &word);
	system("pause");
	return 0;
}
void input_number(int* hour, int* minute) {
	char symbol;
	cout << "Please input one time like(14:25)=>";
	cin >> *hour >> symbol >> *minute;
}
int conversion(int* hour, int* minute, int* after_convert_time, char* word) {
	if (*hour > 12) {
		*after_convert_time = *hour - 12;
		*word = 'P';
		return *after_convert_time;
	}
	else {
		*word = 'A';
	}
	return *hour;
}
void output_number(int* hour, int* minute, int after_convert_time, char* word) {
	if (*word == 'P') {
		cout << "Now the time is " << after_convert_time << ":" << *minute << "P.M" << endl;
	}
	else if (*word == 'A') {
		cout << "Now the time is " << *hour << ":" << *minute << "A.M" << endl;
	}
	else {
		cout << "Not found" << endl;
	}
}
