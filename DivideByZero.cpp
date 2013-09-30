/*
 * Given an array with positive, negative and zeros, 
 * arrange the given array such that negatives are 
 * on left, zeros in the middle and positives on the right.
 */
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

inline void swap(vector<int> &Array, int i, int j)
{
	int temp = Array[i];
	Array[i] = Array[j];
	Array[j] = temp;
}

void DivideByZero(vector<int> &Array)
{
	int Size = Array.size();
	if (Size == 0 || Size == 1)
		return;
	int intLastNega = 0;
	int intLastZero = 0;
	int intLastPosi = 0;
	int intCurrent = 0;
	for (intCurrent = 0; intCurrent < Size; intCurrent++) {
		if (Array[intCurrent] > 0) {
			intLastPosi++;
		} else if (Array[intCurrent] < 0) {
			if (intLastZero != intCurrent)
				swap(Array, intLastNega, intLastZero);
			swap(Array, intCurrent, intLastNega);
			intLastNega++;
			intLastZero++;
		} else {
			swap(Array, intCurrent, intLastZero);
			intLastZero++;
		}
	}
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		Array[i] = rand() % Num - Num / 2;
		cout << Array[i] << " ";
	}
	cout << endl;
	DivideByZero(Array);
	for (int i = 0; i < Num; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
	return 0;
}
