#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

    bool IsValid(pair<int, int> &ij, int i, int j)
    {
        if (ij.first == i)
            return false;
        if (ij.second == i)
            return false;
        if (ij.first == j)
            return false;
        if (ij.second == j)
            return false;
        return true;
    }

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
    
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int Size = num.size();
        vector<vector<int> > ret;
        if (Size <= 0)
            return ret;
            
        vector<int> Array(Size * (Size - 1) / 2);
        unordered_map<int, vector<pair<int, int> > > Position;
        unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int> > > > IsInside;
        
        int k = 0;
        sort(num.begin(), num.end());
        for (int i = 0; i < Size; i++) {
            for (int j = i + 1; j < Size; j++) {
                Array[k] = num[i] + num[j];
                pair<int, int> pos(i, j);
                Position[Array[k]].push_back(pos);
                k++;
            }
        }
        
        sort(Array.begin(), Array.end());
        
        for (int i = 0; i < Size; i++) {
            for (int j = i + 1; j < Size; j++) {
                int val = target - num[i] - num[j];
                int pos = BinarySearch(Array, 0, Array.size() - 1, val);
                if (pos == -1)
                    continue;
                    
                // bingo!
                int key = Array[pos];
                //pair<int, int> &ij = Position[key];
                vector<pair<int, int> > &ijset = Position[key];
                bool flag = false;
                vector<int> temp(4);
                for (auto &ij : ijset) {
                    if (!IsValid(ij, i, j))
                        continue;
                    temp[0] = num[ij.first];
                    temp[1] = num[ij.second];
                    temp[2] = num[i];
                    temp[3] = num[j];
                    flag = true;
                    break;
                }
                if (flag == false)
                    continue;
                
                sort(temp.begin(), temp.end());
                
                if (IsInside[temp[0]][temp[1]][temp[2]][temp[3]])
                    continue;
                ret.push_back(temp);
                IsInside[temp[0]][temp[1]][temp[2]][temp[3]] = 1;
            }
        }
        
        return ret;
        
        
    }

int main()
{

	int a[] = {-3, -2, -1, 0, 0, 1, 2, 3};
	vector<int> Array(a, sizeof(a) / sizeof(int));

	vector<vector<int> > ret = foursum(Array, 0); 


	return 0;
}
