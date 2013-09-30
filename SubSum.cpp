#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;


struct Position {
	int start;
	int end;
	friend ostream& operator<<(ostream& os, struct Position& X) {
		os << "(" << X.start << ", "<< X.end << ")";
		return os;
	}
		
};

struct PositionINFO {
	int sum;
	int location;
};

void SubSum(vector<int> &pArray, vector<struct Position*> &PosVector)
{
	int i, j;
	int sum = 0;
	int Num = pArray.size();
	for (i = 0; i < Num; i++) {
		sum = 0;
		for (j = i; j < Num; j++) {
			sum +=  pArray[j];
			if (sum == 0) {
				Position *pNode = new Position;
				pNode->start = i;
				pNode->end = j;
				PosVector.push_back(pNode);
			}
		}
	}
}

class LessThan {
public:
	bool operator()(PositionINFO *X, PositionINFO *Y) {
		return (X->sum < Y->sum);
	}
};


void SubSum1(vector<int> &pArray)
{
	int Num = pArray.size();
	if (Num == 0)
		return;
	vector<PositionINFO*> sum;
	PositionINFO *pInfo = new PositionINFO;
	pInfo->sum = 0;
	pInfo->location = 0;

	LessThan myLessThan;


	sum.push_back(pInfo);
	for (int i = 0; i < Num; i++) {
		pInfo = new PositionINFO;
		pInfo-> sum = sum.back()->sum + pArray[i];
		pInfo->location = i;
		sum.push_back(pInfo);
	}
	sort(sum.begin(), sum.end(), myLessThan);
	bool flag = false;
	for (int i = 1; i < Num + 1; i++) {
		if (sum[i]->sum == sum[i - 1]->sum) {
			if (flag)
				cout << sum[i]->location << " ";
			else {
				cout << sum[i]->location << " " << sum[i - 1]->location << " ";
				flag = true;
			}
		} else if (flag) {
			flag = false;
			cout << endl;
		}
	}
	cout << endl;
	for (int i = 0; i < sum.size(); i++) {
		pInfo = sum.back();
		sum.pop_back();
		delete pInfo;
	}
}

int main(int argn, char **argv)
{
	int Num = atoi(argv[1]);
	vector<struct Position*> Vector;
	vector<int> Array;
	struct Position *pNode = NULL;
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		Array.push_back(rand() % 20 - 10);
		cout << Array[i] << " ";
	}
	cout << endl;
	SubSum(Array, Vector);

	SubSum1(Array);
	
	while (!Vector.empty()) {
		pNode = Vector.back();
//		Vector.pop_back();
		cout << *pNode << endl;
		Vector.pop_back();
		delete pNode;
	} 

	return 0;
}
