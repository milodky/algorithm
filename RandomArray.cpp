#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>


using namespace std;

void myswap(vector<int> &Array, int i, int j)
{
	int temp = Array[i];
	Array[i] = Array[j];
	Array[j] = temp;
}

void RandomGeneration(vector<int> &Array)
{
	int Num = Array.size();
	int i, j;
	if (Num == 0)
		return;
	srand(time(NULL));
	for (i = 0; i < Num; i++)
		Array[i] = i;

	for (i = 0; i < Num; i++) {
		j = rand() % (i + 1);
		myswap(Array, i, j);
	}	
}

int main(int argn, char **argv)
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num, 0);
	RandomGeneration(Array);
	for (int i = 0; i < Num; i++)
		cout << Array[i] << " ";
	cout << endl;
	return 0;
}

