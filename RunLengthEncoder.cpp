/*
 * Run-Length Encoder
 */

#include <iostream>
using namespace std;

void RLEncoder(char *pStr)
{
	if (pStr == NULL)
		return;
	int Index = 1;
	int Count = 1;
	char CharEncoded = pStr[0];
	while (pStr[Index] != '\0') {
		if (pStr[Index] == CharEncoded)
			Count++;
		else {
			cout << Count << CharEncoded;
			Count = 1;
			CharEncoded = pStr[Index];
		}
		Index++;
	}
	cout << Count << CharEncoded;
	cout << endl;
}
int main(int argn, char *argv[])
{
	char *pStr = argv[1];
	RLEncoder(pStr);
	return 0;
}
