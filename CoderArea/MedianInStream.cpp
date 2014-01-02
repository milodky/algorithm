#include <queue>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class LargerThan {
public:
	bool operator() (int x, int y) {
		if (x < y)
			return false;
		else
			return true;
	}
};


int GetMedian(int Num)
{
	/*
	 * divide the stream into two parts -- smaller one and larger one.
	 * smaller one is held by a max heap, which means we can get its
	 * maximal value quickly while larger one is held by a min heap,
	 * which means we can get its minimal value very quickly.
	 */
	static priority_queue<int> MaxHeap;
	static priority_queue<int, vector<int>, LargerThan> MinHeap;
	int ret = 0;
	if (MinHeap.empty() == true && MaxHeap.empty() == true) {
		MaxHeap.push(Num);
		return Num;
	} else if (MinHeap.empty() == true) {
		int MaxTop = MaxHeap.top();
		if (MaxTop < Num)
			MinHeap.push(Num);
		else {
			MaxHeap.pop();
			MaxHeap.push(Num);
			MinHeap.push(MaxTop);
		}
		return (MaxTop + Num) / 2;
	} else if (MaxHeap.empty() == true) {
		int MinTop = MinHeap.top();
		if (Num < MinTop)
			MaxHeap.push(Num);
		else {
			MinHeap.pop();
			MinHeap.push(Num);
			MaxHeap.push(MinTop);
		}
		return (MinTop + Num) / 2;
	} else {
		int MaxSize = MaxHeap.size();
		int MinSize = MinHeap.size();
		int MaxTop = MaxHeap.top();
		int MinTop = MinHeap.top();
		if (MaxSize < MinSize) {
			if (Num < MinTop)
				MaxHeap.push(Num);
			else {
				MinHeap.pop();
				MaxHeap.push(MinTop);
				MinHeap.push(Num);
			}
			ret = (MinHeap.top() + MaxHeap.top()) / 2;
		} else if (MinSize < MaxSize) {
			if (MaxTop < Num)
				MinHeap.push(Num);
			else {
				MaxHeap.pop();
				MaxHeap.push(Num);
				MinHeap.push(MaxTop);
			}
			ret = (MinHeap.top() + MaxHeap.top()) / 2;
		} else {
			if (Num < MinTop)
				MaxHeap.push(Num);
			else {
				MinHeap.pop();
				MaxHeap.push(MinTop);
				MinHeap.push(Num);
			}
			ret = MaxHeap.top();
		}
		return ret;
	}
}


int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num);
	srand(time(NULL));
	int ret = 0;
	for (int i = 0; i < Num; i++) {
		Array[i] = rand() % 50 + 1;
		cout << Array[i] << " ";
		ret = GetMedian(Array[i]);	
		cout << ret << endl;
	}
	cout << endl;
	sort(Array.begin(), Array.end());
	cout << "Result median is: " << ret << endl;
	cout << "Golden median is: " << Array[Num / 2] << endl;
	return 1;
}


