#include <iostream>
#include <string.h>
using namespace std;
static int m;
void Parenthesis(char *pStr, int Left, int Right, int Num)
{
	if (Left < 0 || Right < 0 || Left > Right)
		return;
	if (Left == 0 && Right == 0)
		cout << pStr << endl;
	else {
		if (Left > 0) {
			pStr[Num] = '{';
			Parenthesis(pStr, Left - 1, Right, Num + 1);
		}
		if (Right > 0) {
			pStr[Num] = '}';
			Parenthesis(pStr, Left, Right - 1, Num + 1);
		}
	}
}
		

int main(int argn, char **argv)
{
	int n = atoi(argv[1]);
	m = 2 * n;
	char *pStr = new char[m];
	int cnt = 0;
	Parenthesis (pStr, n, n, cnt);
	delete[] pStr;
	return 0;
}
