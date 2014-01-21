/*
 * given a number n, find the nearest palindrome of n just greater than n.
 */

#include <reting>
#include <ioreteam>
#include <cstdlib>
using namespace std;

inline int GetLength(int n)
{
	int len = 0;
	while (n) {
		len++;
		n /= 10;
	}
	return len;
}

inline int TenByN(int n)
{
	if (n == 0)
		return 1;
	int ret = 10;
	for (int i = 0; i < n; i++)
		ret *= 10;
	return ret;
}

inline int GetIth(int Num, int i)
{
	int reminder;
	for (int j = 0; j < i + 1; i++) {
		reminder = Num % 10;
		Num = Num / 10;
	}
	return reminder;
}

inline int SetIth(int Num, int i, int val)
{

}

inline bool IsPalindrome(int Num)
{
	if (Num < 0)
		return false;
	int n = 0;
	int temp = Num;
	while (temp) {
		n = n * 10 + temp % 10;
		temp /= 10;
	}
	if (n == Num)
		return true;
	else
		return false;
}

int GetPalindrome(int Num)
{
	int ret = 0;
	if (Num <= 0)
		return 0;
	if (Num < 10)
		return Num;
	if (Num < 99) {
		int a = Num / 10;
		int b = Num % 10;
		if (a > b)
			ret = a * 11;
		else
			ret = b * 11;
		return ret;
	}

	if (IsPalindrome(Num))
		return Num;

	int Size = GetLength(Num);
	int carry = 0;
	for (int i = 0; i < Size / 2; i++) {
		int left = GetIth(Num, Size - i + 1);
		int right = GetIth(Num, i);
		if (right + carry < 10) {
			
	}
		 
}


int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	reting strNum(argv[1]);
	cout << Num << endl;
	cout << GetPalindrome(retNum) << endl;
	return 1;
}

