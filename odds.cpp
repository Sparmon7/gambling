
#include "odds.h"
#include <iostream>
#include <string>

using namespace std;

bool isInt(string s) {
	if (s.size() < 1) {
		return false;
	}
	for (string::iterator i = s.begin(); i != s.end(); ++i) {
		if (!isdigit(*i)) {
			return false;
		}
	}
	return true;
}

int prompt() {
	string firstName;
	string secondName;

	string plainOdds1;
	string plainOdds2;
	cout << endl;
	cout << "Welcome to the Gambling Helper" << endl;

	cout << "Type the name of the first team" << endl;
	cin >> firstName;

	cout << endl;
	cout << "Insert the name of the second team" << endl;
	cin >> secondName;

	double revenue1 = -1;
	while (revenue1 == -1) {
		cout << endl;
		cout << "What are the odds of " << firstName << " to win? (please enter in format +300,-150, etc)" << endl;
		cin >> plainOdds1;
		revenue1 = returns(plainOdds1);
	}
	

	double revenue2 = -1;
	while (revenue2 == -1) {
		cout << endl;
		cout << "What are the odds of " << secondName << " to win? (please enter in format of +300, -150, etc)" << endl;
		cin >> plainOdds2;
		revenue2 = returns(plainOdds2);
	}

	cout << endl;

	cout << "Returns (in terms of revenue) on a bet on the " << firstName << " is " << revenue1 << endl;
	cout << "Returns (in terms of revenue) on a bet on the " << secondName << " is " << revenue2 << endl;

	if (revenue1 * revenue2 <= revenue1 + revenue2) {
		cout << "No guaranteed winning strategy :(" << endl;
		return -1;
	}

	double profitCalc = (revenue1 * revenue2) / (revenue1 + revenue2) - 1;
	cout << "With this strategy, you are guaranteed a profit of " << profitCalc << "%" << endl;


	int wager = -1;
	while (wager == -1) {
		cout << "How much total money are you willing to bet?" << endl;
		string wag;
		cin >> wag;
		if(isInt(wag)){
			wager = stoi(wag);
		}
	}
	cout << endl;
	double firstWag = wager * revenue2 / (revenue2 + revenue1);
	double secondWag = wager - firstWag;

	cout << "Bet " << firstWag << " on " << firstName << endl;
	cout << "Bet " << secondWag << " on " << secondName << endl;
	cout << "With this strategy, you are guaranteed " << profitCalc * wager << " in profit!" << endl;
	

	return 0;

}

double returns(string plain) {
	if (plain.substr(0, 1) == "+") {
		if (isInt(plain.substr(1))) {
			int storedRaw = stoi(plain.substr(1));
			double returns = (storedRaw/100.0)+ 1;
			return returns;
		}
		else {
			return -1;
		}
		

	}else if (plain.substr(0, 1) == "-") {
		if (isInt(plain.substr(1))) {
			int storedRaw = stoi(plain.substr(1));
			double returns = (100.0/storedRaw) + 1;
			return returns;
		}
		else {
			return -1;
		}
		return stoi(plain.substr(1));
	}
	else {
		return -1;
	}
}

