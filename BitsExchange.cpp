#include <iostream>

using namespace std;

void Base2print(int Num)
{
	int Size = sizeof(int) * 4;
	int print;	
	int k = 1;
	for (int i = 0; i < Size; i++) {
		print = (k & Num) > 0 ? 1 : 0;
		cout << print;
		k = k * 2;
	}
	cout << endl;
}


void Exchange(int &m, int &n, int k, int l, int i, int j)
{
	int diff = k - l + 1;
	if (diff != (i - j + 1))
		return;
	int Temp = 0;
	int Temp1 = 0;
	int s = 1;
	for (int ii = 0; ii < diff; ii++) {
		Temp = Temp | s;
		s = s * 2;
	}
	Temp1 = Temp;
	cout << "Temp1 = " << Temp1 << endl;
	s = 1;
	for (int ii = 0; ii < l; ii++)
		Temp = Temp * 2;
	Temp = Temp & m;
	for (int ii = 0; ii < l; ii++)
		Temp = Temp / 2;
	for (int ii = 0; ii < j; ii++) {
		Temp = Temp * 2;
		Temp1 = Temp1 * 2;
	}
	Base2print(Temp1);
	n = n & (~Temp1);
	n = n | Temp;
}


int main()
{
	int m = 50;
	int n = 27;
	int i = 3, j = 0;
	int k = 7, l = 4;
	cout << "(j, i) = (" << j << ", " << i << ")\n";
	cout << "(l, k) = (" << l << ", " << k << ")\n";
	cout << "m = ";
	Base2print(m);
	cout << "n = ";
	Base2print(n);
	Exchange(m, n, k, l, i, j);
	Base2print(n);

}
