/*
 * Given an unsorted integer array, find the first missing positive integer.
 * 
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 * 
 * Your algorithm should run in O(n) time and uses constant space.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void swap(vector<int> &Array, int i, int j)
{
	int temp = Array[i];
	Array[i] = Array[j];
	Array[j] = temp;
}


int Result(vector<int> &Array)
{
	int Size  = Array.size();
	if (Size == 0)
		return 0;
	for (int i = 0; i < Size;) {
		if (Array[i] <= 0 || Size <= Array[i]) {
			i++;
			continue;
		}
		if (i == Array[i - 1]) {
			i++;
			continue;
		}
		int j = Array[i] - 1;
		if (Array[i] == Array[j]) {
			i++;
			continue;
		}
		swap(Array, i, j);
	}
	int ret;
	for (int i = 0; i < Size; i++) {
		if (i + 1 != Array[i]) {
			ret = i + 1;
			break;
		}
	}
	return ret;
}


int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	unordered_set<int> mymap;
	vector<int> Array(Num);
	srand(time(NULL));
	for (int i = 0; i < Num;) {
		int a = rand() % 31 - 15;
		if (mymap.count(a) == 0) {
			Array[i] = a;
			i++;
			mymap.insert(a);
		}
	}
	cout << "Before: " << endl;
	for (int i = 0; i < Num; i++)
		cout << Array[i] << " ";
	cout << endl;
	int ret = Result(Array);
	cout << ret << endl;
	cout << "After: " << endl;
	for (int i = 0; i < Num; i++)
		cout << Array[i] << " ";
	cout << endl;
	cout << "Sorted: " << endl;
	sort(Array.begin(), Array.end());	
	for (int i = 0; i < Num; i++)
		cout << Array[i] << " ";
	cout << endl;
	return 1;
}

