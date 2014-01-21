/*
 * Find subarray with given sum
 * Given an unsorted array of nonnegative
 * integers, find a continous subarray
 * which adds to a given number.
 * 
 * Examples:
 * 
 * Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
 * Ouptut: Sum found between indexes 2 and 4
 * 
 * Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
 * Ouptut: Sum found between indexes 1 and 4
 * 
 * Input: arr[] = {1, 4}, sum = 0
 * Output: No subarray found
 */


#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;



void Result(vector<int> &Array, int Sum)
{
	int Size = Array.size();
	if (Size == 0) {
		cout << "Invalid input..\n";
		return;
	}
	vector<vector<int> > Matrix(Size, vector<int>(Size, 0));
	for (int i = 0; i < Size; i++)
		Matrix[i][i] = Array[i];
	/*
	 * Matrix[i][j] means the sum from i to j
	 */
	for (int i = 0; i < Size; i++) {
		for (int j = i + 1; j < Size; j++) {
			Matrix[i][j] = Matrix[i][j - 1] + Array[j];
			if (Sum == Matrix[i][j]) {
				cout << "From " << i << " to " << j << endl;
				return;
			}
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
	int Sum = rand() % 70;
	cout << "Sum is: " << Sum << endl;

	Result(Array, Sum);
	return 0; 
}
