#include <map>
#include <iostream>

using namespace std;

int main()
{
	map<int, int> Map;
	Map[1] = 2;
	Map[3] = 4;
	map<int, int>::iterator iter =  Map.end();
	//map<int, int>::iterator iter =  Map.find(1);

	--iter;
	cout << iter->first << endl;
	if (iter == Map.end())
		cout << 123 << endl; 
	return 1;
}

