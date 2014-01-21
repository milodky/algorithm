#include <vector>
#include <cstddef>
#include <stack>
#include <queue>
#include <iostream>
#include <utility>
#include <ctime>
#include <cstdlib>
using namespace std;
#define INT_MAX 0x7fffffff
#define P 0.2
void GenMatrix(vector<vector<char> > &matrix, int M, int N)
{
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = ((double)rand()) / INT_MAX > P ? '1' : '0';
		}
	}
}
void Output(vector<vector<char> > &matrix)
{
	int M = matrix.size();
	int N = matrix[0].size();
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cout << matrix[i][j];
		cout << endl;
	}
}

int maximalRectangle(vector<vector<char> > &matrix) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	// flood or dfs
	int M = matrix.size();
	if (M == 0)
		return 0;
	int N = matrix[0].size();
	if (N == 0)
		return 0;

	int RetVal = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {

			if (matrix[i][j] == '0') {
				continue;
			}

			queue<pair<int, int> > holder;
			pair<int, int> pos(i, j);
			holder.push(pos);

			int X = M - 1;
			int Y = N - 1;
			while (holder.empty() == false) {
				pair<int, int> dian = holder.back();
				holder.pop();
				int x = dian.first;
				int y = dian.second;
				RetVal = max(RetVal, (x - i + 1) * (y - j + 1));
				if (x < X && (matrix[x + 1][y] == '1')) {
					pair<int, int> up(x + 1, y);
					holder.push(up);
				} else if (x >= X) {
				} else if (matrix[x + 1][y] == '0') {
					X = min(X, x + 1);
				}



				if (y < Y && (matrix[x][y + 1] == '1')) {
					pair<int, int> right(x, y + 1);
					holder.push(right);
				} else if (y >= Y){
				} else if (matrix[x][y + 1] == '0')
					Y = min(Y, y + 1);
			}

			if (X == M - 1)
				X++;
			if (Y == N - 1)
				Y++;

			int area = (X - i) * (Y - j);
			RetVal = max(RetVal, area);
		}
	}

	return RetVal;
}




int main(int argn, char *argv[])
{
	int M = atoi(argv[1]);
	int N = atoi(argv[2]);
	srand(time(NULL));
	vector<vector<char> > matrix(M, vector<char>(N, '1'));
	GenMatrix(matrix, M, N);
	Output(matrix);
	cout << maximalRectangle(matrix) << endl;
	return 1;
}


