#include <iostream>
#include <stack>
#include <ctime>
#include <cstdlib>
using namespace std;

void printStack(stack<int> &S)
{
	if (S.size() == 0)
		return;
	int n = S.top();
	S.pop();
	printStack(S);
	cout << n << " ";
}

void SortStack(stack<int> &S)
{
	if (S.size() == 0)
		return;
	
	int top = S.top();
	S.pop();
	if (S.size() == 0) {
		S.push(top);
		return;
	}
	SortStack(S);
	int NewTop = S.top();
	if (NewTop < top) {
		S.push(top);
		return;
	}

	S.pop();
	S.push(top);
	SortStack(S);
	S.push(NewTop);

}


int main()
{
	int Num = 10;
	stack<int> Stack;
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		int n = rand() % (Num + 5);
		Stack.push(n);
		cout << n << " ";
	}
	cout << endl;

	SortStack(Stack);
	printStack(Stack);
	cout << endl;
	return 1;
}




