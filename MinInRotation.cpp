#include <iostream>
#define MIN(a, b) ((a) > (b)) ? (b) : (a) 
using namespace std;

int FindMin(int *pArray, int Begin, int End)
{
	int result = 0;
	if (pArray == NULL)
		return result;
	if (Begin > End)
		return result;
	if (Begin == End - 1)
		return MIN(pArray[Begin], pArray[End]);
	if (Begin == End)
		return pArray[Begin];
	int Middle = (End - Begin) / 2 + Begin;
	if (pArray[Middle] >= pArray[Begin] && pArray[Middle] > pArray[End])
		result = FindMin(pArray, Middle + 1, End);
	else if (pArray[Middle] < pArray[Begin] && pArray[Middle] < pArray[End])
		result = FindMin(pArray, Begin, Middle);
	else if (pArray[Middle] >= pArray[Begin] && pArray[Middle] <= pArray[End])
		if (pArray[Begin] >= pArray[End])
			result = pArray[Middle];
		else
			result = 0;
	else if (pArray[Middle] < pArray[Begin] && pArray[Middle] > pArray[End])
		result = 0;
	return result;
}

int main()
{
	int Array1[] = {6, 7, 8, 9, 10, 2, 3, 4};
	int Array2[] = {8, 9, 10, 2, 3, 4, 5, 6};
	int Array3[] = {1, 2, 3 ,4 ,5, 6, 7, 8};
	cout << FindMin(Array1, 0, 7) << endl;
	cout << FindMin(Array2, 0, 7) << endl;
	cout << FindMin(Array3, 0, 7) << endl;
	return 0;
}
