#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

bool IsTriangle(vector<int> &Array)
{
	int Size = Array.size();
	if (Size < 3)
		return false;
	sort(Array.begin(), Array.end());

	int i = 0;
	int j = 1;
	int k = 2;
	for (int i = 0; i < Size - 2; i++) {
		if (Array[i] + Array[i + 1] < Array[i + 2])
			continue;
		return true;
	}

	return false;
			
}

void output(vector<int> &v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
		cout << v[i] << "\t";
	cout << endl;
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num);

	for (int i = 0; i < Num; i++)
		Array[i] = rand() % 100;

	bool ret = IsTriangle(Array);
	output(Array);
	if (ret)
		cout << "Found!" << endl;
	else
		cout << "Not Found!" << endl;
}

