#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

int main() {
	int start[] = {8,6,7,2,3};
	vector<int> digits(start, start + sizeof(start)/sizeof(int));

	for(int i=0; i<985; ++i) {
		int carry = 0;
		for(vector<int>::iterator it = digits.begin(); it != digits.end(); ++it) {
			int n2 = (*it) << 1;
			*it = (n2 + carry) % 10;
			carry = (n2 + carry) / 10;
		}

		if(carry > 0) {
			stringstream ss;
			ss << carry;
			string c = ss.str();
			for(string::reverse_iterator it = c.rbegin(); it != c.rend(); ++it) {
				char c = *it;
				digits.push_back(atoi(&c));
			}
		}
	}

	int sum = 0;
	for(vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); ++it) {
		sum += *it;
	}
	cout << sum << endl;

	return 0;
}
