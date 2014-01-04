/*
 * No. 52 - Maximal Product when Cutting Rope
 * Given a rope with length n, how to cut the rope into
 * m parts with length n[0], n[1], ...,n[m-1], in order
 * to get the maximal product of n[0]*n[1]* ... *n[m-1]?
 * We have to cut once at least. Additionally, the length
 * of the whole length of the rope, as well as the length
 * of each part, are in integer value.
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int GetResult(int Num, vector<int> &Array)
{
	if (Array[Num] != -1)
		Array[Num] = 1;
	for (int i = 1; i < Num; i++) {
		if (Array[i] == -1)
			Array[i] = GetResult(i, Array);
		if (Array[Num - i] == -1)
			Array[Num - i] = GetResult(Num - i, Array);
		Array[Num] = max(Array[Num], Array[i] * Array[Num - i]);
	}
	return Array[Num];
}

int Result(int Num)
{
	if (Num == 0)
		return 0;
	if (Num == 1)
		return 1;
	if (Num == 2)
		return 1;
	if (Num == 3)
		return 2;
	vector<int> Array(Num, -1);
	Array[0] = 1;
	Array[1] = 1;
	Array[2] = 2;
	Array[3] = 3;
	return GetResult(Num, Array);
}

int Recursive(int Num)
{
	if (Num == 0)
		return 0;
	if (Num == 1)
		return 1;
	int Ret = Num;
	for (int i = 1; i < Num; i++)
		Ret = max(Ret, Recursive(i) * Recursive(Num - i));
	return Ret;
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	int Product = Result(Num);
	cout << "Maximal product From DP is: " << Product << endl;
	int ProductR = Recursive(Num);
	cout << "Maximal product From Recursion is: " << ProductR << endl;
	return 1;
}

