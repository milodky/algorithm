/*
 * Find a sorted subsequence of size 3 in linear time
 * Given an array of n integers, find the 3 elements
 * such that a[i] < a[j] < a[k] and i < j < k in 0(n) time.
 * If there are multiple such triplets, then print any one of them.
 * 
 * Examples:
 * 
 * Input:  arr[] = {12, 11, 10, 5, 6, 2, 30}
 * Output: 5, 6, 30
 * 
 * Input:  arr[] = {1, 2, 3, 4}
 * Output: 1, 2, 3 OR 1, 2, 4 OR 2, 3, 4
 * 
 * Input:  arr[] = {4, 3, 2, 1}
 * Output: No such triplet
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void Result(vector<int> &Array)
{
	int Size = Array.size();
	if (Size <= 3)
		return;
	vector<int> smaller(Size);
	vector<int> larger(Size);

	smaller[0] = Array[0];
	for (int i = 1; i < Size; i++)
		smaller[i] = min(Array[i - 1], smaller[i - 1]);
	larger[Size - 1] = Array[Size - 1];
	for (int i = Size - 2; i >= 0; i--)
		larger[i] = max(Array[i + 1], larger[i + 1]);
	for (int i = 0; i < Size; i++) {
		if (smaller[i] < Array[i] && Array[i] < larger[i]) {
			cout << smaller[i] << ", ";
			cout << Array[i] << ", ";
			cout << larger[i] << endl;
			return;
		}
	}
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

	Result(Array);
	return 0; 
}
