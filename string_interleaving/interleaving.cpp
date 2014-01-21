#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool IsInterleaving(string &s1, string &s2, string &s3)
{
	int M = s1.size();
	if (M == 0)
		return (s2 == s3);

	int N = s2.size();
	if (N == 0)
		return (s1 == s3);
	if (s1.size() + s2.size() != s3.size())
		return false;

	vector<vector<int> > matrix(M + 1, vector<int>(N + 1, 0));
	for (int i = 1; i < M + 1; i++)
		if (s1[i - 1] == s3[i - 1])
			matrix[i][0] = 1;
		else
			break;
	for (int i = 1; i < N + 1; i++)
		if (s2[i - 1] == s3[i - 1])
			matrix[0][i] = 1;
		else
			break;
	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (matrix[i - 1][j] && ((s2[i - 1] == s3[i + j - 1]) || (s1[i - 1] == s3[i + j - 1]))) {
				cout << "haha" << endl;
				matrix[i][j] = 1;
				continue;
			}
			if (matrix[i][j - 1] && ((s1[j - 1] == s3[i + j - 1]) || (s2[j - 1] == s3[i + j - 1]))) {
				cout << "hehe" << endl;
				matrix[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < M + 1; i++) {
		for (int j = 0; j < N + 1; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	return matrix[M][N];
}

int main()
{
	string s1 = "babb";
	string s2 = "bbcbbaa";
	string s3 = "bbabacbbbab";

	if (IsInterleaving(s1, s2, s3))
		cout << "haagadfasdf" << endl;

	return 1;
}

