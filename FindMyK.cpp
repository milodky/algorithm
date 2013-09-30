/*
 * Given an array A[n] such that A[i+1] = A[i]+1 OR A[i]-1,
 * and a number k, can you determine in most efficient way 
 * whether k is present in A[n] or not?
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

bool FindK(vector<int> &Array, int K)
{
	int Size = Array.size();
	if (Size == 0)
		return false;
	int Index = K;
// 0 -1 0 1 2 3 4 5 6 5 6 7 6 5 6 7 8 9 10 9 
	while (Index < Size) {
		if (Array[Index] == K) {
			cout << "Found @ " << Index << endl;
			Index += 2;
		}
		else {
			int step = K - Array[Index];
			Index += (step > 0) ? step : (0 - step);
		}
	}
	return false;
}
int main(int argn, char **argv)
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num);

	Array[0] = 0;
	srand(time(NULL));
	cout << "0 ";
	for (int i = 1; i < Num; i++) {
		int temp = (rand() & 0x01) ? 1 : (0 - 1);
		Array[i] = Array[i - 1] + temp;
		cout << Array[i] << " ";
	}
	cout << endl;

	FindK(Array, 3);
	return 0;
}
