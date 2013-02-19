#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	vector<unsigned long long> digits;

	string numbers[100];

	ifstream file("bigsum.txt");
	if(file.is_open()) {
		for(int i=0; i<100; ++i)
			file >> numbers[i];
	}
	file.close();

	unsigned long long carry = 0, sum = 0;
	for(int i=49; i>=0; --i) {
		sum = carry;
		for(int j=0; j<100; ++j) {
			char c = numbers[j][i];
			int term = atoi(&c);
			// cout << term << " + ";
			sum += term;
		}
		carry = sum / 10;
		if(i!=0)
		digits.push_back(sum % 10);
	}

	cout << sum << " ";

	for(int i=digits.size()-1; i>=0; --i)
		cout << digits[i] << " ";
	cout << endl;

	return 0;
}
