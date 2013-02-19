#include <iostream>
#include <climits>
#define SIZE 8
using namespace std;

const int values[] = { 1, 2, 5, 10, 20, 50, 100, 200 };
unsigned int ways[SIZE][201];

unsigned int waysToMake(int n, int maxcoin) {
	if(n == 0) {
		cout << "bottom" << endl;
		return 1;
	} else if(n < 0) {
		return 0;
	}

	if(ways[maxcoin][n] == UINT_MAX) {
		int totalWays = 0;

		for(int coin=0; coin<=maxcoin; ++coin) {
			totalWays += waysToMake(n-values[coin], coin);
		}
		ways[maxcoin][n] = totalWays;
	}

	return ways[maxcoin][n];
}

int main() {
	for(int i=0; i<=SIZE; ++i)
		for(int j=0; j<=200; ++j)
			ways[i][j] = UINT_MAX;

	cout << waysToMake(200, 7) << endl;
	return 0;
}
