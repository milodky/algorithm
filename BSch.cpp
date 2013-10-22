#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

    int BinarySearch(vector<int> &Array, int begin, int end, int target)
    {
        if (begin > end)
            return -1;
        while (begin <= end) {
            int mid = (end - begin) / 2 + begin;
            if (Array[mid] == target)
                return mid;
            else if (Array[mid] > target) {
                end = mid - 1;
            } else
                begin = mid + 1;
        }
        return -1;
    }


int main()
{
	int Num = 10;

	vector<int> Array(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		Array[i] = rand() % 10;
	}

	sort(Array.begin(), Array.end());
	for (int i = 0; i < Num; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;

	int ret = -1;

	ret = BinarySearch(Array, 0, 9, 5);

	cout << ret << endl;
}
