#include <iostream>
using namespace std;

    int sqrt(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (x <= 0)
            return 0;
        int i;
        int sum = 0;
        for (i = 1; ; i++) {
            sum += i;
		int abc = (x & 1) + (i & 1);
		
            int right = x / 2 + i / 2 + abc / 2;
            if (sum == right) {
                break;
            } else if (sum > right) {
                i--;
                break;
            }
        }
        return i;
    }

int main (int argn, char *argv[])
{
//	int x = atoi(argv[1]);
	int x = 1;
	cout << sqrt(x) << endl;

	return 0;
}
