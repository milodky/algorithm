#include <iostream>
#include <vector>
#include <queue>
#include <cstddef>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

struct node {
	int val;
	int i;
	int j;
	node(int v, int _i, int _j) : val(v), i(_i), j(_j){}
	bool operator < (const node& X) const {
		if (val > X.val)
			return true;
		return false;
	}
};

bool MyLessThan(node &a, node &b)
{
	if (a.val < b.val)
		return true;
	return false;
}

int KthSmall(vector<int> &a, vector<int> &b, int K)
{
	int Size = a.size();
	if (K > (Size * Size) || Size == 0)
		return -1;

	priority_queue<node> Holder;
	//priority_queue<node, vector<node>, MyLessThan> Holder;

	int k = 0;
	node first(a[0] + b[0], 0, 0);
	Holder.push(first);

	while (true) {
		const node Node = Holder.top();

		Holder.pop();
		if (k == K)
			return Node.val;
		k++;
		if (Node.j + 1 < Size) {
			node temp1(a[Node.i] + b[Node.j + 1], Node.i, Node.j + 1);
			Holder.push(temp1);
		}
		if (Node.i + 1 < Size) {
			node temp2(a[Node.i + 1] + b[Node.j], Node.i + 1, Node.j);
			Holder.push(temp2);
		}
	}
	return -1;
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> a(Num);
	vector<int> b(Num);
	vector<int> c(Num * Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		a[i] = rand() % Num;
		b[i] = rand() % Num;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < Num; i++)
		cout << a[i] << " ";
	cout << endl;
	for (int i = 0; i < Num; i++)
		cout << b[i] << " ";
	cout << endl;
	for (int i = 0; i < Num; i++) {
		for (int j = 0; j < Num; j++) {
			c[i * Num + j] = a[i] + b[j];
		}
	}


	sort(c.begin(), c.end());
//	cout << "Kth small is " << KthSmall(a, b, 2) << endl;
	for (int k = 0; k < 10; k ++)
		cout << KthSmall(a, b, k) << " == " << c[k] << endl;

	return 0;

}

