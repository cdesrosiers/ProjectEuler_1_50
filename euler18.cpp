#include <iostream>
#include <fstream>
#include <algorithm>
#define SIZE 15
using namespace std;

int main() {
	ifstream file("bigtriangle.txt");
	int triangle[SIZE][SIZE];
	int pathlen[SIZE][SIZE];

	if(file.is_open()) {
		for(int i=0; i<SIZE; ++i)
			for(int j=0; j<=i; ++j)
				file >> triangle[i][j];
	}
	file.close();

	for(int j=0; j<SIZE; ++j) {
		pathlen[SIZE-1][j] = triangle[SIZE-1][j];
	}

	for(int i=SIZE-2; i>=0; --i) {
		for(int j=0; j<=i; ++j) {
			pathlen[i][j] = triangle[i][j] + max(pathlen[i+1][j], pathlen[i+1][j+1]);
		}
	}

	for(int i=0; i<SIZE; ++i) {
		for(int j=0; j<=i; ++j)
			cout << triangle[i][j] << " ";
		cout << endl;
	}

	cout << endl << endl;

	for(int i=0; i<SIZE; ++i) {
		for(int j=0; j<=i; ++j)
			cout << pathlen[i][j] << " ";
		cout << endl;
	}

	return 0;
}
