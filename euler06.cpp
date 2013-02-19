#include <iostream>
using namespace std;

int main(int count, char **args) {
	int sum = 0;
	int sumofsquares = 0;

	for(int i=1; i<=100; ++i) {
		sum += i;
		sumofsquares += i*i;
	}

	cout << sum*sum - sumofsquares << endl;
	
	return 0;
}
