#include <iostream>
using namespace std;


    int divide(int A[], int begin, int end) {
        if (begin >= end)
            return 0;

        if (begin + 1 == end) {
            return 0;
        }
        int Max = 0;
        int pMax = begin;
        for (int i = begin; i <= end; i++) {
            if (A[i] > Max) {
                Max = A[i];
                pMax = i;
            }
        }
        int ret = 0;
        int pLess = begin;
        int pLessMax = 0;
        int pMore = pMax + 1;
        int pMoreMax = 0;
        for (int i = begin; i < pMax; i++) {
            if (A[i] > pLessMax) {
                pLessMax = A[i];
                pLess = i;
            }
        }
	cout << "1" << endl;
        for (int i = pLess + 1; i < pMax; i++) {
            ret += pLessMax - A[i];
        }
	cout << "2" << endl;
        
        
        ///////////////////////////////////////
        for (int i = pMax + 1; i <= end; i++) {
            if (A[i] > pMoreMax) {
                pMoreMax = A[i];
                pMore = i;
            }
        }
	cout << "3" << endl;
        
        for (int i = pMax + 1; i < pMore; i++) {
            ret += pMoreMax - A[i];
        }
	cout << "4" << endl;
        
	cout << begin << endl << pLess << endl << pMore << endl << end << endl;
	cin >> ret;
        ret += divide(A, begin, pLess);
        ret += divide(A, pMore, end);
        return ret;
    }
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n == 0)
            return 0;

        int ret = divide(A, 0, n - 1);
        return ret;
    }
int main ()
{
	int A[] = {0, 2, 0};
	cout << trap(A, 3) << endl;
	return 0;
}
