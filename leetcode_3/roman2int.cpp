#include <iostream>
#include <string>

using namespace std;

int convert(char c) {
	int ret = 0;
	switch (c) {
		case 'I':
			ret = 1;
			break;
		case 'V':
			ret = 5;
			break;
		case 'X':
			ret = 10;
			break;
		case 'L':
			ret = 50;
			break;
		case 'C':
			ret = 100;
			break;
		case 'D':
			ret = 500;
			break;
		case 'M':
			ret = 1000;
			break;
		default:
			break;
	}
	return ret;
}
int r2i(string s) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	int Size = s.size();
	if (Size == 0)
		return 0;
	if (Size == 1)
		return convert(s[0]);
	char CharSet[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
	int i = 0;
	size_t Pos = 0;
	for (i = 0; i < sizeof (CharSet); i++) {
		Pos = s.find(CharSet[i]);
		if (Pos != string::npos)
			break;
	}
	string s1 = "";
	if (Pos != 0)
		s1 = s.substr(0, Pos);
	string s2 = "";
	if (Pos != Size - 1)
		s2 = s.substr(Pos + 1);
	int Ret = r2i(s2) + convert(s[Pos]) - r2i(s1);
	return Ret;
}

int main()
{
	string s = "DCXXI";
	int ret = r2i(s);
	cout << ret << endl;
	return 0;
}

