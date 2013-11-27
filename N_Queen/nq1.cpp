#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
static int N;

struct node {
	int i;
	int j;
	node (int x, int y) : i(x), j(y) {}
};


bool IsOK(vector<node> &holder, int x, int y, int size)
{
	if (size == 0)
		return true;

	for (int i = 0; i < size; i++) {
		node &Node = holder[i];
		if (Node.i == x || Node.j == y)
			return false;
		if (((Node.i - Node.j) == (x - y)) || ((Node.i + Node.j) == (y + x)))
			return false;
	}
	return true;
}

void output(vector<node> &holder)
{
	int Size = holder.size();
	for (int i = 0; i < Size; i++) {
		node &Node = holder[i];
		cout << "(" << Node.i << ", " << Node.j << ") ";
	}
	cout << endl;
}


void get_result(vector<node> &holder, int n, int &Cnt, int size)
{
	if (n == 0) {
		Cnt++;
		return;
	}
	int start_i;
	int start_j;
	if (size == 0) {
		start_i = 0;
		start_j = 0;
	} else {
		node &last = holder[size - 1];
		start_i = last.i + 1;
		start_j = 0;
	}
	for (int i = start_i; i < N; i++) {
		for (int j = start_j; j < N; j++) {
			if (IsOK(holder, i, j, size) == false)
				continue;
			//node Node(i, j);
			//holder.push_back(Node);
			holder[size].i = i;
			holder[size].j = j;
			get_result(holder, n - 1, Cnt, size + 1);
			//holder.pop_back();
		}
	}
}


int N_Queen(int n)
{
	if (n <= 0)
		return 0;
	int Cnt = 0;
	vector<node> holder(n, node(0, 0));
	get_result(holder, n, Cnt, 0);
	return Cnt;
}


int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
//	int Num = 2;
	N = Num;
	int Cnt = N_Queen(Num);
	cout << Cnt << endl;
	return 0;
}

