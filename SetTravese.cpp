#include <set>
#include <vector>
#include <ctime>
#include <iostream>
using namespace std;

int main(int argn, char **argv)
{
	int Num = atoi(argv[1]);
	set<int> A;
	vector<int> B(Num);

	for (int i = 0; i < Num; i++) {
		A.insert(i);
		B[i] = i;
	}
	clock_t t1, t2, t3;
	t1 = clock();
	for (set<int>::iterator iter = A.begin(); iter != A.end(); iter++) {
	//	cout << *iter;
	}
	t2 = clock();

	for (vector<int>::iterator iter = B.begin(); iter != B.end(); iter++) {
	//	cout << *iter;
	}
	t3 = clock();
	cout << endl;
	cout << (float)(t2 - t1) / CLOCKS_PER_SEC << endl;
	cout << (float)(t3 - t2) / CLOCKS_PER_SEC << endl;

	return 0;
}
