/*
 * Dynamic Programming | Set 35 (Longest Arithmetic Progression)
 * Given a set of numbers, find the Length of the 
 * Longest Arithmetic Progression (LLAP) in it.
 * 
 * Examples:
 * 
 * set[] = {1, 7, 10, 15, 27, 29}
 * output = 3
 * The longest arithmetic progression is {1, 15, 29}
 * 
 * set[] = {5, 10, 15, 20, 25, 30}
 * output = 6
 * The whole set is in AP
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>
#include <utility>
using namespace std;

int Calculate(vector<int> &Array)
{
	int Size = Array.size();
	if (Size == 0)
		return 0;
	unordered_map<int, unordered_set<int> > HashMap;
	for (int i = 1; i < Size; i++) {
		int j = 0;
		int k = Size - 1;
		while (j < i && i < k) {
			if (Array[j] + Array[k] < 2 * Array[i]) {
				j++;
				continue;
			}
			if (Array[j] + Array[k] > 2 * Array[i]) {
				k--;
				continue;
			}
			HashMap[Array[k] - Array[i]].insert(Array[i]);
			HashMap[Array[k] - Array[i]].insert(Array[j]);
			HashMap[Array[k] - Array[i]].insert(Array[k]);
			break;
		}
	}
	size_t Ret = 0;
	for (unordered_map<int, unordered_set<int> >::iterator iter = HashMap.begin(); iter != HashMap.end(); ++iter) {
		unordered_set<int> &myset = iter->second;
		Ret = max(Ret, myset.size());
	}
	return Ret;
}


int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num);
	srand(time(NULL));
	unordered_set<int> hashmap;
	for (int i = 0; i < Num;) {
		int a = rand() % 100;
		if (hashmap.count(a))
			continue;
		hashmap.insert(a);
		Array[i] = a;
		i++;
	}
	sort(Array.begin(), Array.end());
	for (int i = 0; i < Num; i++)
		cout << Array[i] << " ";
	cout << endl;

	int Result = Calculate(Array);
	cout << Result << endl;
	return 1;
}

