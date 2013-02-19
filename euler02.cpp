#include <iostream>
#include <cstdlib>
using namespace std;

int main(int count, char **args) {

	// Find the sum of the even terms of the Fibonacci sequence that are less
	// than 4 million

	int sum = 0;
	int max = atoi(args[1]);
	int temp;

	for(int i=1, j=2; j<max;) {
		if(j % 2 == 0)
			sum += j;
		temp = j;
		j=i+j;
		i=temp;
	}

	cout << sum << endl;
	return 0;
}
