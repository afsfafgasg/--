/*this program is to change different weight scales*/
#include <iostream>
using namespace std;
class Weight{
public:
    void setWeightPounds(double pounds) {
        this->pound=pounds;
    }
    void setWeightKilograms(double kilograms) {
        this->pound = kilograms/ 0.453592;
    }
    void setWeightOunces(double ounces) {
        this->pound = ounces/16;
    }
    double getWeightPound() const{
        return pound;
    }
    double getWeightkilogram() const {
        return pound* 0.453592;
    }
    double getWeightOunce() const {
        return pound*16;
    }
private:
    double pound;
};

int main(void) {
    Weight weight;
    weight.setWeightPounds(100.0);
    cout << "The weigh in pounds: " << weight.getWeightPound() << endl;
    cout << "The weigh in kilograms: " << weight.getWeightkilogram() << endl;
    cout << "The weigh in ounces: " << weight.getWeightOunce() << endl;
    weight.setWeightKilograms(200.0);
    cout << "The weigh in pounds: " << weight.getWeightPound() << endl;
    cout << "The weigh in kilograms: " << weight.getWeightkilogram() << endl;
    cout << "The weigh in ounces: " << weight.getWeightOunce() << endl;
    weight.setWeightOunces(300.0);
    cout << "The weigh in pounds: " << weight.getWeightPound() << endl;
    cout << "The weigh in kilograms: " << weight.getWeightkilogram() << endl;
    cout << "The weigh in ounces: " << weight.getWeightOunce() << endl;
	return 0;
}