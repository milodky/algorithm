#include <iostream>
#include <stack>

using namespace std;


bool IsMatched(char *pStr)
{
	int flag = false;
	char *temp = pStr;
	int Num;
	int Cnt = 0;
	stack<int> Stack;
	if (pStr == NULL)
		return false;
	while (*temp != '\0') {
		Cnt++;
		switch (*temp) {
			case '(':
				Num = -3;
				break;
			case '[':
				Num = -2;
				break;
			case '{':
				Num = -1;
				break;
			case '}':
				Num = 1;
				break;
			case ']':
				Num = 2;
				break;
			case ')':
				Num = 3;
				break;
			default:
				flag = true;
				break;
		}
		if (flag)
			return false;
		if (Num > 0) {
			if (Stack.empty())
				return false;
			int Match = Stack.top();
			if (Num + Match != 0)
				return false;
			Stack.pop();
		} else
			Stack.push(Num);
		temp++;
	}
	if (Cnt & 0x01)
		return false;
	return true;
}



int main(int argn, char *argv[])
{
	char *pStr = argv[1];

	if (IsMatched(pStr))
		cout << "Matched!\n";
	else
		cout << "Fuck!\n";
	return 0;
}
