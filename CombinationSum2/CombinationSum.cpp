/*
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * 
 * Each number in C may only be used once in the combination.
 * 
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 * A solution set is: 
 * [1, 7] 
 * [1, 2, 5] 
 * [2, 6] 
 * [1, 1, 6] 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void generate(vector<vector<int> > &ret, vector<int> &num, vector<int> &holder, int target, int Pos)
{
	if (target == 0) {
		vector<int> tmp(holder);
		sort(tmp.begin(), tmp.end());
		ret.push_back(tmp);
		return;
	}

	for (int i = Pos; i >= 0; i--) {
		if (target < num[i])
			continue;
		holder.push_back(num[i]);
		generate(ret, num, holder, target - num[i], i - 1);
		holder.pop_back();
	}
}
vector<vector<int> > combinationSum2(vector<int> &num, int target)
{
	vector<vector<int> > ret;
	if (num.size() == 0 || target <= 0)
		return ret;
	vector<int> holder;
	sort(num.begin(), num.end());
	int Pos = num.size() - 1;
	generate(ret, num, holder, target, Pos);
	return ret;
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	int target = atoi(argv[2]);
	vector<int> Array;
	for (int i = 1; i < Num; i++)
		Array.push_back(i);
	vector<vector<int> > ret = combinationSum2(Array, target);

	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	return 1;
}











