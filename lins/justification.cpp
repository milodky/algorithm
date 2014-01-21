#include <iostream>
#include <vector>
#include <string>

using namespace std;

string get_white_space(int SpaceNum, int wordNum, int Mode)
{
	int AverSpaceNum = SpaceNum / (wordNum - 1);
	if (Mode == 1)
		AverSpaceNum += SpaceNum % (wordNum - 1);
	string ret = "";
	for (int i = 0; i < AverSpaceNum; i++)
		ret = ret + ' ';
	return ret;
}
vector<string> fullJustify(vector<string> &words, int L) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	vector<string> ret;
	int Size = words.size();
	if (Size == 0)
		return ret;
	for (int i = 0; i < Size;) {
		int Room = L;
		vector<string> holder;
		while (i < Size) {

			string &Str = words[i];
			int StrNum = Str.size();
			bool flag = StrNum > Room;
			if (flag) {
				break;
			}
			holder.push_back(Str);
			Room -= (Str.size() + 1);
			i++;
		}
		int row_size = holder.size();
		int length = 0;
		for (int j = 0; j < row_size; j++) {
			length += holder[j].size();
		}
		if (row_size == 1) {
			//do some padding
			string whitespace = "";
			for (int j = 0; j < L - length; j++)
				whitespace += ' ';
			string s = holder[0] + whitespace;
			ret.push_back(s);
			continue;
		}
		string s = holder[0];
		for (int j = 1; j < row_size; j++) {
			s += get_white_space(L - length, row_size, j);
			s += holder[j];
		}
		ret.push_back(s);
	}
	return ret;
}



int main()
{
	vector<string> abc;
	string s = "a";
	abc.push_back(s);
	s = "b";
	abc.push_back(s);
	s = "c";
	abc.push_back(s);
	s = "d";
	abc.push_back(s);
	s = "e";
	abc.push_back(s);
	vector<string> c = fullJustify(abc, 3);
	for (int i = 0; i < c.size(); i++)
		cout << c[i] << endl;
	return 0;
}

