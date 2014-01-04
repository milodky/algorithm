/*
 * No. 26 - Minimal Number of Coins for Change
 * Please implement a function which gets the minimal
 * number of coins, whose value is v1, v2, …, vn, to
 * make change for an amount of money with value t.
 * Any coin with value vi may duplicate for any times
 * to make change.
 * For example, the minimal number of coins to make
 * change for 15 out of a set of coins with value
 * 1, 3, 9, 10 is 3. We can choose two coins with
 * value 3 and a coin with value 9. The number of
 * coins for other choices should be greater than 3.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
using namespace std;

int Result(vector<int> &Values, int Target)
{
	int Size = Values.size();
	if (Size == 0)
		return 0;
	if (Target == 0)
		return 0;
	sort(Values.begin(), Values.end());
	Values[0] = 1;
	for (int i = 0; i < Size; i++)
		cout << Values[i] << " ";
	cout << endl;
	vector<int> Array(Target, 0);
	for (int i = 0; i < Target + 1; i++) {
		Array[i] = i;
		for (int j = 0; j < Size; j++) {
			int Pos = i - Values[j];
			if (Pos < 0)
				continue;
			Array[i] = min(Array[i], Array[Pos] + 1);
		}
	}
	return Array[Target];
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	int Val = atoi(argv[2]);
	unordered_set<int> Numbers;
	srand(time(NULL));
	for (int i = 0; i < Num;) {
		int a = rand() % Val + 1;
		if (Numbers.count(a))
			continue;
		Numbers.insert(a);
		i++;
	}
	vector<int> Array;
	for (auto x : Numbers)
		Array.push_back(x);

	int Amount = Result(Array, Val);
	cout << "Coin amount is: " << Amount << endl;
	return 1;
}

