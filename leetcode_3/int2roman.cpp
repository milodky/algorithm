#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int length(int num)
{
	int ret = 0;
	while (num) {
		num = num / 10;
		ret++;
	}
	return ret;
}
int power10(int num) 
{
	int ret = 1;
	for (int i = 1; i < num; i++)
		ret *= 10;
	return ret;
}
string roman(int num)
{
	switch (num) {
		case 1:
			return "I";
		case 5:
			return "V";
		case 10:
			return "X";
		case 50:
			return "L";
		case 100:
			return "C";
		case 500:
			return "D";
		case 1000:
			return "M";
		default:
			return "";
	}
}
string intToRoman(int num) {
	if (num == 0)
		return "";
	int len = length(num);
	int base = power10(len);
	int first_num = num / base;
	if (first_num == 4) {
		int val = 5 * base;
		string ret = roman(val);
		int rest = val - num;
		string left = intToRoman(rest);
		return left + ret;

	} else if (first_num == 8) {
		int val = 10 * base;
		string ret = roman(val);
		int rest = val - num;
		string left = intToRoman(rest);
		return left + ret;
	} else if (first_num >= 5) {
		int val = 5 * base;
		string ret = roman(val);
		int rest = num - val;
		string right = intToRoman(rest);
		return ret + right;
	}

	string r = roman(base);
	string ret = "";
	for (int i = 0; i < first_num; i++)
		ret += r;
	int rest = num - first_num * base;
	cout << rest << endl;
	string right = intToRoman(rest);
	return ret + right;

}


int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	string s = intToRoman(Num);
	cout << s << endl;
	return 1;
}

