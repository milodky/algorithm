#include <iostream>
#include <vector>
using namespace std;

void result(vector<vector<int> > &ret, vector<int> &S, vector<int> &vec, int Position) {
	ret.push_back(vec);

	for (int i = Position; i < S.size(); i++) {
		vec.push_back(S[i]);
		result(ret, S, vec, i + 1);
		vec.pop_back();
	}
}
vector<vector<int> > subsets(vector<int> &S) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	vector<vector<int> > ret;
	int Size = S.size();
	if (Size == 0)
		return ret;
	vector<int> vec;
	result(ret, S, vec, 0);
	return ret;

}

int main (int argn, char **argv)
{
	vector<int> a;
	int Num = atoi(argv[1]);
	for (int i = 0; i < Num; i++)
		a.push_back(i + 1);
	vector<vector<int> > ret = subsets(a);
	int cnt = 0;
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << " ";
		}
		cnt++;
		cout << endl;
	}

	cout << "total count is " << cnt << endl;
	return 0;
}
