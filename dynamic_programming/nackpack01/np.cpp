#include <vector>
#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int GetResults(vector<int> &weights, int Weight)
{
	if (Weight <= 0)
		return 0;
	int Num = weights.size();
	if (Num == 0)
		return 0;

	vector<vector<int> > Matrix(Num + 1, vector<int> (Weight + 1, 0));

	for (int i = 1; i <= Num; i++) {
		for (int j = 0; j <= Weight; j++) {
			if (j < weights[i - 1])
				Matrix[i][j] = Matrix[i - 1][j];
			else
				Matrix[i][j] = max(Matrix[i - 1][j], Matrix[i - 1][j - weights[i - 1]] + weights[i - 1]);
		}
	}

	return Matrix[Num][Weight];
}





int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);

	int Weight = atoi(argv[2]);
	vector<int> weights(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		weights[i] = rand() % 15 + 1;
		cout << weights[i] << " ";
	}
	cout << endl;
	int maximum = GetResults(weights, Weight);
	cout << "Maximum weight is " << maximum << endl;
	return 1;
}

