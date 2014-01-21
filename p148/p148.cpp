#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <utility>
using namespace std;

void output(vector<int> &A)
{
	int n = A.size();
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
}

int result(vector<int> &Array)
{
	int Size = Array.size();
	if (Size == 0)
		return -1;
	vector<int> Curr(Size + 1, 0);
	unordered_map<int, pair<int, int> > hashtable;
	for (int i = 1; i <= Size; i++)
		Curr[i] = Array[i - 1] + Curr[i - 1];
	int ret = 0;
	for (int i = 0; i < Size + 1; i++) {
		int &Num = Curr[i];
		if (hashtable.count(Num) == 0) {
			pair<int, int> p(i, i);
			hashtable.insert(make_pair<int&, pair<int, int>&>(Num, p));
		} else
			hashtable[Num].second = i;
	}

	for (auto &x : hashtable) {
		pair<int, int> &p = x.second;
		if (ret < p.second - p.first)
			ret = p.second - p.first;
	}
	return ret;
}

int main(int argn, char *argv[])
{
	int N = atoi(argv[1]);
	vector<int> Array(N);
	srand(time(NULL));
	for (int i = 0; i < N; i++)
		Array[i] = 2 * (rand() % 2) - 1;
	output(Array);
	cout << endl;
	int length = result(Array);
	cout << "The length is " << length << endl;
	return 1;
}

