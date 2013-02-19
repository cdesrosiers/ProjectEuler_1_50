#include <iostream>
#include <cmath>
using namespace std;

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

int main() {
	unsigned long long sum=0;
	for(unsigned long long i=2; i<2000000; ++i)
		if(isPrime(i))
			sum+=i;

	cout << sum << endl;

	return 0;
}
