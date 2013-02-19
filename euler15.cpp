#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

struct node {
	node(int ix, int iy, int istate) : x(ix), y(iy), state(istate) {}
	int x, y, state;
};

int main(int c, char **args) {
	int size = 21;
	int pathcount = 0;

	bool active[21][21];
	for(int i=0; i<size; ++i)
		for(int j=0; j<size; ++j)
			active[i][j] = false;

	stack<node> s;

	s.push(node(0,0,0));
	active[0][0] = true;

	while(!s.empty()) {
		node& n = s.top();

		if((n.x == size - 1) && (n.y == size - 1)) {
			++pathcount;
			s.pop();
			active[n.x][n.y] = false;
			continue;
		}

		switch(n.state) {
			case 0:
				if(n.x < size-1 && !active[n.x+1][n.y]) {
					s.push(node(n.x+1, n.y, 0));
					active[n.x+1][n.y] = true;
				}
				++n.state;
				break;
			case 1:
				if(n.y < size-1 && !active[n.x][n.y+1]) {
					s.push(node(n.x, n.y+1, 0));
					active[n.x][n.y+1] = true;
				}
				++n.state;
				break;
			case 2:
				s.pop();
				active[n.x][n.y] = false;
				break;
			default:
				cout << "Node in unknown state\n";
				exit(EXIT_FAILURE);
		}
	}

	cout << "Path count: " << pathcount << endl;

	return 0;
}
