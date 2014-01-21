/*
 * given a couple of numbers, you are going to put one operator (+ - * / %)
 * between two numbers as well as the paranthesis, and make the value of the 
 * expression equal to a specific number
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

bool IsValid(vector<double> &Array, int Target)
{
	int Size = Array.size();
	if (Size == 0)
		return false;
	if (Size == 1) {
		if (fabs(Array[0] -  Target) < 0.00001)
			return true;
		else
			return false;
	}

	for (int i = 0; i < Size - 1; i++) {
		int j = i + 1;
		for (int k = 0; k < 4; k++) {
			double val;
			switch(k) {
				case 0:
					val = Array[i] + Array[j];
					break;
				case 1:
					val = Array[i] - Array[j];
					break;
				case 2:
					val = Array[i] * Array[j];
					break;
				case 3:
					if (fabs(Array[j]) < 0.00001)
						continue;
					val = Array[i] / Array[j];
					break;
				default:
					break;
			}

			vector<double> next;
			for (int l = 0; l < Size; l++) {
				if (l == i)
					next.push_back(val);
				else if (l == i + 1) {
				} else
					next.push_back(Array[l]);
			}
			 if (IsValid(next, Target))
				return true;
		}
	}
	return false;
}


int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	int Target = atoi(argv[2]);
	vector<double> Array(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		Array[i] = (double) (rand() % 10);
		cout << Array[i] << " ";
	}
	cout << endl;
	if (IsValid(Array, Target))
		cout << "yes\n";
	else
		cout << "no\n";
	return 1;
}

