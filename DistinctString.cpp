/*


*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numDistinct(string S, string T) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	int SizeS = S.size();
	if (SizeS == 0)
		return 0;
	int SizeT = T.size();
	if (SizeT == 0)
		return 1;
	int i = 0;
	int j = 0;
	/*
	   for (i = 0; i < SizeS; i++) {
	   if (S[i] != T[j])
	   continue;
	   j++;
	   }
	   if (j != SizeT)
	   return 0;
	 */

	vector<vector<int> > Matrix(SizeS + 1, vector<int>(SizeT + 1, 0));

	for (i = 0; i < SizeS + 1; i++)
		Matrix[i][0] = 1;

	for (i = 1; i < SizeS + 1; i++) {
		for (j = 1; j <= min(i, SizeT); j++) {
			if (S[i - 1] != T[j - 1]) {
				Matrix[i][j] = Matrix[i - 1][j];
				continue;
			}

			Matrix[i][j] = Matrix[i - 1][j - 1] + Matrix[i - 1][j];
		}
	}
	for (i = 0; i < SizeS + 1; i++) {
		for (j = 0; j < SizeT + 1; j++) {
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}

	return Matrix[SizeS][SizeT];


}

int main()
{
	string a = "acacacacac";
	string b = "ac";
	numDistinct(a, b);
	return 0;
}
