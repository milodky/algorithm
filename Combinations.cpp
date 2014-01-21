#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



void Start(vector<vector<int> > &Ret, int N, int K, int Cnt, vector<int> &holder)
{
	if (Cnt == K) {
		Ret.push_back(holder);
		return;
	}
	for (int i = Cnt + 1; i <= N; i++) {
		holder.push_back(i);
		Start(Ret, N, K, Cnt + 1, holder);
		holder.pop_back();
	}
		
}





vector<vector<int> > Generate(int N, int K)
{
	vector<int> holder;
	vector<vector<int> > Ret;
	Start(Ret, N, K, 0, holder);
	return Ret;
}

void Print(vector<int> &A)
{
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
	cout << endl;
}


int main(int argn, char *argv[])
{
	int N = atoi(argv[1]);
	srand(time(NULL));
	int K = rand() % N + 1;
	cout << "(N, K): (" << N << ", " << K << ")\n";
	vector<vector<int> > Ret = Generate(N, K);
	for (int i = 0; i < Ret.size(); i++)
		Print(Ret[i]);
	return 0;
}
