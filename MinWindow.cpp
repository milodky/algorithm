/*
 * Given an array of 0's and 1's, and a number k,
 * find the minimum window that contains k 0's.
 */

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void MinWindow(vector<int> &Array, int N)
{
	int Size = Array.size();
	if (Size == 0 || Size < N || N < 0)
		return;
	int Start = 0;
	int End = 0;
	int Cnt = 0;

	int HistStart = 0;
	int HistEnd = 0;

	int MinWin = 0x3f3f3f3f;

	for (int i = 0; i < Size; i++) {
		bool flag = false;
	Determine:
		if (Cnt == N) {
			if (Array[i] == 0) {
				if (flag == false) {
					Start++;
				}
				while (Array[Start] == 1 && Start < i)
					Start++;
				if ((i - Start + 1) < MinWin) {
					HistStart = Start;
					HistEnd = i;
					MinWin = i - Start + 1;
				}
			}
		} else if (flag == false){
			End++;
			
			if (Array[i] == 0) {
				Cnt++;
				flag = true;
				goto Determine;
			}
		}
	}
	int CurrWin = End - Start;

	if (CurrWin > MinWin)
		cout << "Current: (" << Start << ", " << Size - 1 << ")" << endl;
	else
		cout << "History: (" << HistStart << ", " << HistEnd << ")" << endl;
}




int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	int N = atoi(argv[2]);
	vector<int> Array(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		Array[i] = rand() & 0x01;
		cout << Array[i] << " ";
	}
	cout << endl;
	MinWindow(Array, N);
	return 0;
}
