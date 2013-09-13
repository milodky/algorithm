#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;
#define Max(a, b) ((a) > (b)) ? (a) : (b)
#define Min(a, b) ((b) > (a)) ? (a) : (b)


int MaxDistance(int *pArray, int Num)
{
	int result = -1;
	if (pArray == NULL || Num == 0)
		return result;
	if (Num == 1)
		return result;
	int *MinLeft = new int[Num];
	int *MaxRight = new int[Num];
	int i, j;
	MinLeft[0] = pArray[0];
	MaxRight[Num - 1] = pArray[Num - 1];
	for (j = 1; j < Num; j++)
		MinLeft[j] = Min(pArray[j], MinLeft[j - 1]);
	
	for (j = Num - 2; j >= 0; j--)
		MaxRight[j] = Max(pArray[j], MaxRight[j + 1]);
	i = 0;
	j = 0;
	while (i < Num && j < Num) {
		if (MinLeft[i] < MaxRight[j]) {
			result = Max(result, j - i);
			j++;
		} else {
			i++;
		}
	}
	delete[] MinLeft;
	delete[] MaxRight;
	return result;
}

int main(int argn, char **argv)
{
	int n = atoi(argv[1]);
	int *Array = new int[n];
	for (int i = 0; i < n; i++)
		Array[i] = rand() % 1000;
	for (int i = 0; i < n; i++)
		cout << Array[i] << " ";
	cout << endl;
	cout << MaxDistance(Array, n) << endl;
	delete[] Array;

	return 0;



}

