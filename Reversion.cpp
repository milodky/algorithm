#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

vector<int> Reversion(vector<int> &Array, int Begin, int End, int &Cnt)
{
	vector<int> Ret;
	if (End < Begin) {
		Cnt = 0;
		goto Result;
	}
	
	Ret.resize(End - Begin + 1);
	if (Begin == End) {
		Ret[0] = Array[Begin];
		Cnt = 0;
		goto Result;
	}
	if (Begin + 1 == End) {
		if (Array[End] < Array[Begin])
			Cnt = 1;
		else
			Cnt = 0;
		Ret[0] = min(Array[Begin], Array[End]);
		Ret[1] = max(Array[Begin], Array[End]);
		goto Result;
	}
{
	int Mid = (End - Begin) / 2 + Begin;
	int LeftCnt = 0;
	int RightCnt = 0;
	vector<int> Left = Reversion(Array, Begin, Mid, LeftCnt);
	vector<int> Right = Reversion(Array, Mid + 1, End, RightCnt);
	Cnt = LeftCnt + RightCnt;
	int i = 0;
	int j = 0;
	int k = 0;
	while (true) {
		if (i == Left.size() && j == Right.size())
			break;
		if (i == Left.size()) {
			Ret[k] = Right[j];
			j++;
		} else if (j == Right.size()) {
			Ret[k] = Left[i];
			i++;
		} else if (Left[i] <= Right[j]) {
			Ret[k] = Left[i];
			i++;
		} else {
			Ret[k] = Right[j];
			j++;
			Cnt += Left.size() - i;
		}
		k++;
	}
}
Result:
	for (int l = 0; l < Ret.size(); l++)
		cout << Ret[l] << " ";
	cout << "; " << Cnt;
	cout << endl;
	return Ret;
}

int Wrapper(vector<int> &Array)
{
	if (Array.size() == 0)
		return 0;
	int Cnt = 0;
	vector<int> A = Reversion(Array, 0, Array.size() - 1, Cnt);
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
	cout << endl;
	return Cnt;
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		int a = rand() % 100;
		Array[i] = a;
		cout << a << " ";
	}
	cout << endl;
	int Cnt = Wrapper(Array);
	cout << Cnt << endl;
	return 1;
}


