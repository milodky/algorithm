/*
 * Longest Substring without Duplication.
 * Problem: Given a string, please get the length of
 * the longest substring which does not have duplicated
 * characters. Supposing all characters in the string
 * are in the range from ‘a’ to ‘z’.
 */

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
inline char GetSingleChar()
{
	char c = rand() % 26 + 'a';
	return c;
}

string Result(string s)
{
	int Size = s.size();
	if (Size == 0)
		return "";
	char CharSets[26];
	for (int i = 0; i < 26; i++)
		CharSets[i] = -1;
	vector<int> stored(Size, 1);
	int HistoryMax = 0;
	int CurrentMax = 0;
	CharSets[s[0] - 'a'] = 0;
	for (int i = 1; i < Size; i++) {
		int pos = s[i] - 'a';
		if (CharSets[pos] == -1) {
			stored[i] = stored[i - 1] + 1;
			CharSets[pos] = i;
		} else {
			int PosDup = CharSets[pos];
			CharSets[pos] = i;
			stored[i] = i - PosDup;
		}
	}
	int pos = 0;
	int length = 0;
	for (int i = 0; i < Size; i++) {
		if (length < stored[i]) {
			pos = i;
			length = stored[i];
		}
	}
	cout << pos << endl;
	cout << length << endl;
	string ret = s.substr(pos - length + 1, length);
	return ret;
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	string s;
	srand(time(NULL));
	for (int i = 0; i < Num; i++)
		s += GetSingleChar();
	cout << s << endl;
	cout << Result(s) << endl;
}

