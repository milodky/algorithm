#include "MinStack.h"
int MinStack::min()
{
	if (size() == 0)
		throw exception();
	return mMin;
}

int MinStack::top()
{
	if (size() == 0)
		throw exception();
	int ret = mStack.top();
	if (mMin < ret)
		return ret;
	return mMin;
}

void MinStack::push(int val)
{
	if (size() == 0) {
		mStack.push(val);
		mMin = val;
		return;
	}
	if (mMin < val)
		mStack.push(val);
	else {
		mStack.push(2 * val - mMin);
		mMin = val;
	}
}

void MinStack::pop()
{
	if (size() == 0)
		throw exception();
	int ret = mStack.top();
	if (ret <= mMin)
		mMin = 2 * mMin - ret;
	mStack.pop();
	if (size() == 0)
		mMin = 0;
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
	MinStack Stack;
	for (int i = 0; i < Num; i++) {
		int a = rand() % 100;
		Stack.push(a);
		Array.push_back(a);
		cout << "Min in Stack is: " << Stack.min() << endl;
		for (int j = 0; j < Array.size(); j++)
			cout << Array[j] << " ";
		cout << endl;
	}
	return 1;
}


