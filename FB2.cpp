#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

vector<int> Result(string input)
{
	vector<int> ret;
	int Size = input.size();
	if (Size == 0)
		return ret;
	stringstream ss(input);
	string data;
	while (getline(ss, data, ',')) {
		int Pos = data.find('-');
		if (Pos == string::npos) {
			ret.push_back(stoi(data));
			continue;
		}
		int start = stoi(data.substr(0, Pos));
		int end = stoi(data.substr(Pos + 1));
		for (int i = start; i <= end; i++)
			ret.push_back(i);
	}
	return ret;
}

int main()
{
	string a = "1,2,3,5-8,66,56-60";
	vector<int> Ret = Result(a);
	for (int i = 0; i < Ret.size(); i++) {
		cout << Ret[i] << " ";
	}
	cout << endl;
	return 1;
}

