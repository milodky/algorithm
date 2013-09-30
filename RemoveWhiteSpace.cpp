/*
 * Remove whitespace characters in a 
 * string, in place and with out shifting
 */
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
void RemoveWhiteSpace(char *Str)
{
	int WSCnt = 0;
	int Num = 0;
	//int Size = Str.size();
	int Size = 3;
	if (Size == 0)
		return;
	for (int i = 0; i < Size; i++) {
		if (Str[i] != ' ') {
			Str[Num] = Str[i];
			Num++;
		}
	}
//	Str[Num] = '\0';
}

int main()
{
	string Str;
	char a[20] = {0};
	a[0] = 'a';
	a[1] = ' ';
	a[2] = 'b';
	cout << "Input: ";

	cin >> Str;
	cout << Str;
	//RemoveWhiteSpace(Str);
	RemoveWhiteSpace(a);

	cout << Str << "|" << endl;
	cout << a << "|" << endl;
	return 0;
}
