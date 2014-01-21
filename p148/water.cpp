#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


int trap(int A[], int n) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	if (n == 0)
		return 0;
	//int ret = divide(A, 0, n - 1);
	//return ret;


	vector<int> Holder;
	vector<int> Width;
	int Sum = 0;
	Holder.push_back(A[0]);
	Width.push_back(1);
	for (int i = 1; i < n; i++) {
		int last = Holder.back();
		if (last == A[i]) {
			int width = Width.back();
			Width.pop_back();
			Width.push_back(width + 1);
		} else if (A[i] < last) {
			Holder.push_back(A[i]);
			Width.push_back(1);
		} else{
			// last < A[i]
			int TempHeight = 0;
			int TempWidth = 0;
			int TempSum = 0;
			int width = 1;
			while (Holder.empty() == false) {
				TempHeight = Holder.back();
				if (A[i] <= TempHeight)
					break;
				width++;
				TempWidth = Width.back();
				TempSum += (A[i] - TempHeight) * TempWidth;
				Holder.pop_back();
				Width.pop_back();
			}
			if (Holder.empty() == true) {
				Width.clear();
				Width.push_back(1);
			} else {
				Sum += TempSum;
				Width.push_back(width);
			}
			Holder.push_back(A[i]);

		}
	}
	return Sum;
}
