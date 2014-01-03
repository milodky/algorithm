#ifndef MAXSTACK_H_
#define MAXSTACK_H_
#include <stack>
#include <exception>
using std::stack;
using std::exception;
class MaxStack {
public:
	int max();
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
	MaxStack():mMax(0){}
	~MaxStack(){}
private:
	int mMax;
	stack<int> mStack;
};


#endif
