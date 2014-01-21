#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <deque>
#include <algorithm>
using namespace std;

//#define DEBUG
void output(deque<int> &deq, int m)
{
	int n = deq.size();
	for (int i = m; i < n; i++)
		cout << deq[i];
	cout << endl;
}
void get_string (vector<int> &A, int k, deque<int> &str, int begin)
{
	int n = str.size() - begin;
	if (n == 1)
		return;


	int Cnt = A[n - 1];
	int last = A[n - 2];


	int p = ceil(((double) k) / last) + begin;
	int NumToBeSwapped = str[p - 1];
	
#ifdef DEBUG
	cout << "number to be swapped: " << NumToBeSwapped << endl;
#endif
	int reminder = k % last;
	if (reminder == 0)
		reminder = last;



	for (int i = begin + 1; i < str.size(); i++) {
		if (NumToBeSwapped == str[i]) {
			str[i] = str[begin];
			str[begin] = NumToBeSwapped;
			break;
		}
	}
	sort(str.begin() + begin + 1, str.end());
#ifdef DEBUG
	output(str, begin + 1);
#endif

	get_string(A, reminder, str, begin + 1);

//#ifdef DEBUG
//	output(str, begin);
//#endif
}
string getPermutation(int n, int k) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	vector<int> Ann(n, 1);
	deque<int> ret(n);
	string ret_str = "";
	for (int i = 1; i < n; i++)
		Ann[i] = (i + 1) * Ann[i - 1];
	for (int i = 1; i <= n; i++) {
		ret[i - 1] = i;
	}

	get_string(Ann, k, ret, 0);
	for (int i = 0; i < ret.size(); i++)
		ret_str = ret_str + to_string(ret[i]);
	return ret_str;
}

int main()
{
#ifdef DEBUG
	cout << getPermutation(4, 2) << endl;
#else
	for (int i = 1; i <= 24; i++)
		cout << getPermutation(4, i) << endl;
#endif
	return 1;
}

