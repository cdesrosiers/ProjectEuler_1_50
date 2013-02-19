#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;

bool isPrime(int number) {
	if(number < 2)
		return false;

	int max = sqrt(number);
	for(int i=2; i<=max; ++i) {
		if(number % i == 0)
			return false;
	}
	return true;
}

int main(int c, char **args) {
	int count = 0, goal = 6;
	int number = 2;
	bool found = false;

	while(true) {

		if(isPrime(number))
			++count;
		if(count == goal) {
			found = true;
			break;
		}

		if(number==INT_MAX) {
			cerr << "Maxed out on Integer range." << endl;
			break;
		}
		++number;
	}

	if(found)
		cout << "The 10 001th prime is " << number << endl;
	return 0;
}
