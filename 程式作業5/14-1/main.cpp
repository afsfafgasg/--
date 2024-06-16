#include <iostream>
#include "administrator.h"

using namespace std;
using namespace SavitchEmployees;

int main() {
    Administrator salary;
    double bonus = 5000;
    salary.readData();
    salary.print();
    salary.printCheck(bonus);
    return 0;
}
