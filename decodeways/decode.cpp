#include <iostream>
#include <vector>
#include <string>
using namespace std;

void FabGenerator(vector<int> &fab)
{
	int n = fab.size();
	fab[0] = 1;
	fab[1] = 1;
	for (int i = 2; i <= n; i++)
		fab[i] = fab[i - 1] + fab[i - 2];
}
void print(vector<int> &vec)
{
	int n = vec.size();
	for (int i = 0; i < n; i++)
		cout << vec[i] << " ";
	cout << endl;
}
int numDecodings(string s) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	//
	int Size = s.size();
	if (Size == 0)
		return 0;
	vector<int> Fab(Size + 1);

	FabGenerator(Fab); 
	cout << "Fab OK." << endl;
	int result = 1;
	vector<int> slash(Size, 0);

	for (int i = 1; i < Size; i++) {
		if (s[i - 1] >= '3' || (s[i - 1] == '2' && s[i] > '6'))
			slash[i - 1] = 1;
	}
	slash[Size - 1] = 1;

	print(slash);

	int Position = -1;
	for (int i = 0; i < Size; i++) {
		if (slash[i] == 0)
			continue;
		result *= Fab[i - Position];
		Position = i;
	}
	return result;
}


int main()
{
	string s = "1234";
	cout << numDecodings(s) << endl;
	return 1;
}

