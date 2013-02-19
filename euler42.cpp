#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <cmath>
using namespace std;

void factorize(unsigned int n, list<unsigned int>& factors) {

	for(unsigned int i=1; i<=sqrt(n); ++i)
		if(n % i == 0)
			factors.push_front(i);

	for(list<unsigned int>::iterator it = factors.begin(); it != factors.end(); ++it) {
		if(!((*it)*(*it) == n))
			factors.push_front(n/(*it));
	}
}


bool isTriangle(unsigned int n) {
	list<unsigned int> factors;
	factorize(2*n, factors);

	list<unsigned int>::iterator it1 = factors.end(); 
	list<unsigned int>::iterator it2 = factors.end(); --it2;
	do {
		--it1; --it2;
		unsigned int x = *it1, y=*it2;

		if(y==x+1 && x*y == 2*n)
			return true;

	} while(it2 != factors.begin());
	
	return false;
}

bool isTriangleWord(const string& word) {
	int value = 0;
	for(int i=0; i<word.length(); ++i) {
		value += word[i] - 64;
	}
	return isTriangle(value);
}

int main() {
	fstream file("words.txt");
	vector<string> words;

	if(file.is_open()) {
		stringstream ins;
		string line;
		string word;
		while(getline(file, line)) {
			ins << line;
			while(getline(ins, word, ',')) {
				word.erase(0,1);
				word.erase(word.length()-1, word.length());
				words.push_back(word);
			}
		}
		ins.clear();
	}

	file.close();

	isTriangleWord("SKY");

	int num = 0;
	for(vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {
		if(isTriangleWord(*(it)))
			++num;
	}

	cout << num << endl;

	return 0;
}
