#ifndef MINSTACK_H_
#define MINSTACK_H_
#include <stack>
#include <exception>
using std::stack;
using std::exception;
class MinStack {
public:
	int min();
	int top();
	void push(int);
	void pop();
	int size()
	{
		return mStack.size();
	}
	int empty()
	{
		return mStack.empty();
	}
	MinStack():mMin(0){}
	~MinStack(){}
private:
	int mMin;
	stack<int> mStack;
};


#endif
