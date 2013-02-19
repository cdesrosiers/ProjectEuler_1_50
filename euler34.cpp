#include <iostream>
#include <vector>
#define MAX_DIGITS 17
#define tr(container, it) \
	for(typeof(container.begin()) it = container.begin(); it != container.end(); ++it)

using namespace std;
typedef unsigned long long natural;
vector<natural> magic;
vector<int> factorials(10);
vector<natural> powers(MAX_DIGITS);

void findmagic(natural n, natural factsum, int exp) {
	if(exp == MAX_DIGITS)
		return;

	if((factsum > n) || (powers[exp] < factorials[9])) {
		for(int i=0; i<10; ++i) {
			natural candidate_number = n + i*powers[exp];
			natural candidate_factsum = factsum + factorials[i];

			if((candidate_factsum == candidate_number) && (i != 0))
				magic.push_back(candidate_number);
			findmagic(candidate_number, candidate_factsum, exp+1);
		}
	}
}

int main() {
	factorials[0] = 1;
	for(int i=1; i<10; ++i)
		factorials[i] = i*factorials[i-1];
	
	powers[0] = 1;
	for(int i=1; i<MAX_DIGITS; ++i) {
		powers[i] = 10*powers[i-1];
	}

	findmagic(0, 0, 0);

	tr(magic, it)
		cout << *it << " ";

	cout << endl;

	return 0;
}
