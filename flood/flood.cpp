#include <iostream>
#include <vector>
using namespace std;
/*
int M;
int N;
void flood(int x, int y,
		vector<vector<char> > &board,
		vector<vector<char> > &visited)
{
	cout << "here\n";
	if ((visited[x][y] & 0x01) == 1 || board[x][y] == 'X')
		return;
	visited[x][y] |= 0x03;
	if (x > 0)
		flood(x - 1, y, board, visited);
	if (x < M - 1)
		flood(x + 1, y, board, visited);

	if (y > 0)
		flood(x, y - 1, board, visited);
	if (y < N - 1)
		flood(x, y + 1, board, visited);

}
void solve(vector<vector<char> > &board) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	M = board.size();
	if (M == 0)
		return;
	N = board[0].size();
	if (N == 0)
		return;
	vector<vector<char> > visited(M, vector<char>(N, 0));
	for (int i = 0; i < N; i++) {
		if (board[0][i] == '0' && (visited[0][i] & 0x01) == 0)
			flood(0, i, board, visited);
		if (board[M - 1][i] == '0' && (visited[M - 1][i] & 0x01) == 0)
			flood(M - 1, i, board, visited);
	}

	for (int i = 0; i < M; i++) {
		if (board[i][0] == '0' && (visited[i][0] & 0x01) == 0)
			flood(i, 0, board, visited);
		if (board[i][N - 1] == '0' && (visited[i][N - 1] & 0x01) == 0)
			flood(i, N - 1, board, visited);            
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (((visited[i][j] & 0x02) == 0) && (board[i][j] == '0'))
				board[i][j] = 'X';
		}
	}
}
*/
int M;
int N;
void flood(int x, int y,
		vector<vector<char> > &board,
		vector<vector<char> > &visited)
{
	if ((visited[x][y] & 0x01) == 1 || board[x][y] == 'X')
		return;
	visited[x][y] |= 0x03;
	if (x > 0)
		flood(x - 1, y, board, visited);
	if (x < M - 1)
		flood(x + 1, y, board, visited);

	if (y > 0)
		flood(x, y - 1, board, visited);
	if (y < N - 1)
		flood(x, y + 1, board, visited);

}
void solve(vector<vector<char> > &board) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	M = board.size();
	if (M == 0)
		return;
	N = board[0].size();
	if (N == 0)
		return;
	vector<vector<char> > visited(M, vector<char>(N, 0));
	for (int i = 0; i < N; i++) {
		if (board[0][i] == '0' && (visited[0][i] & 0x01) == 0)
			flood(0, i, board, visited);
		if (board[M - 1][i] == '0' && (visited[M - 1][i] & 0x01) == 0)
			flood(M - 1, i, board, visited);
	}

	for (int i = 0; i < M; i++) {
		if (board[i][0] == '0' && (visited[i][0] & 0x01) == 0)
			flood(i, 0, board, visited);
		if (board[i][N - 1] == '0' && (visited[i][N - 1] & 0x01) == 0)
			flood(i, N - 1, board, visited);            
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << (int) visited[i][j] << " ";
			if (((visited[i][j] & 0x02) == 0) && (board[i][j] == '0'))
				board[i][j] = 'X';
		}
		cout << endl;
	}



}
int main()
{
	vector<vector<char> > a(3, vector<char>(3, 'X'));
	a[1][1] = '0';
//	a[2][1] = '0';
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << "after:\n"; 
	solve(a);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}


	return 1;
}

