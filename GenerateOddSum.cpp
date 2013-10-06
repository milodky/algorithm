/*
 * print all compositions of a number in odd parts, i.e. for n = 8: 
 * 7 + 1 
 * 5 + 3 
 * 5 + 1 + 1 + 1 
 * 3 + 3 + 1 + 1 
 * 3 + 1 + 1 + 1 + 1 + 1 
 * 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1
 */
#include <vector>
#include <iostream>
using namespace std;
vector<int> OddSeq;
vector<int> MyStack;
void GenerateComposition(int Num, int Position) 
{
	if (Num == 0) {
		for (int i = 0; i < MyStack.size(); i++)
			cout << MyStack[i] << " ";
		cout << endl;
		return;
	}

	for (int i = Position; i >= 0; i--) {
		int OddNum = OddSeq[i];
		int y = Num;
		int c = 0;
		while (y >= OddNum) {
			y -= OddNum;
			c++;
			MyStack.push_back(OddNum);
			GenerateComposition(y, i - 1);
		}
		while (c) {
			c--;
			MyStack.pop_back();
		}
	}
}

int main(int argn, char *argv[])
{
	int num = atoi(argv[1]);
	for (int i = 0; i < num; i++)
		if (i & 0x01)
			OddSeq.push_back(i);
	GenerateComposition(num, OddSeq.size() - 1);
	return 0;
}
