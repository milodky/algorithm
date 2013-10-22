#include <iostream>
#include <string>
#include <vector>
using namespace std;

    int Num;
    
    string Current;
    vector<string> MyString;
    void AddParentheses(int leftResi, int rightResi, int cnt)
    {
        if (leftResi > rightResi)
            return;
        /*
        if (leftResi == 0)
            return;
        if (rightResi == 0)
            return;
        */
        if (cnt == Num) {
		cout << Current << endl;
            MyString.push_back(Current);
            return;
        }
        if (leftResi > 0) {
            AddParentheses(leftResi - 1, rightResi, cnt + 1);
        }
        if (rightResi > 0) {
            AddParentheses(leftResi, rightResi - 1, cnt + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        MyString.clear();
        if (n <= 0)
            return MyString;
        Num = n * 2;
        Current.clear();
        Current.reserve(Num);
        AddParentheses(n, n, 0);
        return MyString;
    }

int main(int argn, char *argv[])
{
	int n = atoi(argv[1]);
	vector<string> my = generateParenthesis(n);
	for (int i = 0; i < my.size(); i++) {
		cout << my[i] << endl;
	}
	return 0;
}
