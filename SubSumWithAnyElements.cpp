/*
 * given an array of positive integers A and the numbers
 * N and S. Determine the number subsets of A of size S 
 * which sum up to N. 
 * 
 * e.g. A[] = {1,2,5,3,6} 
 * N = 9, S = 3 
 * then we have 2 subsets of size 3: 1+3+5 and 1+2+6
 */
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

static int Count;

static void SubElementsSum(vector<int> &Array, int Sum, int CurrentSum, int Position, int NumLeft)
{
	if (Array.empty())
		return;

	if (Position == Array.size() || NumLeft < 0)
		return;

	int temp = Array[Position];

	if (temp + CurrentSum == Sum && NumLeft == 0) {
		Count++;
		return;
	}
	SubElementsSum(Array, Sum, CurrentSum, Position + 1, NumLeft);
	SubElementsSum(Array, Sum, CurrentSum + temp, Position + 1, NumLeft - 1);
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		Array[i] = rand() % Num + 1;
		cout << Array[i] << " ";
	}
	cout << endl;
	Count = 0;
	SubElementsSum(Array, 6, 0, 0, 3);
	cout << "Count is " << Count << endl;
	return 0;
}
