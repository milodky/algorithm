/*
 * No. 48 - Least Number after Deleting Digits
 * Problem: Please get the least number after deleting
 * k digits from the input number. For example, if the
 * input number is 24635, the least number is 23 after
 * deleting 3 digits.
 */

#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int length(int Num)
{
	int ret  = 0;
	while (Num) {
		Num /= 10;
		ret++;
	}
	return ret;
}

int Result(int Num, int K)
{
	if (K == 0)
		return Num;
	int len = length(Num);
	deque<int> ret;
	int x = 0;
	while (Num) {
		int n = Num % 10;
		ret.push_front(n);
		Num = Num / 10;
	}
	ret.push_front(0);
	int Size = ret.size();
	int i = 1;
	for (; i < Size ; i++)
		if (ret[i - 1] <= ret[i])
			continue;
		else
			break;
	ret[i - 1] = -1;
	for (int i = 1; i < ret.size(); i++) {
		if (ret[i] == -1)
			continue;
		x = x * 10 + ret[i];
	}
	x = Result(x, K - 1);
	return x;
}


int main(int argn, char *argv[])
{
	srand(time(NULL));
	int Num = rand() % 100000;
	cout << "Number is: " << Num << endl;
	int len = length(Num);
	cout << "Length is: " << len << endl;
	for (int i = 1; i < len; i++) {
		int ret = Result(Num, i);
		cout << ret << endl;	
	}
	return 1;
}

