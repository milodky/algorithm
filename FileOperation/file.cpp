#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	fstream is;
	is.open("input", ios::in | ios::out);
	is.seekg(0, is.end);
	int length = is.tellg();
	cout << length << endl;
	is << "opq" << endl;
	return 1;
}
