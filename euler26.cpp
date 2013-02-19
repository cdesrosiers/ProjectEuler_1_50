#include <iostream>
#include <bitset>
#include <stack>
#define LIMIT 1000
using namespace std;

int main(int c, char **args) {
	int longest = 0;
	int winner = 0;

	for(int divisor=2; divisor<=1000; ++divisor) {
		bitset<1000> remainders;
		stack<int> dividends;

		bool nonrepeating = false;

		int dividend = 1;

		while(true) {

			bool done = false;

			while(dividend < divisor) {
				dividend*=10;
				if(remainders[dividend/10-1]) {
					done = true;
					break;
				}

				remainders.set(dividend/10-1);
				dividends.push(dividend);
			}
			if(done)
				break;

			if((dividend %= divisor) == 0) {
				nonrepeating = true;
				break;
			}
		}

		if(nonrepeating)
			continue;


		int top;
		int counter = 0;
		do {
			top = dividends.top();
			dividends.pop();
			++counter;
		} while(top != dividend);

		if(counter > longest) {
			longest = counter;
			winner = divisor;
		}
	}

	cout << endl << winner << " has a recurring cycle of length " << longest << endl;
	return 0;
}
