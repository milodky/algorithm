#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
static int Den[4];
inline int GetSum(int *pCoins, int Index)
{
	int sum = 0;
	for (int i = Index; i < 4; i++) {
		sum += pCoins[i] * Den[i];
		pCoins[i] = 0;
	}
	return sum;
}
int Coins(int Value, int *pCoins, int Index)
{
	int Num = 0;
	if (Value > 0) {
		if (Value >= Den[Index]) {
			Value -= Den[Index];
			pCoins[Index]++;
			Num += Coins(Value, pCoins, Index);
		} else {
			Index++;
			Num += Coins(Value, pCoins, Index);
		}
	} else {
		Num++;

		for (int j = 0; j < 4; j++)
			cout << pCoins[j] << " ";
		cout << endl;

		for (int i = 2; i >= 0; i--) {
			if (pCoins[i] > 0) {
				int Sum = GetSum(pCoins, i + 1);
				pCoins[i]--;
		//		int Temp[4] = {0};
		//		Temp[i] = pCoins[i];
				Value = Den[i] + Sum;
		//		Value = Den[i];
				Num += Coins(Value, pCoins, i + 1);
			}
		}
	}
	return Num;
}

int main(int argn, char** argv)
{
	int value  = atoi(argv[1]);
	cout << "Sum is " << value << endl;
	cout << endl;
	Den[0] = 25;
	Den[1] = 10;
	Den[2] = 5;
	Den[3] = 1;
	int pCoins[4] = {0};
	cout << Coins(value, pCoins, 0) << endl;
	return 0;
}
