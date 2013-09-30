#include <iostream>

using namespace std;


void ReversedOrder(char *pStr, int Begin, int End)
{
	int Mid = (End - Begin + 1) / 2 + Begin;
	for (int i = Begin; i < Mid; i++) {
		char temp = pStr[i];
		pStr[i] = pStr[End - i + Begin];
		pStr[End - i + Begin] = temp;
	}
}


void RotateString(char *pStr)
{
	char *pTemp = pStr;
	if (pTemp == NULL)
		return;
	if (*pTemp == '\0')
		return;
	int Size = 0;
	while (*pTemp != '\0') {
		Size++;
		pTemp++;
	}
	cout << Size << endl;
	pTemp = pStr;
	ReversedOrder(pStr, 0, Size - 1);

	cout << pStr << endl;

	int Begin = 0;
	int End = 0;
	while (*pTemp != '\0') {
		if (*pTemp == ' ') {
			ReversedOrder(pStr, Begin, End - 1);
			Begin = End + 1;
			cout << Begin << endl;
		}
		pTemp++;
		End++;
	}
	cout << End << endl;
	ReversedOrder(pStr, Begin, End - 1);

}

int main()
{
	char Str[] = "She is so cute";
	cout << Str << endl;
	RotateString(Str);
	cout << Str << endl;
	return 0;
}
