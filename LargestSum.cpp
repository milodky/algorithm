#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
#define MIN_VALUE -200
#define MAX(a, b) ((a) > (b)) ? (a) : (b)
int LargestSum(const vector<int> &Array)
{
	int result = MIN_VALUE;
	int HistorySum = 0;
	int CurrentSum = 0;
	int Num = Array.size();
	if (Num == 0)
		return result;

	for (int i = 0; i < Num; i++) {
		if (Array[i] > 0)
			CurrentSum += Array[i];
		else if (Array[i] + CurrentSum > 0) {
			HistorySum = MAX(CurrentSum, HistorySum);
			CurrentSum += Array[i];
		} else
			CurrentSum = 0;
	}
	return MAX(HistorySum, CurrentSum);		
	
}

int main(int argn, char** argv)
{
	int Num = atoi(argv[1]);
	srand (time (NULL));

	vector<int> Array;
	for (int i = 0; i < Num; i++) {
		Array.push_back((rand() % 100 - 50));
		cout << Array[i] << " ";
	}
	cout << endl;

	cout << LargestSum(Array) << endl;
	return 0;
}

