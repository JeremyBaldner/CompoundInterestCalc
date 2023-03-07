#include <iostream>
#include "Project2AirgeadBanking.h"
using namespace std;

int main() {
	char answer = 'Y';
	while ((answer != 'N') && (answer != 'n')) {
		system("CLS");
		AirgeadBanking userOne;
		userOne.initialization(); //get user input
		userOne.initialPrint(); //show answers to questions
		userOne.calculation(); // calculate information
		cout << "\nWould you like to perform another calculation?\nType (Y or N)";
		cin >> answer;
		while ((answer != 'N') && (answer != 'n')) {
			if ((answer == 'Y') || (answer == 'y')) {
				break;
			}
			cout << "Enter Y or N...\n";
			cin >> answer;
		}
	}
	return 0;
}