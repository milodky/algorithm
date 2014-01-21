#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <vector>
#include <iostream>

using namespace std;


void abc(vector<int> &ret)
{
	int n = ret.size();
	for (int i = 0; i < n; i++) {
		if (ret[i] == 1) {
			int j = i + 1;
			while (true) {
				if (ret[j] == 0) {
					ret[j] = -2;
					break;
				}
				j++;
				if (j == n)
					break;
			}
			continue;
		}
		if (ret[i] == -1) {
			int j = i + 1;
			while (true) {
				if (ret[j] == 0) {
					ret[j] = 2;
					break;
				}
				j++;
				if (j == n)
					break;
			}
			continue;
		}
	}

	for (int i = 0; i < n; i++) {
		if (ret[i] == -2) {
			ret[i] = -1;
			continue;
		}
		if (ret[i] == 2) {
			ret[i] = 1;
			continue;
		}		
	}
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		Array[i] = rand() % 3 - 1;
		cout << Array[i] << " ";
	}
	vector<int> Proto;
	Proto.assign(Array.begin(), Array.end());
	cout << endl;
	abc(Array);
	for (int i = 0; i < Num; i++) {
		cout << Proto[i] << "\t" << Array[i] << endl;
	}
	cout << endl;
	return 1;
}

