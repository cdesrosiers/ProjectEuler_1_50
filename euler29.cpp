#include <iostream>
#include <set>
#include <cmath>
#define N 100
#define EPSILON 1e-7
using namespace std;

struct compare {
	bool operator() (double x, double y) {
		return x < y - EPSILON;
	}
};

int main() {
	set<double, compare> logs;
	for(int i=2; i<=N; ++i)
		for(int j=2; j<=N; ++j)
			logs.insert(1.0*j*log(i));

	cout << logs.size() << endl;
	return 0;
}
