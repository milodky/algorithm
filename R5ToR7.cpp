#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int rand5()
{
	return rand() % 5;
}


int rand7()
{
	int a, b, c;
Generate:
	a = rand5() * 5;
	b = rand5();
	c = a + b;
	if (c >= 21)
		goto Generate;
	return c / 3;
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> holder(7, 0);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		int idx = rand7();
		holder[idx]++;
	}
	for (int i = 0; i < 7; i++)
		cout << i << ": " << holder[i] << endl;
	return 1;
}

