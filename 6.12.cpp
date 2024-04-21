/*this program need to read data from text¡Aand let user to 
selection different fruit if you want to change*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class BoxOfProduce {
public:
    void initbox(string[],BoxOfProduce[]);
    void output(BoxOfProduce deliver[]);
    void setbox(BoxOfProduce[], string[]);
private:
    string word="";

};
void readword(string[]);
void displaylist(string[]);

int main(void) {
    srand(time(NULL));
    BoxOfProduce box[3];
    string selection[5];
    char ans = '\0';
    readword(selection);
    box[3].initbox(selection,box);
    do {
        box[3].output(box);
        box[3].setbox(box, selection);
        box[3].output(box);
        cout << "Would you want to change the box one time(if yes enter(Y or y)=>): ";
        cin >> ans;
        cout << endl;
    } while (ans == 'Y' || ans == 'y');
    cout << "Your final table is=>" << endl;
    box[3].output(box);
    return 0;
}
void readword(string readlist[5]) {
    fstream inputdata;
    string text="";
    int numberused = 0;
    inputdata.open("list.txt");
    while (inputdata >> text) {
        readlist[numberused] = text;
        numberused += 1;
    }

}
void displaylist(string readlist[5]) {
    for (int i = 0; i < 5; i++) {
        cout << readlist[i] << ":" << i << " ";
    }
    cout << endl;
}
void BoxOfProduce::initbox(string readtofile[5], BoxOfProduce store[3]) {
    for (int i = 0; i < 3; i++) {
        store[i].word = readtofile[rand() % (5-1)];
    }
}
void BoxOfProduce::output(BoxOfProduce deliver[]) {
    cout << "Your box current contains:" << endl;
    for (int i = 0; i < 3;i++) {
        cout << deliver[i].word << ":" << i <<" ";
    }
    cout << endl;
}
void BoxOfProduce::setbox(BoxOfProduce box[], string selection[]) {
    int tochange = 0;
    int changewith = 0;
    cout << "If you want to switch the number,enter the number it corrsspond: "<<endl;
    cin >> tochange;
    if (tochange >= 3 || tochange < 0) {
        cout << "Your input number is wrong" << endl;
        exit(1);
    }
    displaylist(selection);
    cout << "\nChange with?" << endl;
    cin >> changewith;
    switch (changewith) {
    case(0):
        box[tochange].word = selection[changewith];
        break;
    case(1):
        box[tochange].word = selection[changewith];
        break;
    case(2):
        box[tochange].word = selection[changewith];
        break;
    case(3):
        box[tochange].word = selection[changewith];
        break;
    case(4):
        box[tochange].word = selection[changewith];
        break;
    default:
        cout << "Your input is wrong!" << endl;
    }
}


