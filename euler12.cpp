#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>
using namespace std;

int numberFactors(unsigned int number) {
	int factors = 1;
	int sq = sqrt(number);

	for(int i=2; i<=sq; ++i) {
		if(number % i == 0)
			++factors;
	}

	return factors*2 - (sq*sq == number ? 1 : 0);
}

int main(int c, char **args) {

	unsigned int max = UINT_MAX/2;
	int triangle = 0;

	for(unsigned int i=1; i<max; ++i) {
		triangle = i*(i+1)/2;
		if(numberFactors(triangle) > 500) {
			cout << triangle << endl;
			return 0;
		}
	}
	return 0;
}
