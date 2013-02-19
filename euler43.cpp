#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef unsigned long long natural;

int prime[] = {2,3,5,7,11,13,17};

bool magic(const string& number) {

	for(int i=2; i<=8; ++i) {
		string sub(number, i-1, 3);

		string::iterator it = sub.begin();
		if(*it == '0')
			sub.erase(it);

		natural n = strtoull(sub.c_str(), NULL, 0);
		if(n % prime[i-2] != 0)
			return false;
	}

	return true;
}

int main() {
	string number = "0123456789";
	string::iterator begin = number.begin(), end = number.end();
	natural sum = 0;

	do {
		string n = number;
		string::iterator it = n.begin();
		if(*it == '0')
			n.erase(it);

		if(magic(n))
			sum += strtoull(n.c_str(), NULL, 0);

	} while(next_permutation(begin, end));

	cout << sum << endl;
	return 0;
}
