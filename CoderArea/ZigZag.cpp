#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

void Result(vector<vector<int> > &Matrix)
{
	int Size = Matrix.size();
	if (Size == 0)
		return;
	int Cnt = 0;
	int Num = Size * Size;
	int i = 0;
	int j = 0;
	int inc = -1;
	while (Cnt < Num) {
		if (i >= Size) {
			i--;
			j += 2;
			inc = 1;
		}
		if (j >= Size) {
			i += 2;
			j--;
			inc = -1;
		}
		if (j < 0) {
			j++;
			inc = 1;
		}

		if (i < 0) {
			i++;
			inc = -1;
		}
		cout << Matrix[i][j] << " ";
		i -= inc;
		j += inc;
		Cnt++;
	}
	cout << endl;
}


int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<vector<int> > Matrix(Num, vector<int>(Num));
	for (int i = 0; i < Num; i++) {
		for (int j = 0; j < Num; j++) {
			Matrix[i][j] = Num * i + j + 1;
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	Result(Matrix);
	cout << endl;
	return 1;
}

