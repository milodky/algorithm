#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int Result(vector<int> &a, vector<int> &b, vector<int> &c)
{
	int diff = 0x3f3f3f3f;

	for (int i = 0, j = 0, k = 0; i < a.size() && j < b.size() && c.size();) {
		int Max = max(a[i], max(b[j], c[k]));
		int Min = min(a[i], min(b[j], c[k]));

		diff = min(diff, Max - Min);
		if (diff == 0)
			return 0;
		if (Min == a[i])
			i++;
		else if (Min == b[j])
			j++;
		else
			k++;
	}
	return diff;
}


int main(int argn, char *argv[])
{
	int ii = atoi(argv[1]);
	int jj = atoi(argv[2]);
	int kk = atoi(argv[3]);
	srand(time(NULL));
	vector<int> a(ii);
	for (int i = 0; i < ii; i++)
		a[i] = rand() % 30;
	sort(a.begin(), a.end());
	cout << "a: ";
	for (int i = 0; i < ii; i++)
		cout << a[i] << " ";
	cout << endl;

	vector<int> b(jj);
	for (int i = 0; i < jj; i++)
		b[i] = rand() % 30;
	sort(b.begin(), b.end());
	cout << "b: ";
	for (int i = 0; i < jj; i++)
		cout << b[i] << " ";
	cout << endl;

	vector<int> c(kk);
	for (int i = 0; i < kk; i++)
		c[i] = rand() % 30;
	sort(c.begin(), c.end());
	cout << "c: ";
	for (int i = 0; i < kk; i++)
		cout << c[i] << " ";
	cout << endl;

	int ret = Result(a, b, c);
	cout << ret << endl;
	return 1;
}

