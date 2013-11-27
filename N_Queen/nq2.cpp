#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

inline void swap(vector<int> &a, int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

bool IsValid(vector<int> &holder, int Size)
{
	int i = Size - 1;
	for (int j = 0; j < i; j++) {
		int temp1 = holder[i] - holder[j];
		int temp2 = i - j;
		if ((temp1 == temp2) || (temp1 + temp2 == 0))
			return false;
	}
	return true;
}
void output(vector<int> &holder)
{
	for (int i = 0; i < holder.size(); i++)
		cout << holder[i] << " ";
	cout << endl;
}

void permutation(vector<int> &holder, int Position, int &Cnt)
{
	if(IsValid(holder, Position) == false)
		return;
	if ((Position == holder.size())) {
		Cnt++;
		return;
	}
	for (int i = Position; i < holder.size(); i++) {
		swap(holder, i, Position);
		permutation(holder, Position + 1, Cnt);
		swap(holder, i, Position);
	}
}



int N_Queen(int n)
{
	if (n <= 0)
		return 0;

	vector<int> holder(n);
	for (int i = 0; i < n; i++)
		holder[i] = i;

	int Cnt = 0;
	permutation(holder, 0, Cnt);
	return Cnt;
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	cout << N_Queen(Num) << endl;
}





