#include <iostream>
#include <vector>
using namespace std;

int SumEqual(vector<int> &Array, int Sum)
{
	int Num = Array.size();
	int result = 0;
	if (Num == 0)
		return -1;
	vector<vector<int> > Matrix(Num);
	for (int i = 0; i < Num; i++)
		Matrix[i].reserve(Sum + 1);

	for (int i = 0; i < Num; i++) {
		for (int j = 0; j < Sum + 1; j++) {
			Matrix[i][j] = 0;
			if (i > 0) {
				if (Matrix[i - 1][j])
					Matrix[i][j] = Matrix[i - 1][j];
				if (j > Array[i] && Matrix[i - 1][j - Array[i]])
					Matrix[i][j] += Matrix[i - 1][j - Array[i]];
			}
			if (j == Array[i])
				Matrix[i][j]++;
		}
	}
	return Matrix[Num - 1][Sum];
}

int RecursiveVersion(vector<int> &Array, int Sum, int Count)
{
	int result = 0;
	int Num = Array.size();
	if (Num == 0)
		return -1;
	if (Array[Count] == Sum)
		result++;
	if (Count == Num - 1)
		if (Sum == Array[Count] || Sum + Array[Count] == 0)
			return 1;
		else
			return 0;
	result += RecursiveVersion(Array, Sum, Count + 1);
	result += RecursiveVersion(Array, Sum + Array[Count], Count + 1);
	result += RecursiveVersion(Array, Sum - Array[Count], Count + 1);
	return result;
}


int main()
{
	int a[] = {1, 2, 3, 4};
	vector<int> Array(a, a + sizeof(a) / sizeof(int));
	int Sum = 6;
	cout << SumEqual(Array, Sum) << endl;;
	cout << RecursiveVersion(Array, Sum, 0) << endl;
	return 0;
}
