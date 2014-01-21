/*
 * Given a sorted array with duplicates and
 * a number, find the range in the form of
 * (startIndex, endIndex) of that number. Fo
 * example, given 0 2 3 3 3 10 10 and 3,
 * return (2, 4). Given the same array and 6,
 * return (-1, -1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <exception>
using namespace std;

static int BSearchLeft(vector<int> &Array, int K, int Begin, int End)
{
	int ret = -1;
	while (Begin <= End) {
		int Mid = (End - Begin) / 2 + Begin;
		if (Array[Mid] >= K) {
			if (Array[Mid] == K)
				ret = Mid;
			End = Mid - 1;

		} else
			Begin = Mid + 1;
	}
	return ret;
}
static int BSearchRight(vector<int> &Array, int K, int Begin, int End)
{
	int ret = -1;
	while (Begin <= End) {
		int Mid = (End - Begin) / 2 + Begin;
		if (Array[Mid] > K)
			End = Mid - 1;
		else {
			if (Array[Mid] == K)
				ret = Mid;
			Begin = Mid + 1;
		}
	}
	return ret;
}


pair<int, int> GetRange(vector<int> &Array, int K, int Begin, int End)
{
	pair<int, int> ret(-1, -1);

	ret.first = BSearchLeft(Array, K, 0, End);
	ret.second = BSearchRight(Array, K, 0, End);
	return ret;
	
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	int K = atoi(argv[2]);
	vector<int> Array(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++)
		Array[i] = rand() % 15;

	sort(Array.begin(), Array.end());
	for (int i = 0; i < Num; i++)
		cout << Array[i] << " ";
	cout << endl;
	const pair<int, int>& Range = GetRange(Array, K, 0, Num - 1);
	cout << "(" << Range.first << ", " << Range.second << ")" << endl;
	return 1;
}

