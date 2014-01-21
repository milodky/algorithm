#include <vector>
#include <string>
#include <iostream>

using namespace std;

void output(vector<vector<int> > Matrix)
{
	int M = Matrix.size();
	int N = Matrix[0].size();
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cout << Matrix[i][j] << " ";
		cout << endl;
	}
}


bool isMatch(const char *s, const char *p) {
	// Note: The Solution object is instantiated only once and is reused by each test case.    
	string S(s);
	string P(p);

	int M = S.size();
	int N = P.size();
	if (M == 0 && N == 0)
		return true;

	vector<vector<int> > Matrix(M + 1, vector<int>(N + 1, 0));
	Matrix[0][0] = 1;
	for (int i = 1; i <= M; i++) {
		if (S[i - 1] == '*' && i == 1)
			Matrix[i][0] = 1;
		if (S[i - 1] == '*' && i > 1)
			Matrix[i][0] = Matrix[i - 2][0];
	}
	for (int i = 1; i <= N; i++) {
		if (P[i - 1] == '*' && i == 1)
			Matrix[0][i] = 1;
		if (P[i - 1] == '*' && i > 1)
			Matrix[0][i] = Matrix[0][i - 2];
	}
	output(Matrix);
	cout << "------------------" << endl;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {

			if (Matrix[i - 1][j - 1] && S[i - 1] == P[j - 1]) {
				Matrix[i][j] = 1;
				continue;
			}
			if (Matrix[i - 1][j - 1] && S[i - 1] == '.') {
				Matrix[i][j] = 1;
				continue;
			}
			if (Matrix[i - 1][j - 1] && P[j - 1] == '.') {
				Matrix[i][j] = 1;
				continue;
			}
			if (Matrix[i - 1][j - 1] && i > 1 && S[i - 1] == '*' && S[i - 2] == '.') {
				Matrix[i][j] = 1;
				continue;
			}
			if (Matrix[i - 1][j - 1] && i > 1 && S[i - 1] == '*' && S[i - 2] == P[j - 1]) {
				Matrix[i][j] = 1;
				continue;
			}
			if (i > 1 && S[i - 1] == '*' && (Matrix[i - 2][j] || Matrix[i - 1][j])) {
				Matrix[i][j] = 1;
				continue;
			}
			if ((Matrix[i - 1][j - 1] || Matrix[i - 1][j]) && j > 1 && P[j - 1] == '*' && P[j - 2] == '.') {
				Matrix[i][j] = 1;
				continue;
			}
			if (Matrix[i - 1][j - 1] && j > 1 && P[j - 1] == '*' && P[j - 2] == S[i - 1]) {
				Matrix[i][j] = 1;
				continue;
			}
			if (j > 1 && P[j - 1] == '*' && (Matrix[i][j - 2] || Matrix[i][j - 1])) {
				Matrix[i][j] = 1;
				continue;
			}
		}
	}
	output(Matrix);
	return Matrix[M][N];
}


int main()
{
	char *s = "aaa";
	char *p = ".*";
	isMatch(s, p);
	return 1;

}

