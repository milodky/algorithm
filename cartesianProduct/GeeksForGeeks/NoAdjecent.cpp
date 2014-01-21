/*
 * Maximum sum such that no two elements are adjacent
 * Question: Given an array of positive numbers, find
 * the maximum sum of a subsequence with the constraint
 * that no 2 numbers in the sequence should be adjacent
 * in the array.
 * 
 * So 3 2 7 10 should return 13 (sum of 3 and 10)
 * or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).
 * Answer the question in most efficient way.
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
inline void swap(int &a, int &b)
{
	int x = a;
	a = b;
	b = x;
}

int Result(vector<int> &Array)
{
	int Size = Array.size();
	if (Size == 0)
		return -1;
	int Previous = 0;
	int Current = Array[0];
	for (int i = 1; i < Size; i++) {
		Previous += Array[i];
		swap(Current, Previous);
	}
	return max(Previous, Current);
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

	int Ret = Result(Array);
	cout << Ret << endl;
	return 0; 
}
