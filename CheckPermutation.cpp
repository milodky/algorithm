/*
 * given 2 unsorted integer arrays a and b of equal 
 * size. Determine if b is a permutation of a. Can 
 * this be done in O(n) time and O(1) space ?
 */


#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool IsPermutation(vector<int> &a, vector<int> &b)
{
	if (a.size() != b.size() || a.size() == 0)
		return false;
	int Size = a.size();
	int ProdA = 1;
	int ProdB = 1;

	for (int i = 0; i < Size; i++) {
		a[i] = a[i] + 2;
		ProdA *= a[i];
		b[i] = b[i] + 2;
		ProdB *= b[i];
	}
	if (ProdB == ProdA)
		return true;
	else
		return false;
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> a(Num);
	vector<int> c(Num);

	srand(time(NULL));

	for (int i = 0; i < Num; i++) {
		a[i] = rand() % Num;
		c[i] = rand() % (Num + 1);
	}
	vector<int> b(a);
	sort(b.begin(), b.end());

	if (IsPermutation(b, a))
		cout << "b is a permutation of a\n";
	if (!IsPermutation(b, c))
		cout << "b is not a permutation of c\n";
	return 0;
	
}
