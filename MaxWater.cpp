#include <iostream>
#include <vector>

using namespace std;


int min(int a, int b)
    {
        return (a > b) ? b : a;
    }
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    int Ai;
    int Aj;
    
    bool LessThanBoth(int a)
    {
        if (a < Ai && a < Aj)
            return true;
        return false;
    }
    
    bool LargerThanBoth(int a)
    {
        if (a >= Ai && a >= Aj)
            return true;
        return false;
    }
    
    int maxArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int Size = height.size();
        if (Size < 2)
            return 0;
        
        int PosStart = 1;
        int PosEnd = 2;
        Ai = height[0];
        Aj = height[1];
        int volume = min(Ai, Aj) * (PosEnd - PosStart);
        
        for (int i = 3; i < Size + 1; i++) {
            int Current = height[i - 1];
            if (LessThanBoth(Current)) {
                int temp = (Current, Ai) * (i - PosStart);
                if (temp > volume) {
                    Aj = Current;
                    PosEnd = i;
                    volume = min(Ai, Aj) * (PosEnd - PosStart);
                }
                continue;
            }
            
            if (LargerThanBoth(Current)) {
                if (Ai < Aj) {
                    int temp1 = min(Ai, Current) * (i - PosStart);
                    int temp2 = min(Aj, Current) * (i - PosEnd);
                    if (temp1 < temp2) {
                        volume = temp2;
                        Ai = Aj;
                        Aj = Current;
                        PosStart = PosEnd;
                        PosEnd = i;
                    } else {
                        PosEnd = i;
                        Aj = Current;
                        volume = temp1;
                    }
                } else {
                    Aj = Current;
                    PosEnd = i;
                    volume = min(Ai, Aj) * (PosEnd - PosStart);
                }
                
                continue;
            }
            
            /* between the two */
            if (Ai > Aj) {
                Aj = Current;
                PosEnd = i;
                volume = min(Ai, Aj) * (PosEnd - PosStart);
            } else {
                int temp1 = min(Ai, Current) * (i - PosStart);
                int temp2 = min(Aj, Current) * (i - PosEnd);
                if (temp1 < temp2) {
                    volume = temp2;
                    Ai = Aj;
                    Aj = Current;
                    PosStart = PosEnd;
                    PosEnd = i;
                } else {
                    PosEnd = i;
                    Aj = Current;
                    volume = temp1;
                }
            }
        }
        
        return volume;
        
    }

int main()
{
	vector<int> Array(4);
	Array[0] = 1;
	Array[1] = 2;
	Array[2] = 4;
	Array[3] = 3;
	cout << maxArea(Array) << endl;
	return 0;
}
