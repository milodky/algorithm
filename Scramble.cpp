/*
 * source.cpp
 *
 *  Created on: Oct 23, 2013
 *      Author: Tim
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
bool AreScrambled(vector<vector<int> > &Matrix, string &s1, string &s2,
		int begin, int end) {
	if (end == begin) {
		if (s1[begin] == s2[begin]) {
			Matrix[begin][end] = 1;
			return true;
		} else {
			Matrix[begin][end] = 0;
			return false;
		}
	}

	if (end == begin + 1) {
		if (((s1[begin] == s2[begin]) && (s1[end] == s2[end]))
			|| ((s1[end] == s2[begin]) && (s1[begin] == s2[end]))) {
			Matrix[begin][end] = 1;
			return true;
		} else {
			Matrix[begin][end] = 0;
			return false;
		}
	}

	for (int i = begin; i < end; i++) {
		if (Matrix[begin][i] == 0)
			continue;
		if (Matrix[begin][i] == -1) {
			bool flag = AreScrambled(Matrix, s1, s2, begin, i);
			if (flag == false) {
				Matrix[begin][i] = 0;
				continue;
			}
		}
		Matrix[begin][i] = 1;

		if (Matrix[i + 1][end] == 0)
			continue;
		if (Matrix[i + 1][end] == -1) {
			bool flag = AreScrambled(Matrix, s1, s2, i + 1, end);
			if (flag == false) {
				Matrix[i + 1][end] = 0;
				continue;
			}
		}
		int length1 = i - begin;
		int length2 = end - i - 1;
		Matrix[i + 1][end] = 1;
		Matrix[begin][end] = 1;
		return true;

	}

	return false;
}

bool isScramble(string s1, string s2) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	if (s1.size() != s2.size())
		return false;
	int Size = s1.size();
	if (Size == 0)
		return true;
	vector<vector<int> > Scramble(Size);
	for (int i = 0; i < Size; i++) {
		Scramble[i].reserve(Size);
		for (int j = 0; j < Size; j++)
			Scramble[i][j] = -1;
	}
	bool flag = AreScrambled(Scramble, s1, s2, 0, Size - 1);
	return flag;
}

bool isScramble(string s1, string s2) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	if (s1.size() != s2.size())
		return false;
	int Size = s1.size();
	if (Size == 0)
		return true;
	vector<vector<vector<int> > > scramble(Size);

	for (int i = 0; i < Size; i++) {
		scramble[i].reserve(Size);
		for (int j = 0; j < Size; j++) {
			scramble[i][j].reserve(Size + 1);
			for (int k = 1; k <= Size; k++) {
				scramble[i][j][k] = 0;
			}
			if (s1[i] == s2[j])
				scramble[i][j][1] = 1;
		}
	}
	cout << "hahaha" << endl;
	for (int i = 0; i< Size; i++) {
		for (int j = 0; j < Size; j++) {
			int length = Size - max(i, j);
			for (int k = 2; k <= length; k++) {
				for (int l = 1; l < k; l++) {

					if (scramble[i][j][l] && scramble[i + l][j + l][k - l]) {
						scramble[i][j][k] = 1;
						break;
					}

					if (scramble[i][j + k - l][l] && scramble[i + l][j][k - l]) {
						scramble[i][j][k] = 1;
						break;
					}

					//scramble[i][j][k] = 0;                        


				}
			}
		}
	}


	return scramble[0][0][Size];
}
*/
    bool isScramble(string s1, string s2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s1.size() != s2.size())
            return false;
        int Size = s1.size();
        if (Size == 0)
            return true;
        vector<vector<vector<int> > > scramble(Size);
        
        for (int i = 0; i < Size; i++) {
            scramble[i].reserve(Size);
            for (int j = 0; j < Size; j++) {
                scramble[i][j].reserve(Size + 1);
                for (int k = 1; k <= Size; k++) {
                    scramble[i][j][k] = 0;
                }
                if (s1[i] == s2[j])
                    scramble[i][j][1] = 1;
            }
        }
	for (int m = 0; m < Size; m++) { 
        for (int i = 0; i < Size; i++) {
            for (int j = 0; j < Size; j++) {
                int length = Size - max(i, j);
                for (int k = 2; k <= length; k++) {
                    for (int l = 1; l < k; l++) {
                        
                        if (scramble[i][j][l] && scramble[i + l][j + l][k - l]) {
                            scramble[i][j][k] = 1;
                            break;
                        }
                        
                        if (scramble[i][j + k - l][l] && scramble[i + l][j][k - l]) {
                            scramble[i][j][k] = 1;
                            break;
                        }
                        
                        //scramble[i][j][k] = 0;                        
                            
                        
                    }
                }
            }
        }
	}


        return scramble[0][0][Size];
}
int main()
{
	string a = "aaaaaaaaaabbbbbbbbbbbbbbbaaaaaaaaaaaaaaaa";
	string b = "ccccccccccccccccccccccccccccccccccccccccc";
	if (isScramble(a, b))
		cout << "haha" << endl;
	return 0;
}


