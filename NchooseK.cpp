#include <iostream>
#include <vector>
using namespace std;

    vector<vector<int> > ret;
    int Pos;
    void Create(int Num, vector<int> &vec, int cnt, int curr) {
        if (cnt == 0) {
            // add vec to the ret vector;
		for (int i = 0; i < vec.size(); i++)
			cout << vec[i] << " ";
		cout << endl;
            ret[Pos] = (vec);
            Pos++;
            return;
        }
        for (int i = curr; i <= Num; i++) {
            vec.push_back(i);
            Create(Num, vec, cnt - 1, i + 1);
            vec.pop_back();
        }
    }
    void combine(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        Pos = 0;
        ret.clear();
        int Total = 1;
        if (n < k || n <=0 || k <=0)
            return;
        
        for (int i = n; i > n - k; i--)
                Total *= i;
        for (int i = k; i > 0; i--)
                Total /= i;
        ret.reserve(Total);

        vector<int> MyVec;
        Create(n, MyVec, k, 1);
	cout << ret.size() << endl;
        //return ret;    
    }
int main(int argn, char *argv[])
{
	
	int k = atoi(argv[2]);
	int n = atoi(argv[1]);
	int Total = 1;
        for (int i = n; i > n - k; i--)
                Total *= i;
        for (int i = k; i > 0; i--)
                Total /= i;
	cout << Total << endl;
	combine(n, k);
	return 0;
}
