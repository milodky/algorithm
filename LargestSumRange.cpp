/*
 * print out the start and end index of the 
 * subarray that has the largest sum in an 
 * integer array. 
 * Design test case
 */
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
void LargestSum(vector<int> &Array)
{
	int Size = Array.size();

	if (Size == 0)
		return;
	int HistoryMaxSum = 0;
	int CurrentMaxSum = 0;

	int HistoryStart  = 0;
	int HistoryEnd = 0;

	int CurrentStart = 0;
	int CurrentEnd = 0;

	for (int i = 0; i < Size; i++) {

		if (Array[i] < 0) {
			if (CurrentMaxSum > HistoryMaxSum) {
				HistoryMaxSum = CurrentMaxSum;
				//CurrentMaxSum = 0;
				HistoryStart = CurrentStart;
				HistoryEnd = i - 1;
			}
			if (CurrentMaxSum + Array[i] < 0) {
				CurrentStart = i + 1;
				CurrentEnd = i + 1;
				CurrentMaxSum = 0;
			} else {
				CurrentEnd++;
				CurrentMaxSum += Array[i];
			}
		} else {
			CurrentEnd++;
			CurrentMaxSum += Array[i];
		}

	}

	if (CurrentMaxSum > HistoryMaxSum)
		cout << "(" << CurrentStart << ", " << CurrentEnd << "): " << CurrentMaxSum << "\n";
	else
		cout << "(" << HistoryStart << ", " << HistoryEnd << "): " << HistoryMaxSum << "\n";
}

int main(int argn, char *argv[]) {

	int Num = atoi(argv[1]);
	vector<int> Array(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		Array[i] = rand() % Num - Num / 2;
		cout << Array[i] << " ";
	}
	cout << endl;
	LargestSum(Array);
	return 0;
}
