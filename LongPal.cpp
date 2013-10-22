#include <iostream>
#include <string>
using namespace std;
    string longestPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int Size = s.size();
        if (Size == 0)
            return s;
        bool Matrix[1000][1000];
        for (int i = 0; i < Size; i++) {
            for (int j = 0; j < Size; j++)
                Matrix[i][j] = false;
            Matrix[i][i] = true;
        }
        
        for (int i = 1; i < Size; i++) {
            for (int j = i - 1; j >= 0; j--) {
    
                if (s[j] != s[i]) {
                    continue;
                } else if (j < i - 1) {
                    if (Matrix[j + 1][i - 1])
                        Matrix[j][i] = true;
                } else if (j == i - 1)
                    Matrix[j][i] = true;
            }
        }
        int end = -1;
        int start = 0;
        for (int i = 0; i < Size; i++) {
            for (int j = 0; j < Size; j++)
                cout << Matrix[i][j] << " ";
            cout << endl;
        }
        for (int i = 0; i < Size; i++) {
            for (int j = i; j < Size; j++)
                if (Matrix[i][j] && ((end - start) < (j - i))) {
                    end = j;
                    start = i;
                }
                    
        }
	cout << end << endl;
	int length = end - start + 1;
        return s.substr(start, length);
    }
int main()
{
	string s = "abcbe";
	cout << longestPalindrome(s) << endl;
	return 0;
}
