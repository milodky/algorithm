#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<string> restoreIpAddresses(string s) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	vector<string> ret;
	int Size = s.size();
	if (Size < 4 || Size > 12)
		return ret;
	for (int i = 0; i < 3; i++) {
		for (int k = Size - 2; k >= Size - 4; k--) {
			for (int j = i + 1; j < k; j++) {
				if (j - i > 3 || k - j > 3)
					continue;

				string p1 = s.substr(0, i + 1);
				int part1 = stoi(p1);
				if (part1 > 255)
					continue;

				string p2 = s.substr(i + 1, j - i);
				int part2 = stoi(p2);
				if (part2 > 255)
					continue;

				string p3 = s.substr(j + 1, k - j);
				int part3 = stoi(p3);
				if (part3 > 255)
					continue;

				string p4 = s.substr(k + 1);
				int part4 = stoi(p4);
				if (part4 > 255)
					continue;

				string tmp = p1 + "." + p2 + "." + p3 + "." + p4;
				ret.push_back(tmp);
			}
		}
	}
	return ret;
}

int main()
{
	string s = "010010";
	vector<string> p = restoreIpAddresses(s);
	for (int i = 0; i < p.size(); i++)
		cout <<p[i] << endl;
	return 1;
}

