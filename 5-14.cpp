/*讓使用者輸入三部電影，判斷出他和哪位評論者中的評論較將近，並推薦他其它部的電影*/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int nearest_neighbor(int reviews[4][6], int userRating[], int userRatingmovie[]);
int main(void) {
	int reviews[4][6] = { {3,1,5,2,1,5},
						  {4,2,1,4,2,4},
						  {3,1,2,4,4,1},
						  {5,1,4,2,4,2} };
	int reviewer[4] = { 0,1,2,3 };
	int movie[6] = { 100,101,102,103,104,105};
	int user_Rating[3];
	int user_Ratemovie[3];
	int minclose;
	cout << "Enter the three moive from(100-105)=>"<< endl;
	for (int i = 0; i < 3; i++) {
		while (true) {
			if (!(cin >> user_Ratemovie[i] || user_Ratemovie[i] < 100 || user_Ratemovie[i]>105)) {
				cout << "Your should enter the movie from(100-105)=>" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else {
				break;
			}
		}
	}
	cout << "Rating the movie that you chose.(1 (terrible) to 5 (excellent))"<<endl;
	for (int j = 0; j < 3; j++) {
		cout << "Movie " << user_Ratemovie[j] << ":";
		while (true) {
			if (!(cin >> user_Rating[j]) || user_Rating[j] < 1 || user_Rating[j] > 5) {
				cout << "Please enter the number between(1-5)!" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else {
				break;
			}
		}
	}
	minclose = nearest_neighbor(reviews, user_Rating, user_Ratemovie);
	cout << "Your rating is close to the reviewr " << reviewer[minclose] << endl;
	cout << "And you may interest in the other movies by reviewer's rating:"<<endl;
	for (int i = 0; i < 6; i++) {
		if (i != (user_Ratemovie[0] % 100) && (i != (user_Ratemovie[1] % 100)) && (i != (user_Ratemovie[2] % 100))) {
			cout << "A rating of " << reviews[minclose][i] << " for movie " << movie[i] << endl;
		}

	}
	system("pause");
	return 0;
}
int nearest_neighbor(int reviews[4][6], int userRating[], int userRatingmovie[]) {
	double distance, calculate[4];
	int index = 0;
	for (int i = 0; i < 4; i++) {
		calculate[i] = sqrt(pow(abs(userRating[0] - reviews[i][(userRatingmovie[0]) % 100]), 2) + pow(abs(userRating[1] - reviews[i][(userRatingmovie[1]) % 100]), 2) +
			pow(abs(userRating[2] - reviews[i][(userRatingmovie[2]) % 100]), 2));
	}
	for (int i = 1; i < 4; i++) {
		if (calculate[i] < calculate[index]) {
			index = i;
		}
	}
	return index;
}

