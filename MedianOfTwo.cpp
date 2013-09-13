#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
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
	num++;
	if (start >= end - 1)
		return;
	key = (pArray[start] + pArray[end - 1]) / 2;
	cout << "(" << start << ", " << end << ", " << key << ")" << endl;
	
	for (i = start; i < end; i++) {
		if (pArray[i] < key) {
			temp = pArray[i];
			pArray[i] = pArray[j];
			pArray[j] = temp;
			j++;
		}
	}
	for (i = 0; i < m; i++)
		cout << pArray[i] << " ";
	cout << endl;
	cout << "j = " << j << endl;
	if (j > pos)
		GetMedian(pArray, start, j, pos);
	else
		GetMedian(pArray, j, end, pos - j);
}

int main(int argn, char **argv)
{
	num  = 0;
	m = atoi(argv[1]);
	n = atoi(argv[2]);
	int mod;
	if (argn == 4)
		mod = atoi(argv[3]);
	else
		mod = 1000;
	cout << m << endl;
	cout << mod << endl;
	int *a = new int[m];
	int *b = new int[n];
	for (int i = 0; i < m; i++)
		a[i] = rand() % mod;
	for (int i = 0; i < m; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << endl;

	GetMedian(a, 0, m, (m - 1) / 2);
	cout << "\ngetting median:\n";
	for (int i = 0; i < m; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "Median is: " << a[(m - 1) / 2] << endl;
	cout << num << endl;
	sort(a, a + m);
	for (int i = 0; i < m; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "After sorting, the median is: " << a[(m - 1) / 2] << endl;
	delete a[];
	delete b[];
	return 1;
}
