/*
 * dynamic Programming | Set 28 (Minimum insertions to form a palindrome)
 * Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
 * For example:
 *     ab: Number of insertions required is 1. bab
 *     aa: Number of insertions required is 0. aa
 *     abcd: Number of insertions required is 3. dcbabcd
 *     abcda: Number of insertions required is 2. adcbcda 
 *     abcde: Number of insertions required is 4. edcbabcde
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

int Result(string &s)
{
	int Size = s.size();
	if (Size == 0)
		return 0;
	vector<vector<int> > Matrix(Size + 1, vector<int>(Size + 1, 0));
	for (int j = 1; j <= Size; j++) {
		for (int i = j - 1; i >= 1; i--) {
			if (s[i - 1] == s[j - 1])
				Matrix[i][j] = Matrix[i + 1][j - 1];
			else
				Matrix[i][j] = min(Matrix[i][j - 1], Matrix[i + 1][j]) + 1;
		}
	}
	return Matrix[1][Size];
}

int main(int argn, char *argv[])
{
	string Str(argv[1]);
	int Num = Result(Str);
	cout << Str << endl;
	cout << Num << endl;
	return 1;
}

