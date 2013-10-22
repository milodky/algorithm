#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;


inline void swap(vector<int> &Array, int i, int j)
{
	if (i == j)
		return;
	int temp = Array[i];
	Array[i] = Array[j];
	Array[j] = temp;
}

void PartitionByK(vector<int> &Array, int K)
{
	int Size = Array.size();
	if (Size == 0)
		return;

	int LastLessThanK = -1;
	int LastK = -1;
	bool flag = false;
	for (int i = 0; i < Size; i++) {

		if (Array[i] < K) {
			// need swapping
			// FirstK with i
			// LastK with FirstK
			if (LastLessThanK + 1 != i)
				swap(Array, LastLessThanK + 1, i);
			if (LastK >= 0) {
				LastK++;
				swap(Array, i, LastK);
			}
			LastLessThanK++;
			continue;
		}
		if (Array[i] == K) {
			if (LastK < 0) {
			// never meet K before
				LastK = LastLessThanK + 1;
				swap(Array, LastK, i);
				continue;
			}
			swap(Array, ++LastK, i);
			//LastK++;
			continue;
		}
	}
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		Array[i] = rand() % 3;
		cout << Array[i] << " ";
	}
	cout << endl;
	PartitionByK(Array, 1);
	for (int i = 0; i < Num; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
	return 0;



}
