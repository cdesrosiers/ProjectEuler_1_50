#include <iostream>
#include <bitset>
#include <cstdlib>
#define SIZE 1001
using namespace std;

int main() {
	int spiral[SIZE][SIZE];
	bitset<SIZE> filled[SIZE];

	int i,j, from;
	i = j = SIZE/2, from = 4;
	int end = SIZE * SIZE;

	for(int n=1; ;++n){

		spiral[i][j] = n;
		filled[i].set(j);

		if(n==end)
			break;

		switch(from) {
			case 1:
				if(!filled[i + 1][j]) {
					++i;
					from = 2;
				}
				else if(!filled[i][j + 1]) {
					++j;
					from = 1;
				}
				break;
			case 2:
				if(!filled[i][j - 1]) {
					--j;
					from = 3;
				}
				else if(!filled[i + 1][j]) {
					++i;
					from = 2;
				}
				break;
			case 3:
				if(!filled[i - 1][j]) {
					--i;
					from = 4;
				}
				else if(!filled[i][j - 1]) {
					--j;
					from = 3;
				}
				break;
			case 4:
				if(!filled[i][j + 1]) {
					++j;
					from = 1;
				}
				else if(!filled[i - 1][j]) {
					--i;
					from = 4;
				}
				break;
			default:
				cout << "Unknown state." << endl;
				exit(EXIT_FAILURE);
		}
	}

	int sum = 0;
	for(int c=0; c<SIZE; ++c) {

		sum += spiral[c][c] + spiral[c][SIZE-c-1];
	}

	sum -= 1;

	cout << sum << endl;

	return 0;
}
