#include <iostream>
using namespace std;

bool checkPS(int Num) {
	bool result = false;
	int sum = 0;
	int temp;
	if (Num < 0)
		return result;
	for (int i = 1; i <= Num; i++) {
		sum += i;
		temp = sum + sum - i;
		if (temp == Num) {
			result = true;
			break;
		}
	}
	return result;
}

int main(int argn, char **argv)
{
	int n = atoi(argv[1]);
	if (checkPS(n))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0; 
}
