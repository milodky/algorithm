#include <iostream>
#include <string>
using namespace std;
int cnt;
/*
 * given string is of the form "abcd1234" then output should be "a1b2c3d4" with O(n) time
 */

void SpecialPermutation(string& Str, int Begin, int End)
{
	int Size = End - Begin + 1;
	if (Size == 0 || Size == 1 || Size == 2)
		return;
	int Mid = (End - Begin) / 2 + Begin;
	int Half = Size / 2;
	int HalfMid = (Mid + 1 - Begin) / 2 + Begin;

	for (int i = HalfMid; i <= Mid; i++) {
		cnt++;
		int temp = Str[i];
		Str[i] = Str[i - HalfMid + Half + Begin];
		Str[i - HalfMid + Half + Begin] = temp;
	}
	if (Half & 0x01) {
		int temp = Str[Begin + Half - 1];
		Str[Begin + Half - 1] = Str[Begin + Half];
		Str[Begin + Half] = temp;
		SpecialPermutation(Str, Begin, Begin + Half - 2);
		SpecialPermutation(Str, Begin + Half + 1, End);

	} else {
		SpecialPermutation(Str, Begin, Begin + Half - 1);
		SpecialPermutation(Str, Begin + Half, End);
	}
}

int main(int argn, char **argv)
{
	int Num = atoi(argv[1]);
	cnt = 0;
	string Array = "";
//	cout << "Input: ";
	for (int i = 0; i < Num; i++) {
		Array += "a";
	}
	for (int i = 0; i < Num; i++) {
		Array += "b";
	}
	//cout << "Input: ";
	//cin >> Array;
	SpecialPermutation(Array, 0, Array.size() - 1);
	cout << Array << endl;
	cout << cnt << endl;
	return 0;
}
