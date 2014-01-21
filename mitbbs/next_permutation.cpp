#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void output(vector<int> &v)
{
	int Size = v.size();
	for (int i = 0; i < Size; i++)
		cout << v[i];
	cout << endl;
}
void next_permutation(vector<int> &v)
{
	// todo
}
int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> v(Num);
	for (int i = 0; i < Num; i++)
		v[i] = rand() % 10;
	output(v);
	next_permutation(v);
	output(v);
	return 1;
}

