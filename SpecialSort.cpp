#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using std::vector;
using std::cout;
using std::endl;
using std::sort;
using namespace std;
struct Node {
	int original;
	int updated;
	bool operator < (const Node &X) const {
		return (updated < X.updated);
	}
};

int GetNum(int Num)
{
	int ret;
	int i;
	for (i = 0; ; i++) {
		Num /= 10;
		if (Num == 0)
			break;
	}
	return (i + 1);
}

void AddingTail(Node &MyNode, int MyNum, int Max)
{
	MyNode.original = MyNum;
	int Times = 1;
	int result = 0;
	int LastDigit = MyNum % 10;
	int HowMany = GetNum(MyNum);
	int Diff = Max - HowMany;
	for (int i = 0; i < Diff; i++) {
		result = LastDigit + result * 10;
		Times *= 10;
	}

	MyNode.updated = MyNum * Times + result;
}

struct LargerThan {
	bool operator() (const Node &X, const Node &Y) {
		return (X.updated > Y.updated);
	}
};
void SpecialSort(vector<int> &Array)
{
	int Size = Array.size();
	if (Size == 0)
		return;
	int Max = Array[0];
	for (int i = 1; i < Size; i++)
		if (Array[i] > Max)
			Max = Array[i];

	int Num = GetNum(Max);
	vector<Node> TempArray(Size);
	for (int i = 0; i < Size; i++)
		AddingTail(TempArray[i], Array[i], Num);
	LargerThan MyLargerThan;
	sort(TempArray.begin(), TempArray.end(), MyLargerThan);
//	sort(TempArray.begin(), TempArray.end());

	for (int i = 0; i < Size; i++)
		cout << TempArray[i].original;
	cout << endl;
}

int main(int argn, char *argv[])
{

	int Num = atoi(argv[1]);
	vector<int> Array(Num);
	for (int i = 0; i < Num; i++) {
		Array[i] = rand() % 100;
		cout << Array[i] << " ";
	}
	cout << endl;
	SpecialSort(Array);
	return 0;

}
