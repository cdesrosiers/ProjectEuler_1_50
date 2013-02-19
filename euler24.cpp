#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
#define ORDER 3
using namespace std;

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main(int c, char **args) {

	int x = atoi(args[1]);
	
	char pDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	vector<char> digits (pDigits, pDigits + sizeof(pDigits)/sizeof(char));
	vector<char>::iterator it = digits.begin();
	list<char> result;

	for(int i=9; i>=1; --i) {
		int ifact = factorial(i);
		it = digits.begin() + x/ifact;
		result.push_back(*it);
		digits.erase(it);
		x %= ifact;
	}

	it = digits.begin();
	result.push_back(*it);

	for(list<char>::iterator i = result.begin(); i != result.end(); ++i)
		cout << *i;
	cout << endl;

	return 0;
}
