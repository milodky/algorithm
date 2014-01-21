#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int AddTwoNumbers(int a, int b)
{
	if (b == 0)
		return a;
	int XOR = a ^ b;
	int Carry = a & b;
	int Result = AddTwoNumbers(XOR, Carry << 1);
	return Result;
}




int main()
{
	srand(time(NULL));
	int a = rand() % 10000;
	cout << "a = " << a << endl;
	int b = rand() % 10000;
	cout << "b = " << b << endl;
	int Golden = a + b;
	int Result = AddTwoNumbers(a, b);
	cout << "Result is: " << Result << endl;
	cout << "Golden is: " << Golden << endl;
	return 0;
}

