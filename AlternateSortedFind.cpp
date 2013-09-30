/*
 * Given an array which is alternatively sorted. Find an element in it. 
 * e.g. 12,2,16,5,18,32,33,38
 */
#include <vector>
#include <iostream>
using namespace std;
bool AlternateSearch(vector<int> &Array, int Key)
{
	int Size = Array.size();
	bool RetVal = false;
	if (Size == 0)
		return RetVal;
	int start = 0;
	int end = Size - 2;
	if (Size & 0x01)
		end++;

	while (start <= end) {
		int mid = (start + end) / 4 * 2;
		if (Array[mid] == key)
			return true;
		else if (Array[mid] > key)
			start = mid  + 2;
		else
			end = mid - 2;
	}
	if (Size > 1)
		start = 1;
	else
		return RetVal;
	end = (Size & 0x01) ? (Size - 2) : (Size - 1);
	while (start <= end) {
		int mid = (start + end) / 4 * 2;
		if (Array[mid] == key)
			return true;
		else if (Array[mid] > key)
			start = mid  + 2;
		else
			end = mid - 2;
	}
	return RetVal;

}
