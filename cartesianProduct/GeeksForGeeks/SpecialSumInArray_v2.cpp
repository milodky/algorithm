#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void Result(vector<int> &Array, int Sum)
{
	int Size = Array.size();
	if (Size == 0)
		return;
	if (Array[0] == Sum) {
		cout << "Done" << endl;
	}
	vector<int> Vec(Array);
	unordered_map<int, int> mytable;
	for (int i = 1; i < Size; i++) {
		Vec[i] = Vec[i - 1] + Array[i];
		int Target = Vec[i] - Sum;
		if (mytable.count(Target)) {
			cout << "From " << mytable[Vec[i]] << " to " << i << endl;
			return;
		}	
		mytable[Vec[i]] = i;
	}
}


int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num);
	srand(time(NULL));
	cout <<"Array:	";
	for (int i = 0; i < Num; i++) {
		int a = rand() % 21;
		Array[i] = a;
		cout << a << "	";
	}
	cout << endl;
	int Sum = rand() % 70;
	cout << "Sum is: " << Sum << endl;

	Result(Array, Sum);
	return 0; 
}
