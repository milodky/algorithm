/*
 * Maximum Product Subarray
 * Given an array that contains both positive
 * and negative integers, find the product of
 * the maximum product subarray. Expected Time
 * complexity is O(n) and only O(1) extra space
 * can be used.
 * 
 * Examples:
 * 
 * Input: arr[] = {6, -3, -10, 0, 2}
 * Output:   180  // The subarray is {6, -3, -10}
 * 
 * Input: arr[] = {-1, -3, -10, 0, 60}
 * Output:   60  // The subarray is {60}
 * 
 * Input: arr[] = {-2, -3, 0, -2, -40}
 * Output:   80  // The subarray is {-2, -40}
 */

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int Result(vector<int> &Array)
{
	int Size = Array.size();
	if (Size == 0)
		return -1;
	int CurrentMin = 1;
	int CurrentMax = 1;
	int MaxSoFar = 0;
	for (int i = 0; i < Size; i++) {
		if (Array[i] < 0) {
			int temp = CurrentMax;
			CurrentMax = max(CurrentMin * Array[i], 1);
			CurrentMin = temp * Array[i];
		} else if (Array[i] == 0) {
			CurrentMin = 1;
			CurrentMax = 1;
		} else {
			CurrentMax = CurrentMax * Array[i];
			CurrentMin = min(CurrentMin * Array[i], 1);
		}
		MaxSoFar = max(MaxSoFar, CurrentMax);
	}
	return MaxSoFar;
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		int a = rand() % 51 - 25;
		Array[i] = a;
		cout << a << " ";
	}
	cout << endl;

	int ret = Result(Array);
	cout << ret << endl;
	return 0; 
}

