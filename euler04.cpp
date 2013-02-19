#include <iostream>
#include <queue>
#include <sstream>
#include <cstdlib>
using namespace std;

class PairCompare;

class Pair {
	public:
		Pair(int x, int y) : mX(x), mY(y), mProduct(x*y) {
		}
		friend class PairCompare;
		int product() { return mProduct; }
		int x() { return mX; }
		int y() { return mY; }
	private:
		int mX,mY, mProduct;
};

class PairCompare {
	public:
		bool operator() (const Pair& left, const Pair& right) {
			return left.mProduct < right.mProduct;
		}
};

bool isPalindrome(int number) {
	stringstream out;
	out << number;
	string s = out.str();

	int length = s.length();
	for(int i=0; i<length/2; ++i) {
		if(s[i] != s[length-i-1])
			return false;
	}
	return true;
}

int main(int count, char **args) {
	// Find the largest palindrome made from the product of 2 three-digit numbers
	// The following algorithm works by searching through all pairs of three
	// digit numbers starting from that pair producing the largest product,
	// (999,999) and choosing the next pair producing the next largest product,
	// and so on. Each time, we check to see whether the product is a palindrome
	// and stop if it is. We use a priority queue to continually choose the next
	// largest product, so the traversal through pairs of numbers is similar to
	// that of a Dijkstra graph traversal.
	
	bool visited[900][900];
	for(int i=0; i<900; ++i)
		for(int j=0; j<900; ++j) {
			if(i > j)
				visited[i][j] = true;
			else
				visited[i][j] = false;
		}

	cout << "Matrix initialized" << endl;

	priority_queue<Pair, vector<Pair>, PairCompare> q;
	q.push(Pair(999,999));
	visited[899][899] = true;

	int largestP = 0;

	while(!q.empty()) {
		Pair pair = q.top();
		q.pop();

		cout << pair.x() << " " << pair.y() << endl;
		if(isPalindrome(pair.product())) {
			largestP = pair.product();
			break;
		}

		int x = pair.x(), y = pair.y();

		if(x>100 && !visited[x-1-100][y-100]) {
			q.push(Pair(x-1, y));
			visited[x-1-100][y-100] = true;
		}
		if(y>100 && !visited[x-100][y-1-100]) {
			q.push(Pair(x, y-1));
			visited[x-100][y-1-100] = true;
		}
	}

	cout << "Largest Palindrome: " << largestP << endl;
	return 0;
}
