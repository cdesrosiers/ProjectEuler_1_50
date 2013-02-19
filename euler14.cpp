#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

unsigned long long termlimit = (ULLONG_MAX-1)/3;

unsigned int chainlen(int number) {
	unsigned long long term = number;
	unsigned int count = 1;
	while(term!=1) {
		if(term % 2 == 0)
			term/=2;
		else if(term < termlimit) { //check for overflow
			term = 3*term + 1;
		} else {
			cout << "Usigned int overflow\n";
			cout << "ULLONG_MAX = " << ULLONG_MAX << " term = " << term << endl;
			exit(EXIT_FAILURE);
		}
		++count;
	}
	return count;
}

int main(int c, char **args) {
	unsigned int maxlen = 0;
	int maxstart = 0;

	for(int i = 1; i< 1000000; ++i) {
		unsigned int len = chainlen(i);
		if(len > maxlen) {
			maxstart = i;
			maxlen = len;
		}
	}

	cout << maxstart << " has the longest chain length of " << maxlen << endl;

	return 0;
}
