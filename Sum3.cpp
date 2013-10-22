#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

    int BinarySearch(vector<int> &Array, int begin, int end, int target)
    {
        if (begin > end)
            return -1;
        if (begin == end && target != Array[begin])
            return -1;
        int ret;
        int mid = (end - begin) / 2 + begin;
        
        if (target > Array[mid])
            begin = mid + 1;
        else if (target < Array[mid])
            end = mid - 1;
        else
            return mid;
        ret = BinarySearch(Array, begin, end, target);
        return ret;
    }

    vector<vector<int> > threeSum(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int Size = num.size();
        vector<vector<int> > Array;
        if (Size < 3)
            return Array;

        sort(num.begin(), num.end());
        for (int i = 0; i < Size; i++) {
            for (int j = i + 1; j < Size; j++) {
                int target = 0 - num[i] - num[j];
                int k = BinarySearch(num, j + 1, Size - 1, target);
                if (k == -1)
                    continue;
                vector<int> temp(3);
                
                temp[0] = num[i];
                temp[1] = num[j];
                temp[2] = num[k];
                if (!Array.empty()) {
                    vector<int> &last = Array.back();
                    if (last == temp)
                        continue;
                }
                Array.push_back(temp);

            }
        }
        
        return Array;
        
    }
int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);

	vector<int> Array(Num);
	srand(time(NULL));

	for (int i = 0; i < Num; i++) {
		Array[i] = rand() % 20 - 10;
	}
	sort(Array.begin(), Array.end());

	for (int i = 0; i < Num; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;

	vector<vector<int> > ret;

	ret = threeSum(Array);

	cout << ret.size() << endl;


	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i][0] << ", " << ret[i][1] << ", " << ret[i][2] << endl;
	}
	return 0;
}
