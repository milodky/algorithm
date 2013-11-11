#include <iostream>
#include <vector>

using namespace std;

int Size;
//unordered_set<int> hashmap;
void swap(vector<int> &num, int i, int j) {
	int temp = num[i];
	num[i] = num[j];
	num[j] = temp;
}
void result(vector<vector<int> > &ret, vector<int> &num, int Cnt)
{
	if (Cnt == Size) {
		ret.push_back(num);
		return;
	}

	for (int i = Cnt; i < Size; i++) {

		if (i != Cnt && num[i] == num[Cnt])
			continue;
		swap(num, i, Cnt);
		result(ret, num, Cnt + 1);
		swap(num, i, Cnt);
	}
}
vector<vector<int> > permuteUnique(vector<int> &num) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	Size = num.size();
//	hashmap.clear();
	vector<vector<int> > ret;
	if (Size == 0)
		return ret;
	result(ret, num, 0);
	return ret;        
}

int main ()
{
	vector<int> A;
	A.push_back(2);
	A.push_back(1);
	A.push_back(1);
	sort(A.begin(), A.end());
	vector<vector<int> > ret = permuteUnique(A);
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	return 0;
}
