#include <iostream>
#include <climits>
using namespace std;

int main(int count, char **args) {
	int maxIterations = INT_MAX/20;
	int multiple = 20;
	bool found = false;

	for(int i=1; i<=maxIterations; ++i) {

		int j;
		for(j=19; j>0; --j) {
			if(multiple%j != 0)
				break;
		}

		if(j==0) {
			found = true;
			break;
		}

		multiple+=20;
	}

	cout << "Least common multiple of numbers 1-20: " << multiple << endl;
	return 0;
}
