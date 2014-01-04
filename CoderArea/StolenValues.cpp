/*
 * No. 44 - Dynamic Programming on Stolen Values
 * There are n houses built in a line, each of which
 * contains some value in it. A thief is going to
 * steal the maximal value in these houses, but he
 * cannot steal in two adjacent houses because the
 * owner of a stolen house will tell his two neighbors
 * on the left and right side. What is the maximal
 * stolen value?
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int Result(vector<int> &Values)
{
	int Size = Values.size();
	if (Size == 0)
		return 0;
	vector<int> Ret(Size);
	Ret[0] = Values[0];
	if (Size > 1)
		Ret[1] = Values[1];
	for (int i = 2; i < Size; i++)
		Ret[i] = max(Ret[i - 1], Ret[i - 2] + Values[i]);
	int RetVal = 0;
	for (int i = 0; i < Size; i++)
		RetVal = max(RetVal, Ret[i]);
	return RetVal;
}


int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	srand(time(NULL));
	vector<int> Array(Num);
	for (int i = 0; i < Num; i++) {
		int a = rand() % 20 + 1;
		cout << a << " ";
		Array[i] = a;
	}
	cout << endl;
	int Val = Result(Array);
	cout << "Maximal value is: " << Val << endl;
	return 1;
}

