#include <iostream>
using namespace std;

void Roatation (int *pMatrix[], int N)
{
	NumOfLayer = (N + 1) / 2;
	for (int i = 0; i < NumofLayer; i++) {
		for (int j = i; j < N - i; j++) {
			int k = 0;
			int temp = pMatrix[i][N - j];
			int aa;
			int kk;
			int ii = i;
			int jj = j;
			while (k < 3) {
				kk = jj;
				aa = pMatrix[jj][ii];
				jj = N - ii;
				ii = kk;
				pMatrix[jj][ii] = aa;
			}
			pMatrix[j][i] = temp;
		}
	}
}
