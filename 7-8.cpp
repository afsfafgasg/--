/*know the all stundent there grade range*/
#include <iostream>
#include <vector>
using namespace std;
void histogram(vector<int>hist);
int main(void) {
	vector<int> grades;
	int max = 0;
	int grade = 0;
	cout << "Enter the quiz scores.When you are finish enter -1!" << endl;
	while (grade > -1) {
		cout << "\nEnter the quiz grade: ";
		cin >> grade;
		grades.push_back(grade);
	}
	grades.resize(grades.size() - 1);
	for (unsigned i = 0; i < grades.size(); i++) {
		if (max < grades[i]) {
			max = grades[i];
		}
	}
	vector<int>hist(max+1);
	for (unsigned i = 0; i < grades.size(); i++) {
		hist[grades[i]] += 1;
	}
	cout << "Quiz result of " << grades.size() << " students" << endl;
	cout << "The maximum number is " << max << endl;
	for (unsigned i = 0; i < hist.size(); i++) {
		cout << hist[i] << " grades of " << i << endl;
	}
	return 0;
}

