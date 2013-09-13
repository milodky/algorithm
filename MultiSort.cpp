#include <iostream>
using namespace std;

int min(int *pArray[], int *Index, int n, int k)
{
	int i;
	int temp;
	int value = 0x3f3f3f3f;
	for (i = 0; i < n; i++) {
		if (pArray[i][Index[i]] < value && Index[i] < k) {
			temp = i;
			value = pArray[i][Index[i]];
		}
	}
	Index[temp]++;
	return value;
}



void int* Multisort(int *pArray[], int n, int k)
{
	int *pSorted = NULL;
	int *Index;
	int MinValue;
	if (pArray == NULL)
		pSorted = NULL;
	pSorted = new int[n * k];
	Index = new int[n];
	for (int i = 0; i < n; i++)
		Index[i] = 0;
	for (int i = 0; i < n * k; i++) {
		MinValue = min(pArray, Index, n, k);
		pSorted[i] = MinValue;
	}
	delete[] Index;
	return pSorted;
}
