#include <iostream>

using namespace std;
static int Num;
void PrintTruthTable(char *pStr, int NumOfT, int NumOfF, int Count)
{
	if (NumOfT < 0 || NumOfF < 0)
		return;
	if (NumOfT == 0 || NumOfT == 0) {
		pStr[Count] = '\0';
		cout << pStr << endl;
		return;
	}
	if (NumOfT > 0) {
		pStr[Count] = 'T';
		PrintTruthTable(pStr, NumOfT - 1, NumOfF - 1, Count + 1);
	}
	if (NumOfF > 0) {
		pStr[Count] = 'F';
		PrintTruthTable(pStr, NumOfT - 1, NumOfF - 1, Count + 1);
	}
}


int main(int argn, char** argv)
{
	int n = atoi(argv[1]);
	cout << n << endl;
	char *pStr = new char[n + 1];
	PrintTruthTable(pStr, n, n, 0);
	delete[] pStr;
	return 0;
}
