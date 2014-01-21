/*
 * Find the minimum distance between two numbers
 * 
 * Given an unsorted array arr[] and two numbers x and y,
 * find the minimum distance between x and y in arr[].
 * The array might also contain duplicates. You may assume
 * that both x and y are different and present in arr[].
 * 
 * Examples:
 * Input: arr[] = {1, 2}, x = 1, y = 2
 * Output: Minimum distance between 1 and 2 is 1.
 * 
 * Input: arr[] = {3, 4, 5}, x = 3, y = 5
 * Output: Minimum distance between 3 and 5 is 2.
 * 
 * Input: arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, x = 3, y = 6
 * Output: Minimum distance between 3 and 6 is 4.
 * 
 * Input: arr[] = {2, 5, 3, 5, 4, 4, 2, 3}, x = 3, y = 2
 * Output: Minimum distance between 3 and 2 is 1.
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void Result(vector<int> &Array, int x, int y)
{
	int Size = Array.size();
	if (Size == 0)
		return;
	int Diff = 0x3f3f3f3f;
	int Prev = -1;
	for (int i = 0; i < Size; i++) {
		int a = Array[i];
		if (a != x && a != y)
			continue;
		if (Prev == -1) {
			Prev = i;
			continue;
		}
		if (a == x) {
			if (Array[Prev] != x)
				Diff = min(Diff, i - Prev);
			Prev = i;
			continue;
		}
		if (a == y) {
			if (Array[Prev] != y)
				Diff = min(Diff, i - Prev);
			Prev = i;
			continue;
		}
	}
	cout << "Distance is: " << Diff << endl;
	
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
	int x, y;
Again:
	x = Array[rand() % Num];
	y = Array[rand() % Num];
	if (x == y)
		goto Again;
	cout << "(x, y): (" << x << ", " << y << ")\n"; 

	Result(Array, x, y);
	return 0; 
}
