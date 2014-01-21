#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cstddef>
using namespace std;

#define INT_MAX 0x3f3f3f3f

inline int myabs(int N)
{
	if (N < 0)
		N = 0 - N;
	return N;
}
int GetResult(vector<int> &Array, int K, int Sum)
{
	int Size = Array.size();
	if (Size == 0)
		return 0;
	if (K <= 0)
		return 0;
	int N = Size * K;
	int Diff = INT_MAX;
	int RetVal;
	vector<vector<int> > Matrix(Size + 1, vector<int>(N + 1, 0));
	Matrix[0][0] = 1;
	for (int i = 1; i <= Size; i++) {
		for (int j = 0; j <= N; j++) {
			if (Matrix[i - 1][j] == 1)
				Matrix[i][j] = 1;
			else if (j >= Array[i] && Matrix[i - 1][j - Array[i - 1]] == 1)
				Matrix[i][j] = 1;

			if (Matrix[i][j] == 1) {
				int temp = myabs(Sum - 2 * j);
				if (temp < Diff) {
					Diff = temp;
					RetVal = j;
				}
			}
		}
	}
	return RetVal;
}





int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	int K = atoi(argv[2]);

	vector<int> Array(Num);
	srand(time(NULL));
	int Sum = 0;
	for (int i = 0; i < Num; i++) {
		Array[i] = rand() % (K + 1);
		Sum += Array[i];
		cout << Array[i] << " ";
	}
	cout << endl;
	int Half = GetResult(Array, K, Sum);

	cout << "Sum is " << Sum << endl;
	cout << "Half is " << Half << endl;
	return 1;
}

