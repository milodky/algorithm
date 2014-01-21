#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void output(vector<int> &v)
{
	int Size = v.size();
	for (int i = 0; i < Size; i++)
		cout << v[i] << " ";
	cout << endl;
}

void rotate(vector<int> &v, int begin, int end)
{
	int length = end - begin + 1;
	for (int i = begin; i < length / 2 + begin; i++) {
		int temp = v[i];
		v[i] = v[end - i + begin];
		v[end - i + begin] = temp;
	}
}

void generate(vector<int> &v, int k)
{
	int Size = v.size();
	rotate(v, 0, Size - 1);
	rotate(v, 0, k);
	rotate(v, k + 1, Size - 1);
}


int search(vector<int> &v, int Num)
{
	int begin = 0;
	int end = v.size() - 1;
	while (begin <= end) {
		int mid = (end - begin) / 2 + begin;
		int &MVal = v[mid];
		if (Num == MVal)
			return mid;
		if (v[begin] < v[end]) {
			if (Num < MVal)
				end = mid - 1;
			else
				begin = mid + 1;
			continue;
		}
		if (Num > v[begin]) {
			if (Num > v[mid])
				begin = mid + 1;
			else
				end = mid - 1;
			continue;
		} else if (Num == v[begin])
			return begin;

		if (Num < v[mid]) {
			if (v[begin] > v[mid])
				end = mid - 1;
			else
				begin = mid + 1;
		} else
			begin = mid + 1;
	}
	return -1;
}



int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> v(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		v[i] = rand() % 30;
	}
	int n = v[2 * Num / 3];
	cout << "position is " << 2 * Num / 3 << endl;
	sort(v.begin(), v.end());
	output(v);
	generate(v, Num * 3 / 4);
	output(v);
	int position = search(v, n);
	cout << "result is " << position << endl;
	cout << n << endl;
	cout << v[position] << endl;
}

