#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <stack>
#include <utility>
#include <exception>
using namespace std;


vector<vector<int> > GetMaze(int M, int N)
{
	vector<vector<int> > ret(M, vector<int>(N, 0));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			ret[i][j] = rand() % 2;
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	return ret;
}


int GetSolution(vector<vector<int> > &Maze)
{
	int M = Maze.size();
	if (M == 0)
		throw exception();
	int N = Maze[0].size();
	if (N == 0)
		throw exception();

	int RetVal = 0;
	if (Maze[0][0] == 1 || Maze[M - 1][N - 1] == 1)
		return RetVal;
	stack<pair<int, int> > Holder;

	Holder.push(make_pair<int, int>(0, 0));

	while (Holder.empty() == false) {
		pair<int, int> &Node = Holder.top();
		int i = Node.first;
		int j = Node.second;
		Holder.pop();
		if ((i == M - 1) && (j == N - 1)) {
			RetVal++;
			continue;
		}

		if (i + 1 < M && Maze[i + 1][j] == 0)
			Holder.push(make_pair<int, int> (i + 1, j));
		if (j + 1 < N && Maze[i][j + 1] == 0)
			Holder.push(make_pair<int, int> (i, j + 1));
	}	
	return RetVal;

}

int main(int argn, char *argv[])
{
	int M = atoi(argv[1]);
	int N = atoi(argv[2]);
	srand(time(NULL));
	vector<vector<int> > Maze = GetMaze(M, N);
	int Solutions = GetSolution(Maze);
	cout << Solutions << endl;
	return 1;

}


