#include <iostream>
#include <string.h>
using namespace std;

inline void swap(char *a, char *b)
{
	char c;
	c = *a;
	*a = *b;
	*b = c;
}

void Permutation(char *pStr, int Current) {
	if (pStr[Current] == '\0') {
		cout << pStr << endl;
		return;
	}
	
	for (int i = Current; pStr[i] != '\0'; i++) {
		if (*(pStr + i) != *(pStr + Current)) {
			swap(pStr + i, pStr + Current);
			Permutation(pStr, Current + 1);
			swap(pStr + i, pStr + Current);
		} else
			Permutation(pStr, Current + 2);
	}
}

int main(int argn, char **argv)
{
	
	char pStr[] = {"abb"};
	Permutation(pStr, 0);
	return 0;
}
