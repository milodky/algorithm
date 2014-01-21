/*
 * Maximum size square sub-matrix with all 1s
 * Given a binary matrix, find out the maximum size square sub-matrix with all 1s.
 * 
 * For example, consider the below binary matrix.
 * 
 *  
 *    0  1  1  0  1 
 *    1  1  0  1  0 
 *    0  1  1  1  0
 *    1  1  1  1  0
 *    1  1  1  1  1
 *    0  0  0  0  0
 * The maximum square sub-matrix with all set bits is
 * 
 *     1  1  1
 *     1  1  1
 *     1  1  1
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <exception>
using namespace std;

int Calculate(vector<vector<int> > &Matrix)
{
	int M = Matrix.size();
	int N = Matrix[0].size();
	int Ret = 0;
	vector<vector<int> > Temp(Matrix);
//	for (int i = 1; i < M; i++) {
//		if (Temp[i][0] == 0)
//			continue;
//		Temp[i][0] = Temp[i - 1][0] + 1;
//	}
//	for (int i = 1; i < N; i++) {
//		if (Temp[0][i] == 0)
//			continue;
//		Temp[0][i] = Temp[0][i - 1] + 1;
//	}
	for (int i = 1; i < M; i++)
		for (int j = 1; j < N; j++) {
			if (Temp[i][j] == 0)
				continue;
			Temp[i][j] = min(Temp[i][j - 1], Temp[i - 1][j]);
			Temp[i][j] = min(Temp[i][j], Temp[i - 1][j - 1]) + 1;
			Ret = max(Ret, Temp[i][j]);
		}
	return Ret;
}

int main(int argn, char *argv[])
{
	int M = atoi(argv[1]);
	int N = atoi(argv[2]);
	vector<vector<int> > Matrix(M, vector<int>(N, 0));
	srand(time(NULL));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int a = rand() % 2;
			Matrix[i][j] = a;
			cout << a << " ";
		}
		cout << endl;
	}
	int Result = Calculate(Matrix);
	cout << Result << endl;
	return 1;
}
