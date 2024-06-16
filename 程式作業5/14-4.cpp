#include <iostream>
#include <string>
using namespace std;

// UniversityStaff class implementation
class UniversityStaff {
public:
    UniversityStaff();
    UniversityStaff(string theName);
    UniversityStaff(const UniversityStaff& theObject);
    string getName() const;
    UniversityStaff& operator=(const UniversityStaff& rtSide);
    friend istream& operator>>(istream& inStream, UniversityStaff& staffObject);
    friend ostream& operator<<(ostream& outStream, const UniversityStaff& staffObject);

private:
    string name;
};
UniversityStaff::UniversityStaff() :name("") {}
UniversityStaff::UniversityStaff(string theName) :name(theName) {}
UniversityStaff::UniversityStaff(const UniversityStaff& theObject) :name(theObject.name) {}
string UniversityStaff::getName() const {
    return name;
}
UniversityStaff& UniversityStaff::operator=(const UniversityStaff& rtSide) {
    if (this != &rtSide) {
        name = rtSide.name;
    }
    return *this;
}
istream& operator>>(istream& inStream, UniversityStaff& staffObject) {
    inStream >> staffObject.name;
    return inStream;
}
ostream& operator<<(ostream& outStream, const UniversityStaff& staffObject) {
    outStream << staffObject.name;
    return outStream;
}
// Base class Student definition
class student {
public:
    student();
    student(string uniname, int regnum, UniversityStaff Procter);
    student(const student& thestudent);
    ~student();

    string getuniversityName() const;
    int getregistrationNumber() const;
    UniversityStaff getprocter() const;

    void setuniversityName(string uniname);
    void setregistrationNumber(int regnum);
    void setprocter(UniversityStaff Procter);
    student& operator=(const student& rtside);
private:
    string universityName;
    int registrationNumber;
    UniversityStaff procter;
};
student::student() :universityName(""), registrationNumber(0), procter() {}
student::student(string uniname, int regnum, UniversityStaff Procter) :universityName(uniname), registrationNumber(regnum), procter(Procter) {}
student::student(const student& thestudent):universityName(thestudent.universityName), registrationNumber(thestudent.registrationNumber), procter(thestudent.procter){}
student::~student() {}

string student::getuniversityName() const {
    return universityName;
}
int student::getregistrationNumber() const {
    return registrationNumber;
}
UniversityStaff student::getprocter() const {
    return procter;
}

void student::setuniversityName(string uniname) {
    universityName = uniname;
}
void student::setregistrationNumber(int regnum) {
    registrationNumber = regnum;
}
void student::setprocter(UniversityStaff Procter) {
    procter = Procter;
}
student& student::operator=(const student& rtside) {
    if (this != &rtside) {
        universityName = rtside.universityName;
        registrationNumber = rtside.registrationNumber;
        procter = rtside.procter;
    }
    return *this;
}
// Derived class ScienceStudent definition
class ScienceStudent : public student {
public:
    ScienceStudent();
    ScienceStudent(string uniname, int regnum, UniversityStaff Procter, string discipaline, string course);
    ScienceStudent(const ScienceStudent& thestudent);
    string getscienceDiscipline();
    string getcourse();
    void setscienceDiscipline(string discipline);
    void setcourse(string Course);
    ScienceStudent& operator=(const ScienceStudent& rtside);
private:
    string scienceDiscipline;
    string course;
};
ScienceStudent::ScienceStudent():student(),scienceDiscipline(""),course("") {}
ScienceStudent::ScienceStudent(string uniname, int regnum, UniversityStaff Procter, string discipaline, string course)
    :student(uniname,regnum,Procter),scienceDiscipline(discipaline),course(course) {}
ScienceStudent::ScienceStudent(const ScienceStudent& thestudent) 
    :student(thestudent), scienceDiscipline(thestudent.scienceDiscipline), course(thestudent.course) {}
string ScienceStudent::getscienceDiscipline() {
    return scienceDiscipline;
}
string ScienceStudent::getcourse() {
    return course;
}
void ScienceStudent::setscienceDiscipline(string discipline) {
    scienceDiscipline = discipline;
}
void ScienceStudent::setcourse(string Course) {
    course = Course;
}
ScienceStudent& ScienceStudent::operator=(const ScienceStudent& rtside) {
    if (this != &rtside) {
        student::operator=(rtside);
        scienceDiscipline = rtside.scienceDiscipline;
        course = rtside.course;
    }
    return *this;
}
// Driver program to test the classes
int main(void) {
    UniversityStaff proctor1("Tony");
    ScienceStudent student1("NUTN",12345,proctor1, "Physics","Undergraduate");
    cout << "Student1 details:" << endl;
    cout << "University: " << student1.getuniversityName() << endl;
    cout << "Registration Number: "<<student1.getregistrationNumber()<<endl;
    cout << "Proctor: " << student1.getprocter()<<endl;
    cout << "Discipline: "<<student1.getscienceDiscipline()<<endl;
    cout << "Course: " << student1.getcourse()<<endl;
    ScienceStudent student2(student1);
    cout << "\nStudent2 details:" << endl;
    cout << "University: " << student2.getuniversityName() << endl;
    cout << "Registration Number: " << student2.getregistrationNumber() << endl;
    cout << "Proctor: " << student2.getprocter() << endl;
    cout << "Discipline: " << student2.getscienceDiscipline() << endl;
    cout << "Course: " << student2.getcourse() << endl;
    ScienceStudent student3;
    student3 = student1;
    cout << "\nStudent3 details:" << endl;
    cout << "University: " << student3.getuniversityName() << endl;
    cout << "Registration Number: " << student3.getregistrationNumber() << endl;
    cout << "Proctor: " << student3.getprocter() << endl;
    cout << "Discipline: " << student3.getscienceDiscipline() << endl;
    cout << "Course: " << student3.getcourse() << endl;
    return 0;
}