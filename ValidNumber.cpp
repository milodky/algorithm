#include <iostream>
#include <cstring>

using namespace std;

bool isNum(const char c)
{
	if ('0' <= c && c <= '9')
		return true;
	else return false;
}
bool scientific(const char *s)
{
	// must be an ordinary number
	int Size = strlen(s);
	if (Size == 0)
		return false;
	for (int i = 0; i < Size; i++) {
		if (isNum(s[i]))
			continue;
		return false;
	}
	return true;
}
bool IsAllBlank(const char *s)
{
	int Size = strlen(s);
	for (int i = 0; i < Size; i++) {
		if (s[i] == ' ')
			continue;
		return false;
	}
	return true;
}

bool fractional(const char *s)
{
	/*
	 * this is the first dot we've met
	 * 1. may be a scientific number
	 * 2. may be an ordinary number
	 */

	int Size = strlen(s);
	if (Size == 0)
		return false;
	for (int i = 0; i < Size; i++) {
		if (isNum(s[i]))
			continue;
		switch(s[i]) {
			case 'e':
				return scientific(s + i + 1);
			default:
				return false;
		}
	}
	return true;

}

bool isNumber(const char *s) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	//bool fractional = false;
	//bool scientific = false;

	int Size = strlen(s);
	if (Size == 0)
		return false;
	int i = 0;

	const char *p = s;
	if (s[0] == '.')
		return fractional(s + 1);

	while (*p == ' ' && *p != '\0')
		p++;
	cout << p << endl;

	const char first = p[i];
	if (!(isNum(first) || first == '-'))
		return false;
	cout << "a" << endl;
	for (i = 1; i < Size; i++) {
		if (isNum(p[i]))
			continue;
		switch (p[i]) {
			case '.':
				return scientific(p + i + 1);
			case 'e':
				return fractional(p + i + 1);
			case ' ':
				return IsAllBlank(p + i + 1);
			default:
				return false;
		}


	}


	return true;

}

int main()
{
	const char *p = " 0";
	isNumber(p);
	return 0;
}
