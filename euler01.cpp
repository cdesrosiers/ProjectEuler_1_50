#include <iostream>
#include <cstdlib>
using namespace std;

int main(int count, char **args) {

	int sum = 0;
	int max = atoi(args[1]);

	for(int i=1; i<max; ++i) {
		if((i % 3 == 0) || (i % 5 == 0))
			sum += i;
	}

	cout << sum << endl;
	return 0;
}
