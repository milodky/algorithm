#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cstddef>
#include <exception>
using namespace std;


vector<vector<int> > results(vector<vector<int> > sets)
{
	int Size = sets.size();
	if (Size < 2)
		throw exception();
	int Cnt = 1;
	for (int i = 0; i < Size; i++)
		Cnt *= sets[i].size();
	vector<vector<int> > ret(Cnt, vector<int>(Size));
	for (int i = 0; i < Cnt; i++) {
		int j = 1;
		for (int k = 0; k < Size; k++) {
			int length = sets[k].size();
			/*
			 * here, there are length times for 
			 * sets[0][l] to be the first element
			 * for a particular l

			 * so does the sets[k][l] to be the
			 * kth element for a particular l for
			 * Cnt / length times
			 */
			int length = sets[k].size();
			int num = sets[k][i / j % length];
			ret[i][k] = num;
			j *= length;
		}
	}
	cout << ret.size() << endl;
	return ret;
}

int main()
{
	vector<vector<int> > sets(2);
	for (int i = 0; i < 3; i++)
		sets[1].push_back(i);
	for (int i = 0; i < 3; i++)
		sets[0].push_back(i + 3);

	vector<vector<int> > ret = results(sets);
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	return 0;
}

