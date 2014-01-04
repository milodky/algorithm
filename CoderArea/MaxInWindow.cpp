/*
 * A long array A[] is given to you. There is a
 * sliding window of size w which is moving from
 * the very left of the array to the very right.
 * You can only see the w numbers in the window.
 * Each time the sliding window moves rightwards
 * by one position. Following is an example:
 * 
 * The array is [1 3 -1 -3 5 3 6 7], and w is 3.
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * Input: A long array A[], and a window width w
 * Output: An array B[], B[i] is the maximum value
 * of from A[i] to A[i+w-1]
 * Requirement: Find a good optimal way to get B[i]
 */

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>

using namespace std;
void Result(vector<int> &A, int Window, vector<int> &B)
{
	int Size = A.size();
	if (Size < Window)
		return;
	deque<int> PQ;
	for (int i = 0; i < Window; i++) {
		while (PQ.empty() == false && A[PQ.back()] < A[i])
			PQ.pop_back();
		PQ.push_back(i);
	}
	B.push_back(PQ.front());

	for (int i = Window; i < Size; i++) {
		while (PQ.empty() == false && (PQ.front() + Window <= i))
			PQ.pop_front();
		while (PQ.empty() == false && A[PQ.back()] < A[i])
			PQ.pop_back();
		PQ.push_back(i);
		B.push_back(PQ.front());
	}
	for (int i = 0; i < B.size(); i++)
		B[i] = A[B[i]];
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		Array[i] = rand() % 21 - 10;
		cout << Array[i] << " ";
	}
	cout << endl;
	vector<int> B;
	int K = 3;
	Result(Array, K, B);
	for (int i = 0; i < B.size(); i++)
		cout << B[i] << " ";
	cout << endl;
	return 1;
}
