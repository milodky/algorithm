#include <vector>
#include <assert.h>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void output(vector<vector<int> > &Matrix)
{
	int Size = Matrix.size();

	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int GetResults(vector<int> &Array)
{
	int Size = Array.size();
	if (Size == 0 || (Size & 0x01 == 1))
		return 0;

	vector<vector<int> > Matrix(Size, vector<int>(Size, 0));

	for (int i = 1; i < Size - 1; i++) {
		Matrix[i - 1][i] = max(Array[i - 1], Array[i]);
		Matrix[i][i + 1] = max(Array[i], Array[i + 1]);
	}
	for (int i = 0; i < Size; i++) {
		for (int j = i - 1; j >= 0; j--) {
			int k = i - j + 1;
			if (k <= 2 || (k & 0x01))
				continue;
			cout << "haha" << endl;
			assert(i > 2);
			assert(i > j + 2);
			int mymax = Matrix[j][i - 2] + max(Array[i], Array[i - 1]);
			mymax = max(mymax, Matrix[j + 2][i] + max(Array[j], Array[j + 1]));
			mymax = max(mymax, Matrix[j + 1][i - 1] + max(Array[j], Array[i]));
			Matrix[j][i] = mymax;
		}
	}
	return Matrix[0][Size - 1];
}




int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num);
	srand(time(NULL));

	for (int i = 0; i < Num; i++) {
		Array[i] = rand() % 10 + 1;
		cout << Array[i] << " ";
	}
	cout << endl;

	int maximum = GetResults(Array);
	cout << "the maximum is " << maximum << endl;
	return 1;
}

