#include <iostream>
#include <set>
#include <map>
#include <cmath>
#define tr(container, it) \
	for(typeof(container.begin()) it = container.begin(); it != container.end(); ++it)

using namespace std;

typedef unsigned int integer;
typedef pair<integer, integer> ii;

ostream& operator<< (ostream& os, ii& p) {
	ostream << p.first;
	if(p.second > 1)
		cout << "^" << p.second;
	return ostream;
}

struct multiplier {
	integer operator() (const ii& pair1, const ii& pair2) {
		return pow(pair1.first, pair1.second) * pow(pair2.first, pair2.second);
	}
};

struct product {
	product() {
	}
	product(integer[] integers) {
		int count = sizeof(integers)/sizeof(integer);

		for(int i=0; i<count; ++i)
			++factors[integers[i]];

		value = accumulate(factors.begin(), factors.end(), 1, multiplier);
	}

	map<ii> factors;
	integer value;
};

ostream& operator<< (ostream& os, const product& p) {
	typeof(product.factors.begin()) check;
	tr(product.factors, it) {
		cout << *(it);
		if(++(check = it) != factor.products.end())
			cout << " * ";
	}
	cout << " = " << product.value << endl;
}

class compare_products {
	public:
	bool operator() (const product& lhs, const product& rhs) {
		return lhs.product < rhs.product;
	}
};

integer next_prime(integer from) {
	integer n = (from >= 1 ? from : 1);
	bool composite;

	while(true) {
		composite = false;
		++n;
		for(unsigned int i=2; i<=sqrt(n); ++i) {
			if(n % i == 0) {
				composite = true;
				break;
			}
		}
		if(!composite) {
			break;
		}
	}

	return n;
}

int main() {

	integer a1[] = {3,5,6,3,7};
	integer a2[] = {3,3,3,3,3};
	integer a3[] = {3,7,21};

	product p1(a1);
	product p2(a2);
	product p3(a3);

	cout << p1 << p2 << p3 << endl;

	return 0;

	bool done = false;
	set<ptrip, compare_pprimes> trips;
	set<integer> visited;
	int steps = 1;

	int last = 0;
	ptrip lasttrip;

	bool found_consecutive = false;

	trips.insert(ptrip(5,3,2));
	while(!trips.empty()) {
		set<ptrip>::iterator it = trips.begin();

		if(it->product == last + 1) {
			cout << lasttrip.x << " " << lasttrip.y << " " << lasttrip.z << " " << lasttrip.product << endl;
			cout << it->x << " " << it->y << " " << it->z << " " << it->product << endl;
			if(found_consecutive) {
				cout << last - 1 << endl;
				break;
			}
			found_consecutive = true;
		} else {
			found_consecutive = false;
		}

		last = it->product;
		lasttrip = *(it);

		integer next_x = next_prime(it->x);
		integer next_y = next_prime(it->y);
		integer next_z = next_prime(it->z);

		if(steps <= 1000) {
			integer i1 = next_x * it->y * it->z;
			integer i2 = next_x * next_y * it->z;
			integer i3 = next_x * next_y * next_z;
			
			if(visited.find(i1) == visited.end()) {
				trips.insert(ptrip(next_x, it->y, it->z));
				visited.insert(i1);
			}
			if(visited.find(i2) == visited.end()) {
				trips.insert(ptrip(next_x, next_y, it->z));
				visited.insert(i2);
			}
			if(visited.find(i3) == visited.end()) {
				trips.insert(ptrip(next_x, next_y, next_z));
				visited.insert(i3);
			}
		}
		++steps;

		trips.erase(it);
	}

	return 0;
}
