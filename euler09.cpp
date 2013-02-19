#include <iostream>
#include <cmath>
using namespace std;

int main(int count, char **args) {

	int a,b,c;

	for(c=1; c<500; ++c) {
		int ab = 500000 - 1000*c;
		int min = ab/1000, max = sqrt(ab);

		for(a=max; a>min; --a)
			if(ab % a == 0) {
				b = ab/a;
				if((a + b + c == 1000) && (a*a + b*b == c*c)) {
					cout << a << " * " << b << " * " << c << " = " << a*b*c << endl;
					return 0;
				}
			}
	}

	return -1;
}
