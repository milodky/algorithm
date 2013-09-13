#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#define min(a, b) ((a) > (b)) ? (b) : (a)
#define max(a, b) ((a) > (b)) ? (a) : (b)
using namespace std;
static int num;
static int m;
static int n;
void GetMedian(int *pArray, int start, int end, int pos)
{
	int key;
	int temp;
	int i;
	int j = start;
	if (start >= end - 1)
		return;
	key = (pArray[start] + pArray[end - 1]) / 2;
	for (i = start; i < end; i++) {
		if (pArray[i] < key) {
			temp = pArray[i];
			pArray[i] = pArray[j];
			pArray[j] = temp;
			j++;
		}
	}
	if (j > pos)
		GetMedian(pArray, start, j, pos);
	else
		GetMedian(pArray, j, end, pos - j);
}

int MedianOfArray(int *pA1, int *pA2, int Len1, int Len2)
{
	int Start1 = 0;
	int Start2 = 0;
	int End1 = Len1;
	int End2 = Len2;
	int i;
	int median1, median2;
	while ((Start1 < End1 - 2) || (Start2 < End2 - 2)) {
		if (Start1 < End1 - 1) {
			GetMedian(pA1, Start1, End1, (End1 + Start1 - 1) / 2);
			median1 = pA1[(End1 + Start1 - 1) / 2];
		}
		if (Start2 < End2 - 1) {
			GetMedian(pA2, Start2, End2, (End2 + Start2 - 1) / 2);
			median2 = pA2[(End2 + Start2 - 1) / 2];
		}
		if (median1 > median2) {
			End1 = (End1 + Start1 + 1) / 2;
			Start2 = (End2 + Start2 - 1) / 2;
		} else {
			End2 = (End2 + Start2 + 1) / 2;
			Start1 = (End1 + Start1 - 1) / 2;
		}
	cout << "1: ";
	for (i = Start1; i < End1; i++)
		cout << pA1[i] << " ";
	cout << endl;
	cout << "2: ";
	for (i = Start2; i < End2; i++)
		cout << pA2[i] << " ";
	cout << endl;
	cout << endl;
	}
	cout << "the last time: \n";
	cout << "1: ";
	for (i = Start1; i < End1; i++)
		cout << pA1[i] << " ";
	cout << endl;
	cout << "2: ";
	for (i = Start2; i < End2; i++)
		cout << pA2[i] << " ";
	cout << endl;
	cout << "1: ";
	for (i = 0; i < m; i++)
		cout << pA1[i] << " ";
	cout << endl;
	cout << "2: ";
	for (i = 0; i < m; i++)
		cout << pA2[i] << " ";
	cout << endl;
	return max(median1, median2);
}

int main(int argn, char **argv)
{
	num  = 0;
/*	m = atoi(argv[1]);
	n = atoi(argv[2]);
*/
	m = 9;
	n = 8;
	int mod, k;
	int i;
	int r1;
	int r2;
/*
	if (argn == 4)
		mod = atoi(argv[3]);
	else
		mod = 1000;
*/
	mod = 1000;
	cout << m << endl;
	cout << mod << endl;
	int *a = new int[m];
	int *b = new int[n];
	int *c = new int[m + n];
	for (i = 0; i < m; i++)
		a[i] = rand() % mod;
	for (i = 0; i < n; i++)
		b[i] = rand() % mod;
	cout << endl;
	for (i = 0; i < m; i++)
		cout << a[i] << " ";
	cout << endl;
	for (i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;
	copy(a, a + m, c);
	copy(b, b + n, c + m);
//	int a[] = {11, 55, 22, 44, 66};
	cout << "median is: " << MedianOfArray(a, b, m, n) << endl; 
	sort(c, c + m + n);
	for (int i = 0; i < m + n; i++)
		cout << c[i] << " ";
	cout << "\nmedian is: " << c[(m+n - 1) / 2] << " or " << c[(m + n -1) / 2 + 1] << endl;
	cout << endl;
	delete[] a;
	delete[] b;
	delete[] c;
	return 1;
}
