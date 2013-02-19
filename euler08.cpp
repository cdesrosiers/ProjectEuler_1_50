#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int c, char ** args) {
	string number;
	ifstream file("bignumber.txt");
	if(file.is_open()) {
		while(file.good()) {
			file >> number;
		}
	}
	file.close();

	int maxproduct = 0;

	for(int i=0; i<996; ++i) {
		int product = 1;
		for(int j=0; j<5; ++j) {
			char c = number[i+j];
			product*=atoi(&c);
		}

		if(product > maxproduct)
			maxproduct = product;
	}

	cout << "Max product: " << maxproduct << endl;
	return 0;
}
