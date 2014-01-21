/*
 * Find the Increasing subsequence of length three with maximum product
 * 
 * Given a sequence of non-negative integers, 
 * find the subsequence of length 3 having
 * maximum product with the numbers of the
 * subsequence being in ascending order.
 * 
 * Examples:
 * 
 *  
 * Input: 
 * arr[] = {6, 7, 8, 1, 2, 3, 9, 10} 
 * Output: 
 * 8 9 10
 * 
 * Input: 
 * arr[] = {1, 5, 10, 8, 9}
 * Output: 5 8 9
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_set>
#include <ctime>

using namespace std;

int Result(vector<int> &Array)
{
	int Size = Array.size();
	if (Size <= 3)
		return 0;
	vector<int> LHS(Size, 0);
	vector<int> RHS(Size, 0);
	unordered_set<int> RB_Tree;
	for (int i = 0; i < Size; i++) {
		int a = Array[i];
		LHS[i] = 0;
		for (int j = 0; j < i; j++)
			if (Array[j] < Array[i])
				LHS[i] = max(LHS[i], Array[j]);
	}
	cout <<"Left:	";
	for (int i = 0; i < Size; i++)
		cout << LHS[i] << "	";
	cout << endl;

	RHS[Size - 1] = 0;
	for (int i = Size - 2; i >= 0; i--) {
		RHS[i] = 0;
		if (Array[i] > RHS[i + 1] && Array[i] > Array[i + 1])
			continue;
		RHS[i] = max(RHS[i + 1], Array[i + 1]); 
	}
	cout <<"Right:	";
	for (int i = 0; i < Size; i++)
		cout << RHS[i] << "	";
	cout << endl;
	int Ret = 0;
	for (int i = 0; i < Size; i++)
		Ret = max(Ret, RHS[i] * LHS[i] * Array[i]);
	return Ret;
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num);
	srand(time(NULL));
	cout <<"Array:	";
	for (int i = 0; i < Num; i++) {
		int a = rand() % 21;
		Array[i] = a;
		cout << a << "	";
	}
	cout << endl;

	int ret = Result(Array);
	cout << ret << endl;
	return 0; 
}
