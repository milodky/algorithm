#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <exception>
using namespace std;


int GetLength(vector<int> &Array)
{
	int ret = 0;
	int Size = Array.size();
	if (Size <= 1)
		return ret;
	vector<int> DP(Size, 0);

	for (int i = 1; i < Size; i++) {
		if (Array[i - 1] ^ Array[i] == 0) {
			if (DP[i - 1] == 0)
				continue;
			int j = i - 1 - DP[i - 1];
			if (j >= 0) {
				if (Array[j] ^ Array[i] == 1)
					DP[i] = DP[i - 1] + 2;
				if (j > 0)
					DP[i] += DP[j - 1];
			}

			continue;
		}
		DP[i] = 2;
		if (i > 1)
			DP[i] += DP[i - 2];
	}
	for (int i = 0; i < Size; i++)
		if (ret < DP[i])
			ret = DP[i];
	for (int i = 0; i < Size; i++)
		cout << DP[i] << " ";
	cout << endl;
	return ret;
}



int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++)
		Array[i] = rand() % 2;

	for (int i = 0; i < Num; i++)
		cout << Array[i] << " ";
	cout << endl;
	cout << GetLength(Array) << endl;
	return 1;
}
