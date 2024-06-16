#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "salariedemployee.h"
#include <string>

namespace SavitchEmployees {

    class Administrator : public SalariedEmployee {
    public:
        Administrator();
        Administrator(const string& theName, const string& theSsn, double theWeeklySalary,
            const string& theTitle, const string& theArea, const string& theSupervisor, double theAnnualSalary);
        void setTitle(const string& newTitle);
        void setArea(const string& newArea);
        void setSupervisor(const string& newSupervisor);
        void setAnnualSalary(double newAnnualSalary);
        void readData();
        void print() const;
        void printCheck(double bonus) const;


    protected:
        string title;
        string area;
        string supervisor;
        double annualSalary;
    };

} // namespace SavitchEmployees

#endif // ADMINISTRATOR_H

