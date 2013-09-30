#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

void BeepOrNot(vector<int>& Array)
{
	int Size = Array.size();
	if (Size == 0)
		return;
	int result = 0;
	for (int i = 0; i < Size; i++) {
		if ((result & Array[i]) == Array[i])
			cout << Array[i] << ": Not Beep!\n";
		else
			cout << Array[i] << ": Beep!\n";
		result = result ^ Array[i];
	}
		
}

int main(int argn, char **argv)
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		Array[i] = rand() % 10 + 1;
		cout << Array[i] << " ";
	}
	cout << endl;
	BeepOrNot(Array);
	return 0;
}
