#include <iostream>
#include <cmath>
#include <climits>
#include <list>
#include <cstdlib>
using namespace std;

const unsigned int maxn = sqrt(UINT_MAX);

inline unsigned int hexagonal(unsigned int n) {
	return n*(2*n-1);
}

void factorize(unsigned int n, list<unsigned int>& factors) {

	for(unsigned int i=1; i<=sqrt(n); ++i)
		if(n % i == 0)
			factors.push_front(i);

	for(list<unsigned int>::iterator it = factors.begin(); it != factors.end(); ++it) {
		if(!((*it)*(*it) == n))
			factors.push_front(n/(*it));
	}
}

bool isTriangle(unsigned int n) {
	list<unsigned int> factors;
	factorize(2*n, factors);

	list<unsigned int>::iterator it1 = factors.end(); 
	list<unsigned int>::iterator it2 = factors.end(); --it2;
	do {
		--it1; --it2;
		unsigned int x = *it1, y=*it2;

		if(y==x+1 && x*y == 2*n)
			return true;

	} while(it2 != factors.begin());
	
	return false;
}

bool isPentagonal(unsigned int n) {
	list<unsigned int> factors;
	factorize(2*n, factors);

	list<unsigned int>::iterator it1 = factors.end();

	while(true) {
		--it1;

		if(it1 == factors.begin())
			break;

		list<unsigned int>::iterator it2 = it1;

		do {
			--it2;

			unsigned int x = *it1, y=*it2;

			if(y==3*x-1 && x*y == 2*n)
				return true;

		} while(it2 != factors.begin());
	}
	
	return false;
}

int main(int c, char **args) {
	int count = 0;
	unsigned int n, hex;

	for(n = 1; ((n <= maxn) && (count < 3)); ++n) {
		hex = hexagonal(n);

		if(isTriangle(hex) && isPentagonal(hex)) {
			++count;
		}
	}

	cout << hex << endl;

	return 0;
}
