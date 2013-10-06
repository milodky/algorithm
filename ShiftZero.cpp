/*
 * Given an Array With random 0s and non 0 numbers,
 * shift all the 0s to the beginning and non 0s to the rear. 
 * Eg: 1,9,8,4,0,0,2,7,0,6,0 
 * Out put 0,0,0,0,1,9,8,4,2,7,6 
 * i.e order of numbers not to change. Do it in place
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
static inline void swap(vector<int> &Array, int i, int j)
{
	int temp = Array[i];
	Array[i] = Array[j];
	Array[j] = temp;
}
void ZeroShift(vector<int> &Array)
{
	int Size = Array.size();
	if (Size == 0)
		return;

	int LastZero = Size;
	int ZeroCnt = 0;
	for (int i = Size - 1; i >= 0; i--) {
		if (Array[i] == 0) {
			if (LastZero == Size)
				LastZero = i;
			ZeroCnt++;
		} else {
			if (LastZero == Size)
				continue;
			else {
				swap(Array, i, LastZero);
				LastZero--;
			}
		}
	}
}

int main(int argn, char *argv[])
{
	int n = atoi(argv[1]);
	srand(time(NULL));
	vector<int> Array(n);
	for (int i = 0; i < n; i++) {
		Array[i] = rand() % n;
		cout << Array[i] << " ";
	}
	cout << endl;
	ZeroShift(Array);
	for (int i = 0; i < n; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;	
	return 0;
}
