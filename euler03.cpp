#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef unsigned long long ull;

bool isPrime(unsigned long long number) {
	if(number < 2)
		return false;

	unsigned long long max = sqrt(number);
	for(unsigned long long i=2; i<=max; ++i) {
		if(number % i == 0)
			return false;
	}
	return true;
}

int main(int c, char **args) {
	ull number = 600851475143;
	ull sqroot = sqrt(number);
	ull bestprime = 0;
	ull quotient;

	for(ull i = sqroot; i>=2; --i) {
		if(number % i == 0) {
			if(isPrime(quotient = number/i))
				bestprime = quotient;
			else if(isPrime(i) && i > bestprime)
				bestprime = i;
		}
	}

	cout << bestprime << endl;

	return 0;
}
