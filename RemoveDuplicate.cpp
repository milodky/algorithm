#include <iostream>
using namespace std;

int removeElement(int A[], int n, int elem) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	int MaxElement = 0;
	if (n == 0)
		return 0;
	for (int i = 0; i < n; i++) {
		if (A[i] > MaxElement)
			MaxElement = A[n];
	}

	MaxElement = MaxElement + 1;
	int length = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] == elem) {
			A[i] = MaxElement;
			continue;
		}
		length++;
	}
	int Last = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (A[i] == MaxElement) {
			continue;
		}
		if (Last != i)
			A[Last] = A[i];
		Last--;
	}
	for (int i = 0; i < 8; i++)
		cout << A[i] << " ";
	cout << endl;

	for (int i = 0; i < length; i++) {
		A[i] = A[i + n - length];
	}
	return length;
}

int main()
{
	int A[] = {2,2,1,0,2,0,0,4};
	for (int i = 0; i < 8; i++)
		cout << A[i] << " ";
	cout << endl;

	int ret = removeElement(A, 8, 4);

	for (int i = 0; i < ret; i++)
		cout << A[i] << " ";
	cout << endl;

	return 0;
}

	
