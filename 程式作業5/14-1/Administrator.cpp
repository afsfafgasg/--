#include "administrator.h"
#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::getline;
using std::cin;
using std::endl;

namespace SavitchEmployees {

    Administrator::Administrator() : SalariedEmployee(), title(""), area(""), supervisor(""), annualSalary(0) {}

    Administrator::Administrator(const string& theName, const string& theSsn, double theWeeklySalary,
        const string& theTitle, const string& theArea, const string& theSupervisor, double theAnnualSalary)
        : SalariedEmployee(theName, theSsn, theWeeklySalary), title(theTitle), area(theArea), supervisor(theSupervisor), annualSalary(theAnnualSalary) {}

    void Administrator::setSupervisor(const string& newSupervisor) {
        supervisor = newSupervisor;
    }

    void Administrator::setTitle(const string& newTitle) {
        title = newTitle;
    }

    void Administrator::setArea(const string& newArea) {
        area = newArea;
    }

    void Administrator::setAnnualSalary(double newAnnualSalary) {
        annualSalary = newAnnualSalary;
    }

    void Administrator::readData() {
        string theName, theSsn, theTitle, theArea, theSupervisor;
        double theWeeklySalary, theAnnualSalary;

        cout << "Please enter the administrator's name: ";
        getline(cin, theName);
        cout << "Please enter the administrator's social security number (SSN): ";
        getline(cin, theSsn);
        cout << "Please enter the administrator's weekly salary: ";
        cin >> theWeeklySalary;
        cout << "Please enter the administrator's annual salary: ";
        cin >> theAnnualSalary;
        cin.ignore(); // Ignore the newline character in the input buffer
        cout << "Please enter the administrator's title: ";
        getline(cin, theTitle);
        cout << "Please enter the company area of responsibility: ";
        getline(cin, theArea);
        cout << "Please enter the name of the immediate supervisor: ";
        getline(cin, theSupervisor);

        setName(theName);
        setSsn(theSsn);
        setSalary(theWeeklySalary); // Call the base class setSalary function
        annualSalary = theAnnualSalary;
        title = theTitle;
        area = theArea;
        supervisor = theSupervisor;
    }

    void Administrator::print() const {
        cout << "Administrator's name: " << getName() << endl;
        cout << "Social Security Number (SSN): " << getSsn() << endl;
        cout << "Annual salary: " << annualSalary << endl;
        cout << "Title: " << title << endl;
        cout << "Company area of responsibility: " << area << endl;
        cout << "Immediate supervisor's name: " << supervisor << endl;
    }
    void Administrator::printCheck(double bonus) const {
        double totalSalary = annualSalary + bonus;
        cout << "Pay to the order of " << getName() << endl;
        cout << "The sum of " << totalSalary << " Dollars" << endl;
        cout << "Check Stub: Not negotiable" << endl;
        cout << "Employee number: " << getSsn() << endl;
        cout << "Salaried Employee. Regular pay." << endl;
        cout << "Title: " << title << endl;
        cout << "Company area of responsibility: " << area << endl;
        cout << "Immediate supervisor's name: " << supervisor << endl;
    }
} // namespace SavitchEmployees
