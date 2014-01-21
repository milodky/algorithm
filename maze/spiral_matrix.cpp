#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <stack>
#include <utility>
#include <exception>
using namespace std;


vector<vector<int> > GetMatrix(int M, int N)
{
	vector<vector<int> > ret(M, vector<int>(N, 0));
	int l = 1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			ret[i][j] = l;
			l++;
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	return ret;
}


vector<int> GetSolution(vector<vector<int> > &matrix)
{

	int M = matrix.size();
	if (M == 0)
		throw exception();
	int N = matrix[0].size();
	if (N == 0)
		throw exception();
	int Size = M * N;
	vector<int> ret(Size);


	int Min = min(M, N);
	int layer = (Min + 1) / 2;
	int l = 0;
	for (int i = 0; i < layer; i++) {
		for (int j = i; j < N - i; j++) {
			ret[l] = matrix[i][j];
			l++;
		}

		if (l == Size)
			return ret;

		for (int j = i + 1; j < M - 1 - i; j++) {
			ret[l] = matrix[j][N - i - 1];
			l++;
		}
		if (l == Size)
			return ret;            
		for (int j = N - 1 - i; j >= i; j--) {
			ret[l] = matrix[M - i - 1][j];
			l++;
		}

		if (l == Size)
			return ret;           
		for (int j = M - 2 - i; j > i; j--) {
			ret[l] = matrix[j][i];
			l++;
		}

		if (l == Size)
			return ret;
	}

	return ret;
}

int main(int argn, char *argv[])
{
	int M = atoi(argv[1]);
	int N = atoi(argv[2]);
	srand(time(NULL));
	vector<vector<int> > matrix = GetMatrix(M, N);
	vector<int> Solution = GetSolution(matrix);
	for (int i = 0; i < Solution.size(); i++)
		cout << Solution[i] << " ";
	cout << endl;
	return 1;

}


