#include <vector>
#include <iostream>
#define INT_MAX 0x3f3f3f3f
using namespace std;


//int get_result(vector<int> &height, int low, int high)
//{
//	if (low > high)
//		return 0;
//	if (low == high)
//		return height[low];
//	if (low + 1== high) {
//		int mini = min(height[low], height[high]);
//		int maxi = max(height[low], height[high]);
//		return max(2 * mini, maxi);
//	}
//
//	int mid = (high - low) / 2 + low;
//	int left = get_result(height, low, mid - 1);
//	int right = get_result(height, mid + 1, high);
//
//	int history_area = height[mid];
//	int history_height = height[mid];
//
//	int current_area = height[mid];
//	int current_height = height[mid];
//
//
//
//	int maximum_area = max(history_area, current_area);
//
//	int ret = max(left, right);
//	ret = max(ret, maximum_area);
//
//	return ret;
//
//}
int largestRectangleArea(vector<int> &height) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
//
//	int Size = height.size();
//	if (Size == 0)
//		return 0;
//	int ret;
//	ret = get_result(height, 0, Size - 1);
//	return ret;
	height.push_back(0);
	int Size = height.size();
	vector<int> mystack(Size);
	vector<int> mywidth(Size);
	int top = 0;
	mystack[0] = 0;
	mywidth[0] = 0;
	int ret = 0;
	for (int i = 0; i < Size; i++) {
		if (height[i] >= mystack[top]) {
			top++;
			mystack[top] = height[i];
			mywidth[top] = 1;
		} else {
			int Mini = INT_MAX;
			int Width = 0;
			while (mystack[top] > height[i] && (top >= 0)) {
				Mini = min(Mini, mystack[top]);
				Width += mywidth[top];
				ret = max(ret, Mini * Width);
				top--;
			}

			top++;
			mystack[top] = height[i];
			mywidth[top] = Width + 1;
		}
	}
	cout << "haha" << endl;
	height.pop_back();
	return ret;
}

int main()
{
	int Num = 2;
	vector<int> Array(Num);
	for (int i = 0; i < Num; i++)
		Array[i] = 0;
	Array[0] = 9;
	cout << largestRectangleArea(Array) << endl;
	return 1;
}

