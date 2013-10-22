#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;
/*
    int threeSumClosest(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int Size = num.size();
        
        if (Size < 3)
            return 0;
        
        sort(num.begin(), num.end());
        
        int sum = 0x3f3f3f3f;
	cout << Size << endl;        
        for (int i = 0; i < Size - 2; i++) {
            int j = i + 1;
            int k = Size - 1;
            
            while (j < k) {
                int ret = num[i] + num[j] + num[k];
                if (abs(sum - target) >= abs(ret - target)) {
                    sum = ret;
		}
                if (sum < target) {
                    j++;
                } else if (sum > target)
                    k--;
                else
                    return sum;
            }
        }
        
        return sum;
    }
*/

int BinarySearch(vector<int> &num, int start, int end, int target)
{
	int mid = (end - start) / 2 + start;
	int ret;
	if (num[start] >= target)
		return start;

	if (num[end] <= target)
		return end;

	if (num[mid] > target) {
		if (start <= mid - 1)
			ret = BinarySearch(num, start, mid - 1, target);
		else
			ret = start;
	} else if (num[mid] < target) {
		if (mid + 1 <= end)
			ret = BinarySearch(num, mid + 1, end, target);
		else
			ret = end;
	}

	if (ret == start)
		return start;
	if (ret == end)
		return end;

	int a0 = abs(num[ret - 1] - target);
	int a1 = abs(num[ret] - target);
	int a2 = abs(num[ret + 1] - target);

	int ret1 = (a0 > a1) ? ret : (ret - 1);

	if (ret == ret1)
		ret = (a2 > a1) ? ret : (ret + 1);
	else
		ret = (a2 > a0) ? (ret - 1) : (ret + 1);

	return ret; 
}


int threeSumClosest(vector<int> &num, int target)
{
	int Size = num.size();
	sort(num.begin(), num.end());
	int start = 0;
	int end = num.size() - 1;
	int sum = 0x3f3f3f3f;
	stack<int> MyStack;



	int ret;
	int third;
	while (start < end) {
		ret = num[start] + num[end];
		third = BinarySearch(num, start + 1, end - 1, target);
		ret = ret + num[third];
		if (abs(sum - target) > abs(ret - target))
			sum = ret;
		if (ret > target)
			end--;
		else if (ret < target)
			start++;
		else
			return sum;
	}
	return sum;

}


int main() {
//	int a[] = {-5, -5, -4, 0, 0, 3, 3, 4, 5};
	int a[] = {-43,61,-62,24,73,64,-23,94,-65,-27,24,-56,8,54,0,19,-100,-64,-53,6,-22,13,-18,55,-41,37,34,-43,0,-8,-95,76,73,21,-93,16,98,60,70,-32,30,-7,-27,-73,79,-26,41,32,41,-5,82,-14,50,-94,22,62,60,-48,51,12,-34,68,-40,-20,-20,46,46,-79,1,82,-98,41,-79,-43,-76,-25,-94,-16,-25,46,-95,-79,53,-1,-30,43,93,17,72,66,83,-89,-16,42,40,87,-46,40,22,85,-91,46,-77,19,-56,-28,8,47,-20,65,8,60,-49,-86,-74,56,30,79,97,-89,14,-90,66,-12,-57,46,-61,87,72,13,75,75,36,79,-16,84,-49,-86,76,68,-8,-65,-86,-11,55,-69,-59,34,63,59,-11,43,16,7,93,57,-55,2,38,64,3,22,-9,-22,-34,-84,90,-71,-88,64,-19,13,-8,-81,-95,-38,-9,-25,82,57,60,-26,66,21,8,65,-38,-68,-59,24,91};
	vector<int> Array(a, a + sizeof(a) / sizeof(int));

//	cout << threeSumClosest(Array, -2) << endl;
	//int ret = (threeSumClosest(Array, -231, 1) + threeSumClosest(Array, -231, 0)) / 2;
//	cout << ret << endl;
//	cout << threeSumClosest(Array, -2) << endl;
	cout << threeSumClosest(Array, -231) << endl;

	return 1;
}
