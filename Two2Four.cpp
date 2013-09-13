#include <iostream>
#include <string.h>
char* Two2Four (char *pBase2)
{
	int Len2, Len4;
	char *pBase4 = NULL;
	if (*pBase2 == NULL)
		return pBase4;
	Len2 = strlen(pBase2);
	Len2 = Len2 + Len2 & (0x01);
	Len4 = Len2 >> 1;
	pBase4 = new char[len4];
	for (int i = Len2 - 1; i >0; i -= 2) {
		int low = atoi(pBase2[i]);
		int high = atoi(pBase2[i - 1]);
		int value = high * 2 + low;
		sprintf(pBase4 + Len4 - 1, value);
		Len4--
	}
	return pBase4;
}

