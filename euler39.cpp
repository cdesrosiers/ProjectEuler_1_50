#include <iostream>
#include <cmath>
#define MAX_P 1000
using namespace std;

int main() {
	int maxsolutions = 0;
	int bestp = 0;

	for(int p=2; p<=MAX_P; p+=2) {
		int numsolutions = 0;
		int halfp = p >> 1;

		for(int c=1; c<=p; ++c) {
			int ab = p*(halfp - c);
			int sqrtab = sqrt(ab);
			for(int a=1; a<=sqrtab; ++a) {
				if(ab % a == 0) {
					int b=ab/a;
					if((a+b+c == p) && (a*a + b*b == c*c)) {
						++numsolutions;
						if(p==840) {
							cout << a << " " << b << " " << c << endl;
						}
					}

				}
			}
		}
		if(numsolutions > maxsolutions) {
			bestp = p;
			maxsolutions = numsolutions;
		}
	}

	cout << maxsolutions << " for " << bestp << endl;
	return 0;
}
