/*change the number to zipcode or change the string to number*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class ZipCode {
public:
	ZipCode(int);
	ZipCode(string);
	int getZipNumber(int);
	string getZipString();
	

private:
	string code;
	int value[5] = { 7,4,2,1,0 };
	void ConvertToString(int);
	int ConvertToInteger();
};
int main(void) {
	ZipCode code1(99504);
	cout << "1" + code1.getZipString() + "1" << endl;
	ZipCode code2(92627);
	cout << "1" + code2.getZipString() + "1" << endl;
	ZipCode code3("1010010100010101100001001");
	cout << endl;
	ZipCode code4("0101000101011000010110001");
	cout << endl;


	return 0;
}
ZipCode::ZipCode(int input) 
{
	cout << "ZIP code:" << input << endl;
	ConvertToString(input);
}
ZipCode::ZipCode(string input) :code(input) 
{
	cout << "POST NET code:" << "1" + input +"1" << endl;
	cout << getZipNumber(ConvertToInteger());
}
void ZipCode::ConvertToString(int input) 
{
	int brokencode[5] = { 0 };
	int remainder = 0;
	char stringofline[25] = {0};
	int index = 0;
	bool flag = false;

	for (int i = 0; i < 5; i++) 
	{
		remainder = input % static_cast<int>(pow(10, (4 - i)));
		brokencode[i] = input / (pow(10, (4 - i)));
		input = remainder;
	}
	int carryon = 0;
	while (index < 5) 
	{
		for (int i = 0; i < 5; i++) 
		{
			for (int j = i + 1; j < 5; j++) 
			{
				if ((value[i] + value[j] == brokencode[index]) || ((value[i] + value[j] == 11) && brokencode[index] == 0)) 
				{
					stringofline[i + carryon] = '1';
					stringofline[j + carryon] = '1';
					flag = true;
					break;
				}
			}
			if (flag == true) 
				break;
			
		}
		flag = false;
		for (int i = 0; i < 5; i++) 
		{
			if (stringofline[i + carryon] != '1') {
				stringofline[i + carryon] = '0';
			}
		}
		index += 1;
		carryon += 5;
	}
	for (int i = 0; i < 25; i++) {
		code += stringofline[i];
	}
	
}
int ZipCode::ConvertToInteger() {
	int decode = 0;
	int toadd = 0;
	for (int i = 0, k = 0; i < 25; i += 5, k++) 
	{
		for (int j = 0; j < 5; j++) 
		{
			if (code[i + j] == '1') {
				toadd += value[j];
			}
			if (toadd == 11) {
				toadd = 0;
			}
		}
		decode += toadd * (pow(10, (4) - k));
		toadd = 0;
	}
	return decode;
}
string ZipCode::getZipString() {
	cout << "The zip code encoded is: ";
	return code;
}
int ZipCode::getZipNumber(int decodedString) {
	cout << "The zip code decoded is: ";
	return decodedString;
}
