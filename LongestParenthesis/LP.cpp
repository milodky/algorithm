#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;
int lalala(string s)
{
	// Note: The Solution object is instantiated only once and is reused by each test case.
	int Size = s.size();
	if (Size < 2)
		return 0;
	vector<int> Array(Size, 0);
	for (int i = 1; i < Size; i++) {
		if (s[i] != ')')
			continue;
		int j = i - Array[i - 1] - 1;
		if (j < 0 || s[j] != '(')
			continue;
		Array[i] = Array[i - 1] + 2;

		int k = i - Array[i];
		cout << "i = " << i << ", " << "j = " << j << ", " << "k = " << k << endl;
		if (k >= 0)
			Array[i] += Array[k];
	}

	int Max = 0;
	for (int i = 0; i < Size; i++) {
		cout << Array[i] << " ";
		if (Max < Array[i])
			Max = Array[i];
	}
	cout << endl;
	return Max;
}

int main(int argn, char *argv[])
{
	//string s(argv[1]);
	string s = "()(())";
	
	int ret = lalala(s);
	cout << ret << endl;
	return 1;
} 
