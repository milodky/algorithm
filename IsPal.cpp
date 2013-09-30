/*
 * Check whether a singly linked list is a pallindrome. 
 * Eg: 1->2->1 Ans: True 
 * 1->3->2->1 Ans: False 
 */

#include <stack>
#include <iostream>
#include <string>
using namespace std;

bool IsPal(string& Str)
{
	stack<char> MyStack;
	int Size = Str.size();
	if (Size == 0)
		return false;
	if (Size == 1)
		return true;
	int i;
	int Mid = Size / 2;
	int IsOddSize = Size & 0x01;
	for (i = 0; i < Mid; i++)
		MyStack.push(Str[i]);
	for (i = Mid + IsOddSize; i < Size; i++) {
		char ChTemp = MyStack.top();
		if (ChTemp != Str[i])
			return false;
		MyStack.pop();
	}
	return true;
}

int main(int argn, char *argv[])
{
	string abc(argv[1]);
	if (IsPal(abc))
		cout << "It is\n";
	else
		cout << "It is not \n";
	return 0;
}
