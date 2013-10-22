#include <iostream>
#include <string>
#include <vector>
using namespace std;

    string simplifyPath(string path) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (path.size() == 0)
            return path;
        vector<string> PathHolder;
        int start = 0;
        int end = 0;
        while (true) {
            end = path.find("/", start + 1);

            if (start + 1 == end) {
                start = end;
                continue;
            } else {
                if (end == string::npos)
                    end = path.size();
                string temp = path.substr(start + 1, end - start - 1);
                if (temp == "..") {
                    if (PathHolder.size())
                        PathHolder.pop_back();
                } else if (temp == ".") {
                    // do nothing here
                    int adfa = 5;
                }else
                    PathHolder.push_back(temp);
            }
            start = end;
            if (start == path.size() || start == path.size() - 1)
                break;
        }
        
        string output;
        for (int i = 0; i < PathHolder.size(); i++) {
            output = output + "/" + PathHolder[i];
        }
        if (output == "")
            output += "/";
        return output;
    }

int main (int argn, char *argv[])
{
	string p("/abc//");
	cout << simplifyPath(p) << endl;
	string p1("/abc");
	cout << simplifyPath(p1) << endl;
	return 0;

}
