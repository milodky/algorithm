#include <iostream>
#include <vector>
using namespace std;

//    bool NextIsZero(int Current, int &Next, int Size)
//    {
//        bool RetVal = false;
//        if (Current >= Size - 1)
//            return RetVal;
//        if (Array[Current + 1] == 1)
//            RetVal = true;
//        else
//            return RetVal;
//        int i;
//        for (i = Current + 1; i < Size; i++)
//            if (Array[i] != 1)
//                break;
//            Next = i - 1;
//        return RetVal;
//    }
//    int candy(vector<int> &ratings) {
//        // Note: The Solution object is instantiated only once and is reused by each test case.
//        int Size = ratings.size();
//        if (Size == 0)
//            return 0;
//        int Sum = 0;
//        int Current = 0;
//        Array = new int[Size];
//        Array[0] = 1;
//        for (int i = 1; i < Size; i++) {
//            if (ratings[i] > ratings[i - 1])
//                Array[i] = Array[i - 1] + 1;
//            else if (ratings[i] == ratings[i - 1])
//                Array[i] = Array[i - 1];
//            else
//                Array[i] = 1;
//        }
//        
//        
//        for (int i = 0; i < Size; i++) {
//            int NextEnd;
//            if (Array[i] == 1) {
//                if(NextIsZero(i, NextEnd, Size)) {
//                    // do some assignment
//                    for (int j = NextEnd; j >= i && j != 0; j--) {
//                        if (ratings[j] == ratings[j - 1])
//                            Array[j - 1] = Array[j];
//                        else
//                            Array[j - 1] = Array[j] + 1;
//                    }
//                    if (i - 1 > 0)
//                        Array[i - 1] = min(Array[i], Array[i - 2]) + 1;
//                    else
//			if (i - 1 == 0)
//                        Array[i - 1] = Array[i] + 1;
//                    
//                    i = NextEnd + 1;
//                }
//            }
//        }
//        for (int i = 0; i < Size; i++)
//            Sum += Array[i];
//        delete[] Array;
//        return Sum;
//    }
//
//    bool NextIsZero(int Current, int &Next, int Size)
//    {
//        bool RetVal = false;
//        if (Current >= Size - 1)
//            return RetVal;
//        if (Array[Current + 1] == 1)
//            RetVal = true;
//        else
//            return RetVal;
//        int i;
//        for (i = Current + 1; i < Size; i++)
//            if (Array[i] != 1)
//                break;
//            Next = i - 1;
//        return RetVal;
//    }
//    int candy(vector<int> &ratings) {
//        // Note: The Solution object is instantiated only once and is reused by each test case.
//        int Size = ratings.size();
//        if (Size == 0)
//            return 0;
//        int Sum = 0;
//        int Current = 0;
//        Array = new int[Size];
//        Array[0] = 1;
//        for (int i = 1; i < Size; i++) {
//            if (ratings[i] > ratings[i - 1])
//                Array[i] = Array[i - 1] + 1;
//          //  else if (ratings[i] == ratings[i - 1])
//            //   Array[i] = Array[i - 1];
//            else
//                Array[i] = 1;
//        }
//       for (int i = 0; i < Size; i++) { 
//            int NextEnd;
//            if (Array[i] == 1) {
//                if(NextIsZero(i, NextEnd, Size)) {
//                    // do some assignment
//                    for (int j = NextEnd; j >= i && j != 0; j--) {
//                        if (ratings[j] == ratings[j - 1]) {
//                            if (j == 1)
//                                Array[j - 1] = 1;
//                            else if (ratings[j - 1] > ratings[j - 2])
//                                ratings[j - 1] = max(ratings[j], ratings[j - 2]) + 1;
//                            else
//                                Array[j - 1] = 1;
//                        } else {
//
//                            Array[j - 1] = Array[j] + 1;
//                            if (j == i) {
//				cout << "abcd" << endl;
//				cout << j << ", " << i << endl;
//				cout << ratings[i - 1] << " " << ratings[i] << " " << Array[i - 1] << " " << Array[i] << endl;
//                                if ((ratings[i - 1] > ratings[i]) && (Array[i - 1] <= Array[i])) {
//                                    Array[i - 1] = Array[i] + 1;
//					cout << "bcde" << endl;
//				}
//                            }
//                        }
//                    }
//                    if (i - 1 > 0)
//                        Array[i - 1] = max(Array[i], Array[i - 2]) + 1;
//                    else if (i - 1 == 0)
//                        Array[i - 1] = Array[i] + 1;
//                    
//                    i = NextEnd + 1;
//                }
//            }
//        }
//        for (int i = 0; i < Size; i++) {
//		cout << Array[i] << " ";
//            Sum += Array[i];
//	}
//	cout << endl;
//        delete[] Array;
//        return Sum;
//    }
    int *Array;
    bool NextIsZero(int Current, int &Next, int Size)
    {
        bool RetVal = false;
        if (Current >= Size - 1)
            return RetVal;
        if (Array[Current + 1] == 1)
            RetVal = true;
        else
            return RetVal;
        int i;
        for (i = Current + 1; i < Size; i++)
            if (Array[i] != 1)
                break;
            Next = i - 1;
        return RetVal;
    }
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int Size = ratings.size();
        if (Size == 0)
            return 0;
        int Sum = 0;
        Array = new int[Size];
        Array[0] = 1;
        for (int i = 1; i < Size; i++) {
            if (ratings[i] > ratings[i - 1])
                Array[i] = Array[i - 1] + 1;
            else
                Array[i] = 1;
        }
        for (int i = 0; i < Size; i++) {
            if (Array[i] != 1)
                continue;
            int NextEnd;
            
            if(!NextIsZero(i, NextEnd, Size))
                continue;
            // do some assignment
            for (int j = NextEnd - 1; j >= i; j--) {
                if (ratings[j] == ratings[j + 1]) {
                    Array[j] = 1;
                } else {
                    Array[j] = Array[j + 1] + 1;
                }
            }
            if (i - 1 > 0)
                Array[i - 1] = max(Array[i], Array[i - 2]) + 1;
            /*
            else if (i - 1 == 0)
                Array[i - 1] = Array[i] + 1;
            */
            i = NextEnd + 1;
        }
        
        for (int i = 0; i < Size; i++)
	{
        	cout << "(" << ratings[i] << ", " << Array[i] << ")\n";
	   Sum += Array[i];
	}
        delete[] Array;
        return Sum;
    }

int main()
{
	int array[] = {58,21,72,77,48,9,38,71,68,77,82,47,25,94,89,54,26,54,54,99,64,71,76,63,81,82,60,64,29,51,87,87,72,12,16,20,21,54,43,41,83,77,41,61,72,82,15,50,36,69,49,53,92,77,16,73,12,28,37,41,79,25,80,3,37,48,23,10,55,19,51,38,96,92,99,68,75,14,18,63,35,19,68,28,49,36,53,61,64,91,2,43,68,34,46,57,82,22,67,89};
	vector<int> abc(array, array + sizeof(array) / sizeof(int));
	cout << candy(abc) << endl;
	return 0;
}
