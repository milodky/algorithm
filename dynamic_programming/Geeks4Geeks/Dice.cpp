/*
 * Dynamic Programming | Set 30 (Dice Throw)
 * Given n dice each with m faces, numbered from 1 to m,
 * find the number of ways to get sum X. X is the summation
 * of values on each face when all the dice are thrown.
 */

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int Calculate(int N, int M, int Sum)
{
	if (N == 0 || M == 0 || Sum == 0)
		return 0;
	if (N * M < Sum || Sum < N)
		return 0;
	vector<vector<int> > Matrix(N + 1, vector<int>(Sum + 1, 0));
	for (int i = 1; i <= M && i <= Sum; i++)
		Matrix[1][i] = 1;
	for (int i = 2; i <= N; i++)
		for (int j = 1; j <= Sum; j++)
			for (int k = 1; k < j && k <= M; k++)
				Matrix[i][j] += Matrix[i - 1][j - k];
	return Matrix[N][Sum];
}

int main(int argn, char *argv[])
{
	int N = atoi(argv[1]);
	int Sum = atoi(argv[2]);
	int M = 6;
	if (argn == 4)
		M = atoi(argv[3]);
	int Result = Calculate(N, M, Sum);
	cout << Result << endl;
	return 0;
}

