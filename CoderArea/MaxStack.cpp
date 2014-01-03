#include "MaxStack.h"
int MaxStack::max()
{
	if (size() == 0)
		throw exception();
	return mMax;
}

int MaxStack::top()
{
	if (size() == 0)
		throw exception();
	int ret = mStack.top();
	if (ret < mMax)
		return ret;
	return mMax;
}

void MaxStack::push(int val)
{
	if (size() == 0) {
		mStack.push(val);
		mMax = val;
		return;
	}
	if (val < mMax)
		mStack.push(val);
	else {
		mStack.push(2 * val - mMax);
		mMax = val;
	}
}

void MaxStack::pop()
{
	if (size() == 0)
		throw exception();
	int ret = mStack.top();
	if (mMax <= ret)
		mMax = 2 * mMax - ret;
	mStack.pop();
	if (size() == 0)
		mMax = 0;
}

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main (int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	srand(time(NULL));
	vector<int> Array;
	MaxStack Stack;
	for (int i = 0; i < Num; i++) {
		int a = rand() % 100;
		Stack.push(a);
		Array.push_back(a);
		cout << "Max in Stack is: " << Stack.max() << endl;
		for (int j = 0; j < Array.size(); j++)
			cout << Array[j] << " ";
		cout << endl;
	}
	cout << endl << "Pop:" << endl << endl;
	for (int i = 0; i < Num; i++) {
		cout << "Max in Stack is: " << Stack.max() << endl;
		for (int j = 0; j < Array.size(); j++)
			cout << Array[j] << " ";
		cout << endl;
		Stack.pop();
		Array.pop_back();
	}
	return 1;
}


