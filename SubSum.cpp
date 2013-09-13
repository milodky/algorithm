#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;


struct Position {
	int start;
	int end;
	friend ostream& operator<<(ostream& os, struct Position& X) {
		os << "(" << X.start << ", "<< X.end << ")";
		return os;
	}
		
};

void SubSum(vector<int> &pArray, vector<struct Position*> &PosVector)
{
	int i, j;
	int sum = 0;
//	struct Position *pNode =NULL;
	int Num = pArray.size();
	for (i = 0; i < Num; i++) {
		sum = 0;
		for (j = i; j < Num; j++) {
			sum +=  pArray[j];
			if (sum == 0) {
				cout << "here \n";
				Position *pNode = new Position;
				cout << "i = " << i << ", j = " << j << endl;
				pNode->start = i;
				pNode->end = j;
				PosVector.push_back(pNode);
			}
		}
	}
}

int main(int argn, char **argv)
{
	int Num = atoi(argv[1]);
	vector<struct Position*> Vector;
	vector<int> Array;
	struct Position *pNode = NULL;
	for (int i = 0; i < Num; i++) {
		Array.push_back(rand() % 20 - 10);
		cout << Array[i] << " ";
	}
	cout << endl;
	SubSum(Array, Vector);
	cout << Vector.size() << endl;
	while (!Vector.empty()) {
		pNode = Vector.back();
//		Vector.pop_back();
		cout << *pNode << endl;
		Vector.pop_back();
		delete pNode;
	} 

	return 0;
}
