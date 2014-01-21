#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void output(vector<int> &v)
{
	int Size = v.size();
	for (int i = 0; i < Size; i++)
		cout << v[i] << " ";
	cout << endl;
}
void swap(vector<int> &v, int i, int j)
{
	if (i == j)
		return;
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void partition(vector<int> &v, int K, int begin, int end)
{
	int i = begin;
	int j = end;

	while (i < j) {
		if (v[j] < K) {
			swap(v, i, j);
			i++;
		} else
			j--;

		if (v[i] >= K) {
			swap(v, i, j);
			j--;
		} else
			i++;
	}
}

//void qsort(vector<int> &v, int begin, int end)
//{
//	if (begin >= end)
//		return;
//	if (begin == end - 1) {
//		if (v[begin] > v[end])
//			swap(v, begin, end);
//		return;
//	}
//	int K = (v[end] - v[begin]) / 2 + v[begin];
//	int ps = partition(v, K, begin, end);
//	cout << "partition ps is " << ps << endl;
//	output(v);
//	if (ps == end)
//		return;
//	qsort(v, begin, ps);
//	qsort(v, ps + 1, end);
//}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> v(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++)
		v[i] = rand() % 50;
	output(v);
	partition(v, 25, 0, Num - 1);
//	qsort(v, 0, Num - 1);
	output(v);
	return 1;
}

