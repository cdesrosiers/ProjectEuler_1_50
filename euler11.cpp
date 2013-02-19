#include <iostream>
#include <fstream>
using namespace std;

int main() {

	int matrix[20][20];

	string number;
	ifstream file("bigmatrix.txt");
	if(file.is_open()) {
		for(int i=0; i<20; ++i)
			for(int j=0; j<20; ++j)
				file >> matrix[i][j];
	}
	file.close();

	unsigned long long max = 0;
	unsigned long long product = 1;
	int starti = 0;
	int startj = 0;

	/*
	// up and down quadruples
	for(int i=0; i<17; ++i) {
		for(int j=0; j<20; ++j) {
			product = 1;
			for(int k=0; k<4; ++k) {
				product *= matrix[i+k][j];
			}

			if(product > max) {
				starti = i; startj = j;
				max = product;
			}
		}
	}*/

	cout << max << endl;

	/*

	// left and right quadruples
	for(int i=0; i<20; ++i) {
		for(int j=0; j<17; ++j) {
			product = 1;
			for(int k=0; k<4; ++k) {
				product *= matrix[i][j+k];
			}

			if(product > max)
				max = product;
		}
	}

	cout << max << endl;
	*/
	// diagonal quadruples
	for(int i=0; i<17; ++i) {
		for(int j=0; j<17; ++j) {
			product = 1;
			for(int k=0; k<4; ++k) {
				product *= matrix[i+k][j+k];
			}

			if(product > max)
				max = product;
		}
	}

	cout << max << " at " << starti << " " << startj << endl;
	return 0;
}
